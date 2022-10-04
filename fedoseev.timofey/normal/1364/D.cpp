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
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;
vector <int> g[N];
int used[N];
int col[N];

vector <int> path;
vector <int> cycle;

void dfs(int u, int p = -1) {
  used[u] = 1;
  path.push_back(u);
  for (auto v : g[u]) {
    if (used[v] == 1 && v != p) {
      if (cycle.empty()) {
        for (int i = 0; i < (int)path.size(); ++i) {
          if (path[i] == v) {
            cycle = vector <int> (path.begin() + i, path.end());
            break;
          }
        }
      }
    }
  }
  for (auto v : g[u]) {
    if (!used[v]) {
      col[v] = col[u] ^ 1;
      dfs(v, u);
    }
  }
  used[u] = 2;
  path.pop_back();
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m, k;
  cin >> n >> m >> k;
  vector <pair <int, int>> edges;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
    edges.push_back({u, v});
  }
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      col[i] = 0;
      dfs(i);
    }
  }
  if (!cycle.empty() && (int)cycle.size() <= k) {
    cout << "2\n" << cycle.size() << '\n';
    for (int id : cycle) cout << id + 1 << ' ';
  } else if (cycle.empty()) {
    vector <vector <int>> who(2);
    for (int i = 0; i < n; ++i) {
      who[col[i]].push_back(i);
    }
    for (int tt = 0; tt < 2; ++tt) {
      if (who[tt].size() >= (k + 1) / 2) {
        cout << "1\n";
        for (int i = 0; i < (k + 1) / 2; ++i) {
          cout << who[tt][i] + 1 << ' ';
        }
        cout << '\n';
        break;
      }
    }   
  } else {
    cout << "1\n";
    int id = 0;
    for (int i = 0; i < (k + 1) / 2; ++i) {
      cout << cycle[id] + 1 << ' ';
      id += 2;
    }
  }   
}