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

int n, m;
vector<vi> adj(51, vi(51));
vector<int> color(51);
ll d = 1;

void dfs(int x) {
  color[x] = 1;
  for (int i = 1; i <= n; i++) {
    if (adj[x][i] && !color[i]) {
      dfs(i);
      d *= 2;
    }
  }
}

int main() {
  ioThings();

  cin >> n >> m;
  rep(i, m) {
    int x, y; cin >> x >> y;
    adj[x][y] = 1;
    adj[y][x] = 1;
  }

  for (int i = 1; i <= n; i++) {
    if (!color[i]) dfs(i);
  }

  cout << d;

  return 0;
}