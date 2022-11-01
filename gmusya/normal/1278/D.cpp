#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define fi first
#define se second

using namespace std;

typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;

int n;
int cnt = 0;
vvi g;

void dfs(int v, int p = -1) {
  cnt++;
  if (cnt >= n)
    return;
  for (int u : g[v])
    if (u != p)
      dfs(u, v);
}

int main() {
  cin >> n;
  vector <int> a(2 * n + 1);
  vector <pii> b;
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    a[l] = i;
    a[r] = -i;
    b.push_back({l, r});
  }
  set <pii> s;
  g.resize(n);
  for (int i = 1; i <= n + n; i++) {
    if (cnt >= n) {
      cout << "NO\n";
      return 0;
    }
    if (a[i] > 0) {
      int id = a[i] - 1;
      s.insert({i, id});
      continue;
    } else {
      int id = -a[i] - 1;
      auto it = s.upper_bound({b[id].fi, id});
      while (it != s.end()) {
        if (it->second == id)
          continue;
        g[it->second].push_back(id);
        g[id].push_back(it->second);
        cnt++;
        it++;
      }
      s.erase({b[id].fi, id});
    }
  }
  if (cnt != n - 1) {
    cout << "NO\n";
    return 0;
  }
  cnt = 0;
  dfs(0);
  if (cnt == n)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}