#include <bits/stdc++.h>
using namespace std;

void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
  freopen("io\\err.txt", "w", stderr);
#endif
}

using   ll        = long long;
#define debug(x)    cerr << #x << ": <" << (x) << ">\n"
#define dotc()      int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second
#define mod         1000000007

vector<set<pair<int, int>>> adj(101);
set<pair<int, int>> explored;

bool dfs(int a, int b, int c) {
  if (explored.count({a, c}))
    return false;

  explored.emplace(a, c);

  if (a == b)
    return true;

  for (auto& i : adj[a])
    if (i.se == c && dfs(i.fi, b, c))
      return true;

  return false;
}

int main() {
  ioThings();

  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    adj[a].emplace(b, c);
    adj[b].emplace(a, c);
  }

  int q; cin >> q;
  while (q--) {
    int a, b; cin >> a >> b;
    set<int> colors;
    explored.clear();
    for (auto& i : adj[a])
      if (!colors.count(i.se) && dfs(i.fi, b, i.se))
        colors.insert(i.se);

    cout << sz(colors) << '\n';
  }

  return 0;
}