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
#define mp(x, y)  make_pair(x, y);
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second
#define mod       1000000007

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define off 10000

int main() {
  ioThings();

  int n;
  cin >> n;

  vi a(n);
  rep(i, n) cin >> a[i];

  ll res = 0;
  vector<vector<ll>> dp(n + 1, vector<ll>(20001));

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 20001; j++) {
      if (j + a[i - 1] >= 0 && j + a[i - 1] < 20001)
        dp[i][j] = (dp[i][j] + dp[i - 1][j + a[i - 1]]) % mod;
        
      if (j - a[i - 1] >= 0 && j - a[i - 1] < 20001)
        dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i - 1]]) % mod;
    }
    dp[i][off - a[i - 1]]++;
    dp[i][off + a[i - 1]]++;
    res = (res + dp[i][off]) % mod;
  }

  cout << res;

  return 0;
}