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

const int N = 155;

int n, m;
int dist[N];
pair<int, pair<int, int>> edge[N];
bitset<N> g[N], tmp[N], db[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 1; i <= m; ++i)
    cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
  int ans = 2e9;
  sort(edge + 1, edge + m + 1);
  bitset<N> vis;
  vis.set(1);
  for (int i = 1; i <= m; ++i) {
    int k = edge[i].first - edge[i - 1].first;
    copy(g + 1, g + n + 1, db + 1);
    while (k) {
      if (k & 1) {
        bitset<N> res;
        for (int j = 1; j <= n; ++j)
          if (vis[j])
            res |= db[j];
        vis = res;
      }
      if (k >>= 1) {
        for (int j = 1; j <= n; ++j) tmp[j].reset();
        for (int j = 1; j <= n; ++j)
          for (int l = 1; l <= n; ++l)
            if (db[j][l])
              tmp[j] |= db[l];
        copy(tmp + 1, tmp + n + 1, db + 1);
      }
    }
    g[edge[i].second.first].set(edge[i].second.second);
    queue<int> q;
    for (int j = 1; j <= n; ++j) {
      if (vis[j]) {
        dist[j] = edge[i].first;
        q.push(j);
      } else
        dist[j] = 2e9;
    }
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int j = 1; j <= n; ++j)
        if (g[u][j] && dist[j] > dist[u] + 1) {
          dist[j] = dist[u] + 1;
          q.push(j);
        }
    }

    ans = min(ans, dist[n]);
  }
  if (ans >= 2e9) cout << "Impossible\n";
  else cout << ans << '\n';

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}