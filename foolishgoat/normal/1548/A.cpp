#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;


set<int> g[N];
int vuln = 0;

void add(int u, int v) {
  bool ok = g[u].size() == 0;
  if (v > u) {
    g[u].insert(v);
  }
  ok &= g[u].size() > 0;
  vuln += ok;
}


void rem(int u, int v) {
  bool ok = g[u].size() > 0;
  g[u].erase(v);
  ok &= g[u].size() == 0;
  vuln -= ok;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    add(u, v);
    add(v, u);
  }
  int q;
  cin >> q;
  while (q--) {
    int t, u, v;
    cin >> t;
    if (t == 3) {
      cout << n - vuln << '\n';
    } else {
      cin >> u >> v;
      --u, --v;
      if (t == 1) {
        add(u, v);
        add(v, u);
      } else {
        rem(u, v);
        rem(v, u);
      }
    }
  }
  return 0;
}