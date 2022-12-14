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
#define mt        make_tuple
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
  vvi m(n);
  rep(i, n) {
    int l;
    cin >> l;
    m[i].resize(l);
    rep(j, l) cin >> m[i][j];
  }

  vi mn(n), mx(n);
  rep(i, n) {
    int cmn = 1e9, cmx = -1;
    bool ok = false;
    for (int j : m[i]) {
      if (j < cmn) cmn = j;
      else if (j > cmn) ok = true;
      if (j > cmx) cmx = j;
    }
    if (ok) mn[i] = -1, mx[i] = 1e9;
    else mn[i] = cmn, mx[i] = cmx;
  }

  sort(all(mn));
  sort(all(mx));

  ll cnt = 0;
  rep(i, n) {
    cnt += distance(upper_bound(all(mx), mn[i]), mx.end());
  }

  cout << cnt;

  return 0;
}