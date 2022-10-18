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

vector<pair<int, int> > v;

double dist(int i, int j) {
  return sqrt(0.0 + (v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second));
}

vector<int> cur, best;
double bdist = -1;

bool used[10000];
double D[102][102];

void go(int left) {
  if (left == 0) {
    double val = 0;
    for (int i = 1; i < cur.size(); ++i)
      val += D[cur[i - 1]][cur[i]];
    if (val > bdist) {
      bdist = val;
      best = cur;
    }
    return;
  }
  for (int i = 0; i < v.size(); ++i) {
    if (used[i]) continue;
    used[i] = true;
    cur.push_back(i);
    go(left - 1);
    cur.pop_back();
    used[i] = false;
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int dx = 0; dx < 4; ++dx)
    for (int dy = 0; dy < 4; ++dy) {
      int x = dx, y = dy;
      if (x >= 0 && x <= n && y >= 0 && y <= m)
        v.push_back(make_pair(x, y));
      x = n - dx, y = m - dy;
      if (x >= 0 && x <= n && y >= 0 && y <= m)
        v.push_back(make_pair(x, y));
    }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  for (int i = 0; i < v.size(); ++i)
    for (int j = 0; j < v.size(); ++j)
      D[i][j] = dist(i, j);
  go(4);
  for (int i = 0; i < best.size(); ++i) {
    cout << v[best[i]].first << " " << v[best[i]].second << endl;
  }
  return 0;
}