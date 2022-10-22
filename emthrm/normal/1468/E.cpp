#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;

constexpr int N = 4;
void solve() {
  vector<int> a(N); REP(i, N) cin >> a[i];
  sort(ALL(a));
  cout << min(a[0], a[1]) * min(a[2], a[3]) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}