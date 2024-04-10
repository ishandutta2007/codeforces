//  Copyright 2022 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

struct line {
  ll k, b;

  ll apply(ll x) const {
    return k * x + b;
  }
};

//  first x0: y(x0) < x(x0)
ll inter(line x, line y) {
  assert(y.k < x.k);
  auto point = (y.b - x.b) / (x.k - y.k);
  while (x.apply(point) <= y.apply(point)) ++point;
  while (y.apply(point - 1) < x.apply(point - 1)) --point;
  return point;
}

//  slopes are non-increasing
struct cht_min {
  ll const INF = 1.1e16;
  vector<pair<line, ll>> lines;

  void add_line(line const& l) {
    if (!lines.empty() && lines.back().first.k == l.k) {
      if (lines.back().first.b <= l.b) return;
      lines.pop_back();
      if (!lines.empty()) {
        lines.back().second = INF;
      }
    }
    while (lines.size() >= 2) {
      auto x_my = inter(lines.back().first, l);
      auto x_they = inter(lines[lines.size() - 2].first, lines.back().first);
      if (x_my <= x_they) {
        lines.pop_back();
      } else {
        break;
      }
    }
    if (lines.empty()) {
      lines.emplace_back(l, INF);
    } else {
      auto x = inter(lines.back().first, l);
      lines.back().second = x;
      lines.emplace_back(l, INF);
    }
  }

  ll query(ll x) const {
    return upper_bound(lines.begin(), lines.end(), x, [](ll a, auto b) {
      return a < b.second;
    })->first.apply(x);
  }

  //  <x, y>: f(x) <= y, x -> min
  pair<ll, ll> findFirst(ll y) const {
    int left = -1;
    int right = int(lines.size()) - 1;
    while (left + 1 != right) {
      int middle = (left + right) / 2;
      auto value = lines[middle].first.apply(lines[middle].second - 1);
      if (value <= y) {
        right = middle;
      } else {
        left = middle;
      }
    }
    auto l = lines[right].first;
    auto point = (y - l.b) / l.k;
    while (l.apply(point) > y) ++point;
    while (l.apply(point - 1) <= y) --point;
    return make_pair(point, l.apply(point));
  }
};

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    graph[u].emplace_back(v, w);
    graph[v].emplace_back(u, w);
  }
  ll const INF = ll(1.1e16);
  vector<ll> dp(n, INF);
  dp[0] = 0;
  for (int lev = 0; lev <= k; ++lev) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    vector<bool> used(n);
    for (int v = 0; v < n; ++v) {
      pq.emplace(dp[v], v);
    }
    while (!pq.empty()) {
      auto[d, v] = pq.top(); pq.pop();
      if (used[v]) {
        continue;
      }
      used[v] = true;
      for (auto[u, w] : graph[v]) {
        if (dp[u] > dp[v] + w) {
          dp[u] = dp[v] + w;
          pq.emplace(dp[u], u);
        }
      }
    }
    if (lev == k) {
      break;
    }
    cht_min hull{};
    for (int v = 0; v < n; ++v) {
      hull.add_line(line{-2ll * v, ll(v) * v + dp[v]});   
    }
    for (int v = 0; v < n; ++v) {
      dp[v] = hull.query(v) + ll(v) * v;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << dp[i] << " \n"[i + 1 == n];
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}