#include <bits/stdc++.h>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main() {
  // freopen("input.txt", "r", stdin);

  int n, k, m, t; cin >> n >> k >> m >> t;
  while (t--) {
    int query, i; cin >> query >> i;
    if (query == 0) {
      if (k <= i) {
        n = i;
      } else {
        k -= i;
        n -= i;
      }
    } else {
      if (i <= k) ++k;
      ++n;
    }
    cout << n << ' ' << k << '\n';
  }
  return 0;
}