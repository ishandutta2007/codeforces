#include <bits/stdc++.h>
using namespace std;

// #define int ll
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

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
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  dotc() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    ll cur = 0;
    ll mx = 0;
    ll odd = 0, even = -a[0];
    rep(i, n) {
      if (i & 1) {
        cur += a[i];
        mx = max(mx, cur - odd);
        odd = min(odd, cur);
      } else {
        cur -= a[i];
        mx = max(mx, cur - even);
        even = min(even, cur);
      }
    }

    ll sum = 0;
    rep(i, n) if (~i & 1) sum += a[i];

    cout << mx + sum << '\n';
  }

  return 0;
}