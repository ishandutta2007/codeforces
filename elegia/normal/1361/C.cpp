#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <tuple>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>
 
#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}
 
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i] >> b[i];

  auto pred = [&](int r) {
    vector<int> deg(1 << r);
    int mask = (1 << r) - 1;
    vector<vector<pair<int, int>>> g(1 << r);
    for (int i = 0; i < n; ++i) {
      ++deg[a[i] & mask];
      ++deg[b[i] & mask];
      g[a[i] & mask].emplace_back(b[i] & mask, i * 2);
      g[b[i] & mask].emplace_back(a[i] & mask, i * 2 + 1);
    }
    for (int i = 0; i <= mask; ++i)
      if (deg[i] & 1)
        return vector<int>();
    vector<bool> vis(n);
    vector<int> ans;
    ans.reserve(n * 2);
    function<void(int)> dfs = [&](int u) {
      while (!g[u].empty()) {
        while (!g[u].empty() && vis[g[u].back().second >> 1]) g[u].pop_back();
        if (g[u].empty()) return;
        int v = g[u].back().first, rec = g[u].back().second;
        g[u].pop_back();
        vis[rec >> 1] = true;
        dfs(v);
        ans.push_back(rec ^ 1);
        ans.push_back(rec);
      }
    };
    for (int i = 0; i <= mask; ++i)
      if (deg[i]) {
        dfs(i);
        break;
      }
    reverse(ans.begin(), ans.end());
    return ans;
  };

  int l = 0, r = 20;
  vector<int> ans;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (pred(mid).size() == n * 2)
      l = mid;
    else
      r = mid - 1;
  }
  ans = pred(l);
  cout << l << '\n';
  for (int& res : ans) ++res;
  cout << ans << '\n';

  return 0;
}