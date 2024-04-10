#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int timer = -1;
vi tin, tout, d;
vvi g;

void dfs(int v) {
  tin[v] = ++timer;
  for (int u : g[v]) {
    d[u] = d[v] + 1;
    dfs(u);
  }
  tout[v] = timer;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  g.resize(n);
  for (int i = 1; i < n; i++) {
    int v;
    cin >> v;
    v--;
    g[v].push_back(i);
  }
  tin.resize(n), tout.resize(n), d.resize(n);
  dfs(0);
  vector <char> s(n);
  for (int i = 0; i < n; i++)
    cin >> s[i];
  vector <vvi> cnt(n, vvi(26));
  for (int i = 0; i < n; i++)
    cnt[d[i]][s[i] - 'a'].push_back(tin[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 26; j++)
      if (!cnt[i][j].empty())
        sort(cnt[i][j].begin(), cnt[i][j].end());
  while (q--) {
    int v, h;
    cin >> v >> h;
    v--, h--;
    if (h <= d[v]) {
      cout << "Yes\n";
      continue;
    }
    int l = tin[v], r = tout[v];
    int x = 0;
    for (int i = 0; i < 26; i++)
      x += ((upper_bound(cnt[h][i].begin(), cnt[h][i].end(), r) -
           lower_bound(cnt[h][i].begin(), cnt[h][i].end(), l)) % 2);
    if (x < 2)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}