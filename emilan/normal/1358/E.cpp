#include "bits/stdc++.h"
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
  cin >> n;
  int l = (n + 1) / 2;
  vector<ll> a(n);
  rep(i, l) cin >> a[i];
  int x;
  cin >> x;
  fill(a.begin() + l, a.end(), x);

  vector<ll> p(n);
  partial_sum(all(a), p.begin());

  vector<ll> p2(l + 1);
  rep(i, l) p2[i + 1] = x - a[i];

  vector<ll> p3(l + 1);
  partial_sum(all(p2), p3.begin());
  rep(i, l) p3[i + 1] = min(p3[i], p3[i + 1]);

  int k;
  for (k = l; k <= n; k++) {
    if (p[k - 1] + p3[n - k] > 0) break;
  }

  if (k == n + 1) cout << -1;
  else cout << k;
  
  return 0;
}