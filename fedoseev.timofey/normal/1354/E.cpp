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

const int N = 5007;

vector <int> g[N];
int used[N];

vector <int> cmp[2];

void dfs(int u) {
  cmp[used[u]].push_back(u);
  for (auto v : g[u]) {
    if (used[v] == -1) {
      used[v] = used[u] ^ 1;
      dfs(v);
    } else if (used[v] != (used[u] ^ 1)) {
      cout << "NO\n";
      exit(0);
    }
  }
}

vector <int> have[N][2];

bool dp[N][N];
int pr[N][N];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  fill(used, used + n, -1);
  int uk = 0;
  for (int i = 0; i < n; ++i) {
    if (used[i] == -1) {
      cmp[0].clear();
      cmp[1].clear();
      used[i] = 0;
      dfs(i);
      have[uk][0] = cmp[0];
      have[uk][1] = cmp[1];
      ++uk;
    }
  }
  dp[0][0] = 1;
  for (int i = 1; i <= uk; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (j >= have[i - 1][0].size() && dp[i - 1][j - (int)have[i - 1][0].size()]) {
        dp[i][j] = 1;
        pr[i][j] = 0;
      }
      if (j >= have[i - 1][1].size() && dp[i - 1][j - (int)have[i - 1][1].size()]) {
        dp[i][j] = 1;
        pr[i][j] = 1;
      }
    }
  }
  if (dp[uk][n2]) {
    cout << "YES\n";
    vector <int> ans(n, -1);
    int j = n2;
    for (int i = uk; i >= 1; --i) {
      if (pr[i][j] == 0) {
        for (int id : have[i - 1][0]) {
          ans[id] = 2;
        }
        j -= have[i - 1][0].size();
      } else {
        for (int id : have[i - 1][1]) {
          ans[id] = 2;
        }
        j -= have[i - 1][1].size();
      }
    } 
    for (int i = 0; i < n; ++i) {
      if (ans[i] == -1) {
        if (n1 > 0) {
          ans[i] = 1;
          --n1;
        } else {
          ans[i] = 3;
          --n3;
        }
      }
    }
    for (int i = 0; i < n; ++i) cout << ans[i];
    cout << '\n';
  } else {
    cout << "NO\n";
  }
}