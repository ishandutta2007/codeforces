#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#define debug(x) cerr << #x << ": <" << (x) << ">\n"
#else
#define debug(x)
#endif
}

#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second
#define mod       1073741824

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  int a, b, c; cin >> a >> b >> c;
  vector<int> dp(1000001, -1);
  ll sum = 0;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      for (int k = 1; k <= c; k++) {
        int cur = i * j * k, r = cur;
        if (dp[cur] == -1) {
          ll cnt = 1;
          for (int d = 2, mx = sqrt(r); d <= mx && r != 1; d++) {
            int cnt2 = 1;
            while (r % d == 0) {
              r /= d;
              cnt2++;
            }
            cnt = cnt * cnt2 % mod;
          }
          if (r != 1) cnt *= 2;
          dp[cur] = cnt;
        }
        sum = (sum + dp[cur]) % mod;
      }
    }
  }

  cout << sum;

  return 0;
}