#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int val[3][27];
 
map<pair<int, int>, pair<int, int>> f;

int it1, it2;
int m1, m2, ss = -1e+9;

void restore() {
  string cand[3] = {"MW", "LW", "LM"};
  vector<string> ans;
  int mask = m2;
  for (int i = 0; i < it2; ++i) {
    ans.push_back(cand[mask % 3]);
    mask /= 3;
  }
  mask = m1;
  for (int i = 0; i < it1; ++i) {
    ans.push_back(cand[mask % 3]);
    mask /= 3;
  }
  reverse(ans.begin(), ans.end());
  for (string s : ans)
    cout << s << endl;
  exit(0);
}



void go(int l, int r, int mask, int a, int b, int c, bool check) {
  if (l > r) {
    if (!check) {
      if (!f.count({a - b, a - c}) || f[{a - b, a - c}] < make_pair(a, mask))
        f[{a - b, a - c}] = {a, mask};
      // cout << s[0] - s[1] << "  " << s[0] - s[2] << endl;
    } else {
      pair<int, int> p = {b - a, c - a};
      auto it = f.find(p);
      if (it != f.end()) {
        // cout << f[p] << " " << mask << endl;
        if (a + it->second.first > ss) {
          ss = a + it->second.first;
          m1 = it->second.second; m2 = mask;
        }
      }
    }
    return;
  } 
  for (int i = 0; i < 3; ++i) {
    go(l + 1, r, mask * 3 + i, a + val[0][l] * (i != 0), b + val[1][l] * (i != 1), c + val[2][l] * (i != 2), check);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &val[0][i], &val[1][i], &val[2][i]);
  }
  int m = n / 2;
  it1 = m + 1; it2 = n - it1;
  go(0, m, 0, 0, 0, 0, false);
  go(m + 1, n - 1, 0, 0, 0, 0, true);
  if (ss > -9e+8) restore();
  puts("Impossible");

  // freopen("input.txt", "w", stdout);
  // cout << 4000 << endl;
  // for (int i = 0; i < 3999; ++i)
  //   cout << 1000000 << " " << 1000000 << " " << 1 << endl;
  // cout << 1 << " " << 1 << " " << 1 << endl;
  // cout << 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 << endl;
  return 0;
}