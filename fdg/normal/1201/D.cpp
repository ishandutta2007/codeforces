#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> all[200002];
vector<int> cols;

struct Pos {
  int r, c;
  long long dist;
};

int findSm(int c) {
  int pos = upper_bound(cols.begin(), cols.end(), c) - cols.begin() - 1;
  if (pos >= 0 && pos < cols.size()) return cols[pos];
  return -1;
}

int findGr(int c) {
  int pos = lower_bound(cols.begin(), cols.end(), c) - cols.begin();
  if (pos >= 0 && pos < cols.size()) return cols[pos];
  return -1;
}

int main() {
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    all[x].push_back(y);
  }
  all[1].push_back(1);

  cols.resize(q);
  for (int i = 0; i < q; ++i) {
    cin >> cols[i];
  }
  sort(cols.begin(), cols.end());
  
  for (int r = 1; r <= n; ++r) {
    sort(all[r].begin(), all[r].end());
  }

  vector<Pos> v;
  // v.push_back(Pos{1, all[1][0], all[1].back()});
  v.push_back(Pos{1, all[1].back(), all[1].back() - all[1][0]});

  for (int r = 2; r <= n; ++r) {
    if (all[r].size() == 0) continue;

    vector<Pos> nv;
    // Left.
    {
      long long minDist = 1e+18;
      for (Pos p : v) {
        {
          long long curDist = p.dist;
          int toLeft = findSm(p.c);
          // cout << "L: " << toLeft << endl;
          if (toLeft != -1) {
            curDist += abs(p.c - toLeft);
            curDist += abs(r - p.r);
            curDist += abs(toLeft - all[r].back()) + abs(all[r][0] - all[r].back());
            minDist = min(minDist, curDist);
          }
        }
        {
          long long curDist = p.dist;
          int toRight = findGr(p.c);
          if (toRight != -1) {
            curDist += abs(p.c - toRight);
            curDist += abs(r - p.r);
            curDist += abs(toRight - all[r].back()) + abs(all[r][0] - all[r].back());
            minDist = min(minDist, curDist);
          }
        }
      }
      nv.push_back(Pos{r, all[r][0], minDist});
      // cout << "Left: " << r << "  " << all[r][0] << " " << minDist << endl;
    }
    // Right.
    {
      long long minDist = 1e+18;
      for (Pos p : v) {
        {
          long long curDist = p.dist;
          int toLeft = findSm(p.c);
          if (toLeft != -1) {
            curDist += abs(p.c - toLeft);
            curDist += abs(r - p.r);
            curDist += abs(toLeft - all[r][0]) + abs(all[r][0] - all[r].back());
            minDist = min(minDist, curDist);
          }
        }
        {
          long long curDist = p.dist;
          int toRight = findGr(p.c);
          if (toRight != -1) {
            curDist += abs(p.c - toRight);
            curDist += abs(r - p.r);
            curDist += abs(toRight - all[r][0]) + abs(all[r][0] - all[r].back());
            minDist = min(minDist, curDist);
          }
        }
      }
      nv.push_back(Pos{r, all[r].back(), minDist});
      // cout << "Right: " << r << "  " << all[r].back() << " " << minDist << endl;
    }

    v = nv;
  }

  long long ans = 1e+18;
  for (Pos p : v) {
    ans = min(ans, p.dist);
  }
  cout << ans << endl;

  return 0;
}