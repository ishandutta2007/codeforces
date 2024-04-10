#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = (1e9 + 123) * (1e9 + 321);

struct query {
  int x;
  int type;
  int id;
  bool operator<(query q) {
    if (x != q.x)
      return x < q.x;
    return type < q.type;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector <int> l(q), r(q), v(q);
  for (int i = 0; i < q; i++) {
    cin >> l[i] >> r[i] >> v[i];
    l[i]--, r[i]--;
  }
  vector <query> queries;
  for (int i = 0; i < q; i++) {
    queries.push_back({l[i], -1, i});
    queries.push_back({r[i], 1, i});
  }
  for (int i = 0; i < n; i++)
    queries.push_back({i, 0, i});
  sort(queries.begin(), queries.end());
  vector <ll> dp(n + 1, 0);
  dp[0] = 1;
  vector <bool> can(n + 1);
  for (query que : queries) {
    int type = que.type, id = que.id;
    if (type == -1) {
      for (int i = n; i >= v[id]; i--) {
        dp[i] += dp[i - v[id]];
        while (dp[i] >= MOD)
          dp[i] -= MOD;
      }
    }
    if (type == 0) {
      for (int i = 1; i <= n; i++)
        if (dp[i])
          can[i] = true;
    }
    if (type == 1) {
      for (int i = 0; i + v[id] <= n; i++) {
        dp[i + v[id]] -= dp[i];
        while (dp[i + v[id]] < 0)
          dp[i + v[id]] += MOD;
      }
    }
  }
  vector <int> ans;
  for (int i = 1; i <= n; i++)
    if (can[i])
      ans.push_back(i);
  cout << ans.size() << '\n';
  for (int x : ans)
    cout << x << ' ';
  return 0;
}