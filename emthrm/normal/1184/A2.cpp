#include <bits/stdc++.h>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main() {
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<int> yakusu;
  for (long long i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      yakusu.emplace_back(i);
      if (i * i != n) yakusu.emplace_back(n / i);
    }
  }
  sort(ALL(yakusu));
  yakusu.pop_back();
  string y; cin >> y;
  if (count(ALL(y), '1') == 0) {
    cout << n << '\n';
    return 0;
  }
  map<int, int> mp;
  for (int e : yakusu) {
    bool ok = true;
    vector<bool> visited(n, false);
    REP(i, n) if (!visited[i]) {
      int cnt = 0, pos = i;
      while (!visited[pos]) {
        cnt += y[pos] - '0';
        visited[pos] = true;
        (pos += e) %= n;
      }
      if (cnt & 1) ok = false;
    }
    mp[e] = (ok ? 1 : 0);
  }
  int ans = 0;
  FOR(i, 1, n) ans += mp[__gcd(n, i)];
  cout << ans << '\n';
  return 0;

  // vector<string> x(n, "-");
  // bitset<11> yy(y);
  // REP(i, 1 << n) REP(j, n) if (x[j] == "-") {
  //   bitset<11> moto(i), shift(i);
  //   REP(k, j) {
  //     if (shift[0]) shift.set(n);
  //     shift >>= 1;
  //   }
  //   if ((moto ^ shift) == yy) {
  //     x[j] = "";
  //     REP(k, n) x[j] += (moto[k] ? '1' : '0');
  //     reverse(ALL(x[j]));
  //   }
  // }
  // REP(i, n) cout << x[i] << '\n';
}