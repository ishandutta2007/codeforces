#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;

constexpr int N = 3, M = 5;
void solve() {
  vector<ll> c(N), a(M);
  REP(i, N) cin >> c[i];
  REP(i, M) cin >> a[i];
  REP(i, N) {
    c[i] -= a[i];
    if (c[i] < 0) {
      cout << "NO\n";
      return;
    }
  }
  ll x = min(c[0], a[3]), y = min(c[1], a[4]);
  a[3] -= x;
  a[4] -= y;
  cout << (a[3] + a[4] <= c[2] ? "YES\n" : "NO\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}