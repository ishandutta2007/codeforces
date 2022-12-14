#include <bits/stdc++.h>
using namespace std;

// #define int ll
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define fastio    ios::sync_with_stdio(0); cin.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define mp        make_pair
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second

int inf(0x3fffffff);
int mod(1000000007);
double pi(acos(-1.0));

int32_t main() {
  fastio;
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  dotc() {
    ll n, x, y;
    cin >> n >> x >> y;
    x--, y--;

    ll l = 0, r = n - 1;
    while (l < r) {
      ll mi = (l + r) / 2;
      if (n * (n - 1) - mi * (mi - 1) > x) l = mi + 1;
      else r = mi;
    }

    ll cur = n * (n - 1) - l * (l + 1);
    while (cur <= y) {
      if (cur == n * (n - 1)) {
        cout << 1;
        break;
      }

      rep(i, l * 2) {
        if (cur >= x && cur <= y) {
          if (i & 1) cout << n - l + (i + 1) / 2 << ' ';
          else cout << n - l << ' ';
        }

        cur++;
      }

      l--;
    }

    cout << '\n';
  }

  return 0;
}