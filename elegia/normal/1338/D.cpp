#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
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

const int INF = 1e7;

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int rep = 1; rep < n; ++rep) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> p(n, -1);
  vector<int> down(n), down2(n), top(n), top2(n);
  function<void(int)> dfs1 = [&](int u) {
    int mx = 0, mx2 = 0, cnt = 0;
    for (int v : g[u])
      if (v != p[u]) {
        p[v] = u;
        dfs1(v);
        ++cnt;
        mx = max(mx, down2[v]);
        mx2 = max(mx2, down[v]);
      }
    down[u] = max(cnt + mx, cnt - 1 + mx2);
    down2[u] = mx2;
  };
  function<void(int)> dfs2 = [&](int u) {
    vector<int> ver;
    for (int v : g[u])
      if (v != p[u])
        ver.push_back(v);
    if (ver.empty()) return;
    int cnt = ver.size();
    vector<int> pre(cnt + 1), suf(cnt + 1), pre2(cnt + 1), suf2(cnt + 1);
    pre[0] = suf[cnt] = pre2[0] = suf2[cnt] = -INF;
    for (int i = 0; i < cnt; ++i) pre[i + 1] = max(pre[i], down[ver[i]]);
    for (int i = cnt; i; --i) suf[i - 1] = max(suf[i], down[ver[i - 1]]);
    for (int i = 0; i < cnt; ++i) pre2[i + 1] = max(pre2[i], down2[ver[i]]);
    for (int i = cnt; i; --i) suf2[i - 1] = max(suf2[i], down2[ver[i - 1]]);
    for (int i = 0; i < cnt; ++i) {
      int mx = max({pre[i], suf[i + 1], top[u]});
      int mx2 = max({pre2[i], suf2[i + 1], top2[u]});
      top[ver[i]] = max((int)g[u].size() - 1 + mx2, (int)g[u].size() - 2 + mx);
      top2[ver[i]] = mx;
      dfs2(ver[i]);
    }
  };
  int rt = 0;
  dfs1(rt);
  top[rt] = top2[rt] = -INF;
  dfs2(rt);
  int ans = 0;
  for (int i = 0; i < n; ++i) if (i != rt) ans = max(ans, down[i] + 1);
  for (int i = 0; i < n; ++i) if (i != rt) ans = max(ans, top[i] + 1);
  cout << ans << '\n';

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}