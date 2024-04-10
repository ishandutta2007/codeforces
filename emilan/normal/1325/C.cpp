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
  cin >> n;
  vector<vii> adj(n + 1);
  rep(i, n - 1) {
    int x, y;
    cin >> x >> y;
    adj[x].pb({y, i});
    adj[y].pb({x, i});
  }

  vi ans(n - 1, -1);
  int x = 0;
  rep(i, n) {
    if (sz(adj[i + 1]) == 1) {
      int idx = adj[i + 1][0].se;
      if (ans[idx] == -1) ans[idx] = x++;
    }
  }

  for (int i : ans) cout << (i != -1 ? i : x++) << '\n';

  return 0;
}