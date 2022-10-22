#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pt = complex<ld>;

constexpr char nl = '\n';
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while(T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, int> cnt;
    for(int i=0; i<n; i++) {
      cin >> a[i];
      cnt[a[i]] += 1;
    }

    map<int, int> badcnt;
    unordered_map<int, unordered_set<int>> bad;
    for(int i=0; i<m; i++) {
      int x, y;
      cin >> x >> y;
      badcnt[x] += 1;
      badcnt[y] += 1;
      bad[min(x, y)].insert(max(x, y)); // x < y
    }

    vector<vector<int>> val(n + 1);
    for(auto [v, c] : cnt) {
      val[c].push_back(v);
    }

    vector<int> pf;
    for(int i=0; i<=n; i++) {
      if(!empty(val[i])) {
        sort(begin(val[i]), end(val[i]), greater<>());
        pf.push_back(i);
      }
    }

    ll ans = 0;
    for(auto [v, c] : cnt) {
      for(int ci : pf) {
        for(int vi : val[ci]) {
          if(v == vi) continue;
          if(auto it = bad.find(min(v, vi));
              it != bad.end() && it->second.count(max(v, vi))) {
            continue;
          }
          ans = max(ans, (ll)(v + vi) * (c + ci));
          break;
        }
      }
    }
    cout << ans << nl;
  }

  return 0;
}