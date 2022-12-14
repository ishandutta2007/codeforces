#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
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

int main() {
  ioThings();

  int n, m; cin >> n >> m;
  vector<set<int>> adj(n + 1);
  while (m--) {
    int a, b; cin >> a >> b;
    adj[a].insert(b);
    adj[b].insert(a);
  }

  int cnt = -1;
  bool ok = true;
  while (ok) {
    cnt++;
    vector<int> kicked;
    ok = false;
    for (int i = 1; i <= n; i++)
      if (sz(adj[i]) == 1) {
        kicked.pb(i);
        ok = true;
      }

    for (auto& i : kicked) {
      for (int j = 1; j <= n; j++) {
        if (adj[j].count(i))
          adj[j].erase(i);
      }
      adj[i].clear();
    }
  }

  cout << cnt;

  return 0;
}