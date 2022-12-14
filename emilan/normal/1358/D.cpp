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

ll mod(1000000007);
double pi(acos(-1.0));

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  int n;
  ll x;
  cin >> n >> x;
  vector<ll> d(n);
  rep(i, n) cin >> d[i];

  vector<ll> ps(n);
  partial_sum(all(d), ps.begin());
  rep(i, n) ps.pb(ps[i] + ps[n - 1]);

  // for (int i : ps) cout << i << ' ';
  // cout << endl;

  int l = 1, r = n;
  vi range(n);
  while (r < 2 * n) {
    ll sum = ps[r] - ps[l - 1];
    if (sum > x && l < r) l++;
    else {
      if (sum > x && l == r) l++;
      range[r - n] = l - 1;
      r++;
    }
  }

  vector<ll> sum(n);
  rep(i, n) sum[i] = d[i] * (d[i] + 1) / 2;
  vector<ll> ps2(n);
  partial_sum(all(sum), ps2.begin());
  rep(i, n) ps2.pb(ps2[i] + ps2[n - 1]);

  ll mx = 0;
  rep(i, n) {
    ll rd = x - ps[i + n] + ps[range[i]];
    ll tot = ps2[i + n] - ps2[range[i]];
    // cout << i << ' ' << range[i] << ' ' << rd << endl;
    // cout << tot << endl;
    tot += (d[range[i] % n] * 2 - rd + 1) * rd / 2;
    // cout << tot << endl;
    mx = max(tot, mx);
  }

  cout << mx;

  return 0;
}