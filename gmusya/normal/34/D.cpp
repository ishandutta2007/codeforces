#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

vi p;
vvi g;

void dfs(int v, int par = -1) {
  for (int u : g[v])
    if (u != par) {
      p[u] = v;
      dfs(u, v);
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, r1, r2;
  cin >> n >> r1 >> r2;
  r1--, r2--;
  g.resize(n), p.resize(n);
  for (int i = 0; i < n; i++) {
    if (i == r1)
      continue;
    int v;
    cin >> v;
    v--;
    g[i].push_back(v);
    g[v].push_back(i);
  }
  dfs(r2);
  for (int i = 0; i < n; i++) {
    if (i == r2)
      continue;
    cout << p[i] + 1 << ' ';
  }
  return 0;
}