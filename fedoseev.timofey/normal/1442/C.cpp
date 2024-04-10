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

const int Inf = 1e9;

const int md = 998244353;

int mul(int a, int b) {
  return ((ll)a * b) % md;
}

void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}

int power(int a, ll b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

const int K = 20;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector <vector <vector <int>>> g(n, vector <vector <int>> (2));
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u][0].push_back(v);
    g[v][1].push_back(u);
  }
  pair <int, int> res = {Inf, Inf};
  {
    vector <vector <pair <int, int>>> d(n, vector <pair <int, int>> (2, make_pair(Inf, Inf)));
    d[0][0] = {0, 0};
    set <tuple <pair <int, int>, int, int>> q;
    q.insert({d[0][0], 0, 0});
    while (!q.empty()) {
      auto tp = *q.begin();
      q.erase(q.begin());
      int u = get <1> (tp), t = get <2> (tp);
      if (d[u][t ^ 1] > make_pair(d[u][t].first + 1, d[u][t].second)) {
        q.erase({d[u][t ^ 1], u, t ^ 1});
        d[u][t ^ 1] = make_pair(d[u][t].first + 1, d[u][t].second);
        q.insert({d[u][t ^ 1], u, t ^ 1});
      }
      for (auto v : g[u][t]) {
        if (d[v][t] > make_pair(d[u][t].first, d[u][t].second + 1)) {
          q.erase({d[v][t], v, t});
          d[v][t] = make_pair(d[u][t].first, d[u][t].second + 1);
          q.insert({d[v][t], v, t});
        }
      }
    }
    res = min(d[n - 1][0], d[n - 1][1]);
  }
  if (res.first >= K) {
    int ans = power(2, res.first);
    add(ans, res.second);
    sub(ans, 1);
    cout << ans << '\n';
  } else {
    vector <vector <vector <int>>> dp(K, vector <vector <int>> (n, vector <int> (2, Inf)));
    dp[0][0][0] = 0;
    for (int i = 0; i < K; ++i) {
      set <tuple <int, int, int>> q;
      for (int j = 0; j < n; ++j) {
        for (int t = 0; t < 2; ++t) {
          if (dp[i][j][t] != Inf) {
            q.insert({dp[i][j][t], j, t});
          }
        }
      }
      while (!q.empty()) {
        auto tp = *q.begin();
        q.erase(q.begin());
        int u = get <1> (tp), t = get <2> (tp);
        for (auto v : g[u][t]) {
          if (dp[i][v][t] > dp[i][u][t] + 1) {
            q.erase({dp[i][v][t], v, t});
            dp[i][v][t] = dp[i][u][t] + 1;
            q.insert({dp[i][v][t], v, t});
          }
        }
      }
      if (i + 1 < K) {
        for (int j = 0; j < n; ++j) {
          for (int t = 0; t < 2; ++t) {
            dp[i + 1][j][t ^ 1] = dp[i][j][t];
          }
        }
      }
    } 
    int ans = Inf;
    int pw = 1;
    int cur = 0;
    for (int cnt = 0; cnt < K; ++cnt) {
      ans = min(ans, cur + min(dp[cnt][n - 1][0], dp[cnt][n - 1][1])); 
      cur += pw;
      pw *= 2;
    }
    cout << ans % md << '\n';
  } 
}