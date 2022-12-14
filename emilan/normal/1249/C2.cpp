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

int main() {
  ioThings();

  dotc() {
    ll n;
    cin >> n;

    ll l = 0, r = (1ll << int(62 / log(3) * log(2)));
    while (l < r) {
      ll m = l + (r - l) / 2, x = 0;

      for (ll i = 1, j = m; j; i *= 3, j /= 2) {
        x += (j & 1) * i;
      }

      if (x >= n) r = m;
      else l = m + 1;
    }

    ll x = 0;
    for (ll i = 1, j = l; j; i *= 3, j /= 2) {
      x += (j & 1) * i;
    }

    cout << x << '\n';
  }

  return 0;
}