#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <tuple>
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

struct Node {
  int u, step;

  Node(int u, int step) : u(u), step(step) {}

  bool operator>(const Node& rhs) const { return step > rhs.step; }
};

const int N = 500010;

int n;
vector<tuple<int, int, int>> rg[N];
vector<int> hl[N][2], hr[N][2], dis[N][2];
vector<vector<tuple<int, int, int>>> adj[N][2];

void adde(int u, int v, int l, int r);
bool cmp(const tuple<int, int, int>& lhs, const tuple<int, int, int>& rhs) {
  if (get<1>(lhs) != get<1>(rhs))
    return get<1>(lhs) < get<1>(rhs);
  return get<2>(lhs) < get<2>(rhs);
}

int main() {

  int m;
  scanf("%d%d", &n, &m);
  while (m--) {
    int u, v, l, r;
    scanf("%d%d%d%d", &u, &v, &l, &r);
    adde(u, v, l, r);
    adde(v, u, l, r);
  }
  if (rg[1].empty()) {
    puts(n == 1 ? "0" : "-1");
  } else {
    for (int i = 1; i <= n; ++i) {
      sort(rg[i].begin(), rg[i].end(), cmp);
      for (int j = 0; j < 2; ++j) {
        for (const auto& tup : rg[i]) {
          int l, r;
          tie(ignore, l, r) = tup;
          if ((l & 1) != j)
            ++l;
          if ((r & 1) != j)
            --r;
          if (l > r)
            continue;
          if (hl[i][j].empty() || hr[i][j].back() < l) {
            hl[i][j].push_back(l);
            hr[i][j].push_back(r);
            adj[i][j].push_back(vector<tuple<int, int, int>>(1, tup));
          } else {
            hr[i][j].back() = max(hr[i][j].back(), r);
            adj[i][j].back().push_back(tup);
          }
        }
        //LOG("%d: %lu\n", i, rg[i].size());

        dis[i][j] = vector<int>(hl[i][j].size(), -1);
      }
    }
    priority_queue<Node, vector<Node>, greater<Node>> q;
    int ans = -1;
    q.emplace(1, 0);
    while (!q.empty()) {
      Node tmp = q.top();
      q.pop();
      if (tmp.u == n) {
        ans = tmp.step;
        break;
      }
      int u = tmp.u, j = tmp.step & 1;
      int i = int(upper_bound(hl[u][j].begin(), hl[u][j].end(), tmp.step) - hl[u][j].begin()) - 1;
      if (i < 0 || hl[u][j][i] > tmp.step || dis[u][j][i] != -1 && (dis[u][j][i] <= tmp.step))
        continue;
      dis[u][j][i] = tmp.step;
      //LOG("TO %d %d\n", tmp.u, tmp.step);
      for (const auto& tup : adj[u][j][i]) {
        int v, l, r;
        tie(v, l, r) = tup;
        //LOG("CONSIDER %d->%d [%d %d]\n", u, v, l, r);
        if (r <= tmp.step)
          continue;
        int dist;
        if (l <= tmp.step)
          dist = tmp.step + 1;
        else {
          dist = (l - tmp.step + 1) / 2 * 2 + tmp.step;
          if (dist >= r)
            continue;
          ++dist;
        }
        q.emplace(v, dist);
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}

void adde(int u, int v, int l, int r) {
  rg[u].emplace_back(v, l, r);
}