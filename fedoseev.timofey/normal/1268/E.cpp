#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <random>
 
using namespace std;
 
typedef long long ll;
 
const int N = 5e5 + 7;
 
vector <int> g[N];
 
int used[N];
int pos[N];
vector <vector <int>> cycles;
 
vector <int> st;
 
void dfs(int u, int p = -1) {
  st.push_back(u);
  pos[st.back()] = (int)st.size() - 1;
  used[u] = 1;
  for (auto v : g[u]) {
    if (!used[v]) {
      dfs(v, u);
    } else if (v != p && used[v] == 1) {
      int x = pos[v];
      cycles.push_back({});
      for (int i = x; i < (int)st.size(); ++i) {
        cycles.back().push_back(st[i]);
      }
    }
  }
  st.pop_back();
  used[u] = 2;
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector <pair <int, int>> edges;
  map <pair <int, int>, int> id;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
    edges.push_back({u, v});
    id[{u, v}] = id[{v, u}] = i;
  }
  dfs(0);
  vector <int> res(m);
  vector <int> who(m, -1);
  vector <int> cmp(n, -1);
  
  for (int i = 0; i < (int)cycles.size(); ++i) {
    vector <int> ce;
    for (int j = 0; j < (int)cycles[i].size(); ++j) {
      cmp[cycles[i][j]] = i;
      ce.push_back(id[{cycles[i][j], cycles[i][(j + 1) % (int)cycles[i].size()]}]);
    }
    rotate(ce.begin(), min_element(ce.begin(), ce.end()), ce.end());
    int mx = max_element(ce.begin(), ce.end()) - ce.begin();
    bool ok = true;
    for (int i = 1; i <= mx; ++i) ok &= ce[i] > ce[i - 1];
    for (int i = mx + 1; i < ce.size(); ++i) ok &= ce[i] < ce[i - 1];
    if (ok) who[ce[0]] = ce[mx];
  }
 
  vector <int> ans(n, 1);
  for (int i = m - 1; i >= 0; --i) {
    int a = edges[i].first;
    int b = edges[i].second;
    int sum = ans[a] + ans[b];
    if (who[i] != -1) sum -= res[who[i]];
    res[i] = sum;
    ans[a] = ans[b] = sum;
  }
  for (int i = 0; i < n; ++i) cout << ans[i] - 1 << ' ';
}