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

const int N = 5e5 + 7;

vector <int> g[N];
int par[N];
int h[N];
vector <int> who[N];
bool used[N];

void dfs(int u, int p) {
  used[u] = 1; 
  par[u] = p;
  who[h[u]].push_back(u);
  for (auto v : g[u]) {
    if (!used[v]) {
      h[v] = h[u] + 1;
      dfs(v, u);
    }
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
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      h[i] = 0;
      par[i] = 0;
      used[i] = 0;
      g[i].clear();
      who[i].clear();
    }
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(0, -1);
    bool fnd = false;
    for (int i = 0; i < n; ++i) {
      int len = h[i] + 1;
      if (2 * len >= n) {
        vector <int> path;
        int u = i;
        while (u != -1) {
          path.push_back(u);
          u = par[u];
        }
        cout << "PATH\n";
        cout << path.size() << '\n';
        for (auto x : path) {
          cout << x + 1 << ' ';
        }
        cout << '\n';
        fnd = true;
        break;
      }
    }
    if (fnd) continue;
    vector <pair <int, int>> pr;
    for (int i = 0; i < n; ++i) {
      while (who[i].size() >= 2) {
        pr.push_back({who[i].rbegin()[0], who[i].rbegin()[1]});
        who[i].pop_back();
        who[i].pop_back();
      }
    }
    cout << "PAIRING\n";
    cout << pr.size() << '\n';
    for (auto p : pr) {
      cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }
  }
}