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

void solve() {
  int X[4] = {0}, Y[4] = {0};
  for (int i = 0; i < 4; ++i)
    cin >> X[i] >> Y[i];
  set<int> d;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < i; ++j) {
      d.insert(abs(X[i] - X[j]));
      d.insert(abs(Y[i] - Y[j]));
    }
  }

  int bestD = 1e+9;
  vector<int> ansX, ansY;

  for (int curD : d) {
    set<int> x, y;
    for (int i = 0; i < 4; ++i) {
      x.insert(X[i] - curD);
      x.insert(X[i]);
      x.insert(X[i] + curD);
      y.insert(Y[i] - curD);
      y.insert(Y[i]);
      y.insert(Y[i] + curD);
    }

    vector<int> p = {0, 1, 2, 3};
    do {
      int minX = min(min(X[p[0]], X[p[1]] - curD), min(X[p[2]], X[p[3]] - curD));
      int maxX = max(max(X[p[0]], X[p[1]] - curD), max(X[p[2]], X[p[3]] - curD));
      x.insert((maxX + minX) / 2);
      int minY = min(min(Y[p[0]], Y[p[1]] - curD), min(Y[p[2]], Y[p[3]] - curD));
      int maxY = max(max(Y[p[0]], Y[p[1]] - curD), max(Y[p[2]], Y[p[3]] - curD));
      y.insert((maxY + minY) / 2);
    } while (next_permutation(p.begin(), p.end()));

    for (int xl : x) {
      for (int yl : y) {
        // cout << curD << " " << xl << "  " << yl << endl;
        vector<int> p = {0, 1, 2, 3};
        vector<int> rx = {xl, xl, xl + curD, xl + curD};
        vector<int> ry = {yl, yl + curD, yl, yl + curD};
        do {
          bool ok = true;
          int ansD = 0;
          for (int t = 0; t < 4; ++t) {
            if (rx[p[t]] == X[t]) ansD = max(ansD, abs(ry[p[t]] - Y[t]));
            else if (ry[p[t]] == Y[t]) ansD = max(ansD, abs(rx[p[t]] - X[t]));
            else ok = false;
          }
          if (ok && ansD < bestD) {
            bestD = ansD;
            ansX = rx; ansY = ry;
            for (int t = 0; t < 4; ++t) {
              ansX[t] = rx[p[t]];
              ansY[t] = ry[p[t]];
            }
          }
        } while (next_permutation(p.begin(), p.end()));
      }
    }
  }
  if (ansX.size() > 0) {
    printf("%d\n", bestD);
    for (int t = 0; t < 4; ++t) {
      printf("%d %d\n", ansX[t], ansY[t]);
    }
  } else {
    puts("-1");
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}