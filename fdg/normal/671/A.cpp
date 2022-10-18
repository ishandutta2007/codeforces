#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <cmath>

using namespace std;

int ax, ay, bx, by, tx, ty;
int n, x[100005], y[100005];

double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool cmpA(int i, int j) {
  return dist(ax, ay, x[i], y[i]) - dist(tx, ty, x[i], y[i]) < dist(ax, ay, x[j], y[j]) - dist(tx, ty, x[j], y[j]);
}

bool cmpB(int i, int j) {
  return dist(bx, by, x[i], y[i]) - dist(tx, ty, x[i], y[i]) < dist(bx, by, x[j], y[j]) - dist(tx, ty, x[j], y[j]);
}

int main() {
  scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &tx, &ty);
  scanf("%d", &n);
  vector<int> p1, p2;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    p1.push_back(i);
    p2.push_back(i);
  }
  sort(p1.begin(), p1.end(), cmpA);
  sort(p2.begin(), p2.end(), cmpB);
  double ans = 1e+50;
  for (int i = 0; i < 4 && i < n; ++i) {
    for (int j = 0; j < 4 && j < n; ++j) {
      if (p1[i] == p2[j]) continue;

      double cur = 0;
      for (int t = 0; t < n; ++t) {
        cur += dist(x[t], y[t], tx, ty);

        if (t == p1[i]) cur += dist(ax, ay, x[t], y[t]);
        else if (t == p2[j]) cur += dist(bx, by, x[t], y[t]);
        else cur += dist(tx, ty, x[t], y[t]);
      }
      ans = min(ans, cur);
    }
  }
  for (int i = 0; i < 4 && i < n; ++i) {
    double cur = 0;
    for (int t = 0; t < n; ++t) {
      cur += dist(x[t], y[t], tx, ty);

      if (t == p1[i]) cur += dist(ax, ay, x[t], y[t]);
      else cur += dist(tx, ty, x[t], y[t]);
    }
    ans = min(ans, cur);
  }
  for (int i = 0; i < 4 && i < n; ++i) {
    double cur = 0;
    for (int t = 0; t < n; ++t) {
      cur += dist(x[t], y[t], tx, ty);

      if (t == p2[i]) cur += dist(bx, by, x[t], y[t]);
      else cur += dist(tx, ty, x[t], y[t]);
    }
    ans = min(ans, cur);
  }
  printf("%.12lf\n", ans);
  return 0;
}