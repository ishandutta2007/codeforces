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

  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<pair<int, int>> pos(n);
  for (int i = 0; i < n; ++i) {
    cin >> pos[i].first;
    --pos[i].first;
    pos[i].second = i;
  }
  /*
  vector<pair<int, int>> mex(n), pos(n);
  for (int i = 0; i < n; ++i) {
    cin >> pos[i].first;
    --pos[i].first;
    pos[i].second = i;
  }
  for (int i = 0; i < n; ++i) {
    vector<bool> vis(g[i].size() + 1);
    for (int x : g[i])
      if (x <= g[i].size())
        vis[x] = true;
    int val = 0;
    while (vis[val]) ++val;
    mex[i] = make_pair(val, i);
  }
  sort(mex.begin(), mex.end());
  sort(pos.begin(), pos.end());
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    if (mex[i].first != pos[i].first) {
      cout << "-1\n";
      return 0;
    }
    ans[pos[i].second] = mex[i].second + 1;
  }
  cout << ans << '\n';*/
  auto mex = [&](const vector<int>& vec) {
    vector<bool> vis(vec.size() + 1);
    for (int x : vec)
      if (x < vec.size())
        vis[x] = true;
    int ret = 0;
    while (vis[ret]) ++ret;
    return ret;
  };
  for (int i = 0; i < n; ++i) {
    vector<int> cur;
    for (int j : g[i])
      cur.push_back(pos[j].first);
    if (pos[i].first != mex(cur)) {
      cout << "-1\n";
      return 0;
    }
  }
  sort(pos.begin(), pos.end());
  vector<int> ans(n);
  for (int i = 0; i < n; ++i)
    ans[i] = pos[i].second + 1;
  cout << ans << '\n';

  return 0;
}