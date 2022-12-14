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

  int n, m;
  cin >> n >> m;
  vvi dir(n);
  vi cnt(n);
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (x > y) swap(x, y);
    dir[y].pb(x);
    cnt[x]++;
  }

  int x = 1;
  vi pos(n);
  rep(i, n) {
    pos[i] = x;

    cout << max(1, cnt[i]) + sz(dir[i]) << '\n';
    if (!cnt[i]) cout << x << ' ' << i + 1 << '\n';
    rep(j, cnt[i]) {
      cout << x + j << ' ' << i + 1 << '\n';
    }
    for (int j : dir[i]) {
      cout << pos[j] << ' ' << i + 1 << '\n';
      pos[j]++;
    }

    x += max(1, cnt[i]);
  }

  return 0;
}