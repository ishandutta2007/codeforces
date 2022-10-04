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
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  vector<char> all;
  for (char c = 'a'; c <= 'z'; ++c) {
    all.push_back(c);
  }
  for (char c = 'A'; c <= 'Z'; ++c) {
    all.push_back(c);
  }
  sort(all.begin(), all.end());
  auto get = [&](char c) {
    return lower_bound(all.begin(), all.end(), c) - all.begin();
  };
  const int K = all.size();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    vector<vector<vector<int>>> where(n, vector<vector<int>>(K, vector<int>(2, -1)));
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      int tt = 0;
      for (auto c : s) {
        int x = get(c);
        a[i].push_back(x);
        if (where[i][x][0] == -1) {
          where[i][x][0] = tt;
        } else if (where[i][x][1] == -1) {
          where[i][x][1] = tt;
        }
        ++tt;
      }
    }
    int id = get('a');
    int nodes = (1 << n) * K;
    vector<vector<pair <int, int>>> g(nodes);
    vector<int> ok_node(nodes);
    for (int c = 0; c < K; ++c) {
      for (int mask = 0; mask < (1 << n); ++mask) {
        bool bad = false;
        for (int i = 0; i < n; ++i) {
          int oc = (mask >> i) & 1;
          if (where[i][c][oc] == -1) {
            bad = true;
          }
        }
        if (bad) {
          ok_node[mask * K + c] = 0;
          continue;
        } else {
          ok_node[mask * K + c] = 1;
        } 

        for (int i = 0; i < n; ++i) {
          if (!((mask >> i) & 1) && where[i][c][1] != -1) {
            g[mask * K + c].push_back({(mask | (1 << i)) * K + c, 0});
          }
        }
        for (int nc = 0; nc < K; ++nc) {
          int nmask = 0;
          bool bad = false;
          for (int i = 0; i < n; ++i) {
            int oc = (mask >> i) & 1;
            if (where[i][nc][0] > where[i][c][oc]) {
              continue;
            } else if (where[i][nc][1] > where[i][c][oc]) {
              nmask |= (1 << i);
              continue;
            } else {
              bad = true;
              break;
            }
          }
          if (!bad) {
            g[mask * K + c].push_back({nmask * K + nc, 1});
          }
        }
      }
    }
    vector<int> dp(nodes);
    vector<int> used(nodes);
    vector<int> go(nodes, -1);
    vector<int> flag(nodes, 0);
    function<void(int)> dfs = [&](int u) {
      dp[u] = max(dp[u], 1);
      used[u] = 1;
      for (auto [v, w] : g[u]) {
        if (!used[v]) {
          dfs(v);
        }
        if (dp[v] + w > dp[u]) {
          dp[u] = dp[v] + w;
          go[u] = v;
          if (w == 1) {
            flag[u] = 1;
          }
        }
      }
    };
    for (int i = 0; i < nodes; ++i) {
      if (!used[i] && ok_node[i]) {
        dfs(i);
      }
    }
    int ans = 0, idx = -1;
    for (int i = 0; i < nodes; ++i) {
      if (dp[i] > ans) {
        ans = dp[i];
        idx = i;
      }
    }
    cout << ans << '\n';
    string res;
    int cur = idx;
    res += all[cur % K];
    while (cur != -1) {
      bool need = flag[cur];
      cur = go[cur];
      if (cur != -1 && need) res += all[cur % K];
    }
    if (ans) cout << res << '\n';
  }   
}