#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};

void solve() {
  int n, m, a, b; cin >> n >> m >> a >> b;
  int d = abs(a - b) - 1, t = a < b ? b - 1 : n - b;
  vector<int> s(m); REP(i, m) cin >> s[i];
  sort(ALL(s));
  int lb = 0, ub = min(d, m) + 1;
  while (ub - lb > 1) {
    int mid = (lb + ub) >> 1;
    bool ok = true;
    for (int i = mid - 1, fall = 1; i >= 0; --i, ++fall) ok &= fall + s[i] <= t;
    (ok ? lb : ub) = mid;
  }
  cout << lb << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}