#include <iostream>
#include <vector>
#include <map>

typedef long long ll;

using namespace std;

vector <int> c;
vector <ll> ans;
vector <vector <int>> g;
vector <map <int, ll>> cnt, sum;

void dfs(int v, int p = -1) {
  sum[v][1] = c[v];
  cnt[v][c[v]] = 1;
  for (int u : g[v])
    if (u != p) {
      dfs(u, v);
      if (cnt[u].size() > cnt[v].size()) {
        swap(cnt[u], cnt[v]);
        swap(sum[u], sum[v]);
      }
      for (auto &now : cnt[u]) {
        int colour = now.first, counter = now.second;
        sum[v][cnt[v][colour]] -= colour;
        cnt[v][colour] += counter;
        sum[v][cnt[v][colour]] += colour;
      }
    }
  ans[v] = sum[v].rbegin()->second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  c.resize(n);
  ans.resize(n);
  g.resize(n);
  cnt.resize(n), sum.resize(n);
  for (int i = 0; i < n; i++)
    cin >> c[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  for (auto &now : ans)
    cout << now << ' ';
  return 0;
}