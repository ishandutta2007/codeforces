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

  int n;
  cin >> n;
  constexpr int M = 2e5;
  vector<vector<int>> ks(M+1);
  for(int i=0; i<n; i++) {
    int m, k;
    cin >> m >> k;
    ks[m].push_back(k);
  }

  pair<ld, vector<int>> best(0, {});

  const int Tmax = min(20, n);
  for(int T=1; T<=Tmax; T++) {
    vector<pair<int, int>> a;
    for(int i=0; i<=M; i++) {
      int sum = 0;
      for(int v : ks[i]) {
        sum += min(v, T);
      }
      a.emplace_back(sum, i);
    }
    sort(begin(a), end(a), greater<>());

    int res = 0;
    vector<int> out;
    for(int i=0; i<T; i++) {
      res += a[i].first;
      out.push_back(a[i].second);
    }
    best = max(best, pair((ld)res/T, out));
  }

  cout << best.second.size() << nl;
  for(int it : best.second) {
    cout << it << " ";
  }
  cout << nl;

  return 0;
}