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
#define mod       1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  int n, m, k; cin >> n >> m >> k;
  vector<int> len(n + 1), wid(m + 1);
  int con = 0;
  rep(i, n) {
    int a; cin >> a;
    if (a) {
      con++;
      len[con]++;
    }
    else
      con = 0;
  }
  partial_sum(rall(len), len.rbegin());

  con = 0;
  rep(i, m) {
    int a; cin >> a;
    if (a) {
      con++;
      wid[con]++;
    }
    else
      con = 0;
  }
  partial_sum(rall(wid), wid.rbegin());

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (k % i == 0 && k / i <= m) {
      ans += (ll)len[i] * wid[k / i];
    }
  }

  cout << ans;

  return 0;
}