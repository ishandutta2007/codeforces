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

const int N = 200010;

int n, m, k;
int a[N], ds[N], dt[N];
pair<int, int> x[N];
vector<int> g[N];

void bfs(int s, int dis[]) {
  fill(dis + 1, dis + n + 1, -1);
  queue<int> q;
  q.push(s);
  dis[s] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : g[u])
      if (dis[v] == -1) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
  }
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;
  for (int i = 1; i <= k; ++i) cin >> a[i];
  while (m--) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  bfs(1, ds);
  bfs(n, dt);

  int ans = -1;
  for (int i = 1; i <= k; ++i)
    x[i] = make_pair(ds[a[i]], dt[a[i]]);

  function<void(vector<pair<int, int>>, vector<pair<int, int>>)> gao = [&](vector<pair<int, int>> a, vector<pair<int, int>> b) {
    sort(a.begin(), a.end());
    for (auto& pr : b) swap(pr.first, pr.second);
    sort(b.begin(), b.end());
    int j = 0;
    vector<int> suf(b.size());
    suf.back() = b.back().second;
    for (int i = (int)b.size() - 2; i >= 0; --i) suf[i] = max(suf[i + 1], b[i].second);
    for (int i = (int)a.size() - 1; i >= 0; --i) {
      while (j < b.size() && b[j].first + a[i].first < ds[n]) ++j;
      if (j == b.size()) break;
      ans = max(ans, a[i].second + suf[j]);
    }
  };

  function<void(int, int)> dc = [&](int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    dc(l, mid);
    dc(mid + 1, r);
    gao(vector<pair<int, int>>(x + l, x + mid + 1), vector<pair<int, int>>(x + mid + 1, x + r + 1));
    gao(vector<pair<int, int>>(x + mid + 1, x + r + 1), vector<pair<int, int>>(x + l, x + mid + 1));
  };
  dc(1, k);

  ans = min(ans + 1, ds[n]);
  cout << ans << '\n';

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}