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
 
using namespace std;
 
typedef long long ll;
 
const int N = 1e5 + 7;
 
vector <int> in[N];
vector <int> out[N];

unordered_map <int, ll> w[N];
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v, d;
    cin >> u >> v >> d;
    --u, --v;
    out[u].push_back(v);
    in[v].push_back(u);
    w[u][v] += d;
  }
  for (int u = 0; u < n; ++u) {
    while (!in[u].empty() && !out[u].empty()) {
      int a = in[u].back();
      in[u].pop_back();
      int b = out[u].back();
      out[u].pop_back();
      ll w1 = w[a][u];
      ll w2 = w[u][b];
      if (w1 == 0 && w2 == 0) continue;
      if (w1 == 0) {
        out[u].push_back(b);
        continue;
      }
      if (w2 == 0) {
        in[u].push_back(a);
        continue;
      }
      ll cr = min(w1, w2);
      w[a][u] -= cr;
      w[u][b] -= cr;
      w1 -= cr;
      w2 -= cr;
      if (w1 > 0) {
        in[u].push_back(a);
      }
      if (w2 > 0) {
        out[u].push_back(b);
      }
      if (a != b) {
        in[b].push_back(a);
        out[a].push_back(b);
        w[a][b] += cr;
      }
    }
  }
  map <pair <int, int>, ll> ans;
  for (int i = 0; i < n; ++i) {
    for (auto p : w[i]) {
      if (p.second > 0) ans[{i, p.first}] += p.second;
    }
  }
  cout << ans.size() << '\n';
  for (auto p : ans) {
    cout << p.first.first + 1 << ' ' << p.first.second + 1 << ' ' << p.second << '\n';
  }
}