#include <bits/stdc++.h>
 
using namespace std;
 
struct Fenwick {
  vector<long long> sum;
  Fenwick(int _n) : sum(_n + 4, 0) {
  }
  
  long long get(int x) {
    long long r = 0;
    for (++x; x; x -= x&-x)
      r += sum[x];
    return r;
  }
 
  void upd(int x, long long v) {
    for (++x; x < (int)sum.size(); x += x&-x)
      sum[x] += v;
  }
};
 
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n * m);
  for (int i = 0; i < n * m; ++i) {
    cin >> a[i];
  }
  int tot = n * m;
  vector<int> id(tot);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int l, int r) {
    if (a[l] == a[r]) {
      return l > r;
    } else {
      return a[l] < a[r];
    }
  });
  Fenwick fen(tot);
  long long ans = 0;
  for (int i = 0; i < tot; ++i) {
    ans += fen.get(id[i]);
    fen.upd(id[i], +1);
  }
  cout << ans << '\n';
}
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    solve();
  }
  return 0;
}