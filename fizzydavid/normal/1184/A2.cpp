#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector <int> cnt(n + 1);
  for (int i = 1; i <= n; i++) {
    cnt[__gcd(i, n)]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i]) {
      bool bad = false;
      vector <bool> u(n);
      for (int j = 0; j < n; j++) {
        if (!u[j]) {
          int xr = 0;
          int x= j;
          while (!u[x]) {
            xr ^= (s[x] - '0');
            u[x] = true;
            x = (x + i) % n;
          }
          if (xr) {
            bad = true;
          }
        }
      }
      if (!bad) ans += cnt[i];
    }
  }
  cout << ans << '\n';
}