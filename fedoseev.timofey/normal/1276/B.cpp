#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>

using namespace std;

typedef long long ll;

const int N = 2e5 + 7;

vector <int> g[N];
bool used[N];
bool ha[N], hb[N];
int cnt;
int sz[N];

void dfs(int u, int a, int b) {
  used[u] = 1;
  ++sz[cnt];
  for (auto v : g[u]) {
    if (v != a && v != b && !used[v]) dfs(v, a, b);
    if (v == a) ha[cnt] = 1;
    if (v == b) hb[cnt] = 1;
  }
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    --a, --b;
    for (int i = 0; i < n; ++i) g[i].clear();
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    fill(used, used + n, false);
    fill(ha, ha + n, false);
    fill(hb, hb + n, false);
    fill(sz, sz + n, 0);
    cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (i != a && i != b && !used[i]) {
        dfs(i, a, b);
        ++cnt;
      }
    }
    int sa = 0, sb = 0;
    for (int i = 0; i < n; ++i) {
      if (ha[i] && !hb[i]) sa += sz[i];
      if (hb[i] && !ha[i]) sb += sz[i];
    }
    cout << (ll)sa * sb << '\n';
  }
}