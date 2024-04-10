#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

const int inf = 1e+9;

vector<pair<int, int>> v;

vector<int> all;

int get(int x) {
  return lower_bound(all.begin(), all.end(), x) - all.begin();
}

int mem[307][307];

int inter(int l1, int r1, int l2, int r2) {
  if (l1 > r1) swap(l1, r1);
  if (l2 > r2) swap(l2, r2);

  return max(0, min(r1, r2) - max(l1, l2));
}

int solve(int l, int r) {
  if (l > r) return 0;

  if (mem[l][r] != -1)
    return mem[l][r];

  vector<pair<int, int>> cur;
  int ml = 0;
  for (int i = 0; i < v.size(); ++i) {
    if (all[l] < v[i].first && v[i].first < all[r]) {
      cur.push_back(v[i]);
      ml = max(ml, v[i].second);
    }
  }

  int ans = 0;

  for (int i = 0; i < cur.size(); ++i) {
    if (cur[i].second == ml) {
      int L = cur[i].first, R = L + ml;
      for (int it = 0; it < 2; ++it) {
        ans = max(ans, solve(l, get(L)) + solve(get(R), r) + (R - L) - inter(L, R, -inf, all[l]) - inter(L, R, all[r], inf));

        vector<pair<int, int>> l1, l2;
        for (int j = 0; j < cur.size(); ++j) {
          if (L <= cur[j].first && cur[j].first <= R && i != j) {
            l1.push_back({cur[j].first - cur[j].second, j});
            l2.push_back({cur[j].first + cur[j].second, j});
          }
        }
        l1.push_back({L, -1});
        l2.push_back({R, -1});
        sort(l1.begin(), l1.end());
        sort(l2.rbegin(), l2.rend());

        for (int t1 = 0; t1 < 2 && t1 < l1.size(); ++t1) {
          for (int t2 = 0; t2 < 2 && t2 < l2.size(); ++t2) {
            if (l1[t1].second == l2[t2].second && l1[t1].second != -1) continue;
            int nl = min(L, l1[t1].first), nr = max(R, l2[t2].first);
            vector<bool> was(cur.size(), false);
            if (l1[t1].second != -1)
              was[l1[t1].second] = true;
            if (l2[t2].second != -1)
              was[l2[t2].second] = true;
            was[i] = true;
            while (true) {
              bool upd = false;
              for (int j = 0; j < cur.size(); ++j) {
                if (nl <= cur[j].first && cur[j].first <= nr && !was[j]) {
                  if (cur[j].first - cur[j].second < nl && cur[j].first + cur[j].second > nr)
                    continue;
                  
                  nl = min(nl, cur[j].first - cur[j].second);
                  nr = max(nr, cur[j].first + cur[j].second);

                  was[j] = true;
                  upd = true;
                }
              }

              if (!upd) break;
            }

            // cout << "!! " << nl << "  " << nr << endl; 
            ans = max(ans, solve(l, get(nl)) + solve(get(nr), r) + (nr - nl) - inter(nl, nr, -inf, all[l]) - inter(nl, nr, all[r], inf));
          }
        }
        L -= ml; R -= ml;
      }

      break;
    }
  }

  // cout << all[l] << " " << all[r] << "  " << ans << endl;

  return mem[l][r] = ans;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a, l;
    cin >> a >> l;
    v.push_back({a, l});
    
    all.push_back(a - l);
    all.push_back(a);
    all.push_back(a + l);
  }

  all.push_back(-inf);
  all.push_back(inf);
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());

  memset(mem, -1, sizeof(mem));
  cout << solve(0, all.size() - 1) << endl;

  return 0;
}