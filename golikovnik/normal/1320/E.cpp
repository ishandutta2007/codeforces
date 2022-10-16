//  Copyright 2020 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef GOLIKOV
mt19937_64 rng(566);
#else
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif

template <typename T>
T rnd_helper(T from, T to, true_type) {
  return uniform_int_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd_helper(T from, T to, false_type) {
  return uniform_real_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd(T from, T to) {
  return rnd_helper(from, to, is_integral<T>{});
}

template <typename A, typename B, typename Cmp>
bool set_min(A& x, B const& y, Cmp&& cmp) {
  if (cmp(y, x)) {
    x = y;
    return true;
  }
  return false;
}

template <typename A, typename B>
bool set_min(A& x, B const& y) {
  return set_min(x, y, less<>{});
}

template <typename A, typename B>
bool set_max(A& x, B const& y) {
  return set_min(x, y, greater<>{});
}

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

template <typename K, typename V> using hash_map = gp_hash_table<K, V>;

template <typename T> using hash_set = gp_hash_table<T, null_type>;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> graph(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int const LOG = 18;
  vector<vector<int>> up(n, vector<int>(LOG));
  vector<int> tin(n), tout(n);
  vector<int> dep(n);
  int timer = 0;
  function<void(int, int)> dfs = [&](int v, int p) {
    dep[v] = dep[p] + 1;
    tin[v] = timer++;
    up[v][0] = p;
    for (int k = 0; k + 1 < LOG; ++k) {
      up[v][k + 1] = up[up[v][k]][k];
    }
    for (auto u : graph[v]) {
      if (u != p) {
        dfs(u, v);
      }
    }
    tout[v] = timer;
  };
  dfs(0, 0);
  auto anc = [&](int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
  };
  auto lca = [&](int v, int u) {
    if (anc(v, u)) return v;
    for (int k = LOG - 1; k >= 0; --k) {
      auto pv = up[v][k];
      if (!anc(pv, u)) v = pv;
    }
    return up[v][0];
  };
  int qs;
  cin >> qs;
  while (qs--) {
    int nviruses, nvertices;
    cin >> nviruses >> nvertices;
    vector<int> viruses(nviruses);
    vector<int> speed(nviruses);
    vector<int> vertices(nvertices);
    vector<int> vs;
    vs.reserve(nviruses + nvertices);
    for (int i = 0; i < nviruses; ++i) {
      cin >> viruses[i] >> speed[i];
      --viruses[i];
      vs.push_back(viruses[i]);
    }
    for (int i = 0; i < nvertices; ++i) {
      cin >> vertices[i];
      --vertices[i];
      vs.push_back(vertices[i]);
    }
    auto by_time = [&](int v, int u) {
      return tin[v] < tin[u];
    };
    auto fix = [&] {
      sort(vs.begin(), vs.end(), by_time);
      vs.erase(unique(vs.begin(), vs.end()), vs.end());
    };
    fix();
    auto nvs = (int) vs.size();
    for (int i = 0; i + 1 < nvs; ++i) {
      vs.push_back(lca(vs[i], vs[i + 1]));
    }
    fix();
    nvs = (int) vs.size();
    auto norm = [&](auto& vec) {
      for (auto& x : vec) {
        x = lower_bound(vs.begin(), vs.end(), x, by_time) - vs.begin();
      }
    };
    norm(vertices);
    norm(viruses);
    vector<vector<pair<int, int>>> tree(nvs);
    vector<int> st{0};
    for (int i = 1; i < nvs; ++i) {
      auto v = vs[i];
      while (!anc(vs[st.back()], v)) st.pop_back();
      auto w = dep[v] - dep[vs[st.back()]];
      tree[st.back()].emplace_back(i, w);
      tree[i].emplace_back(st.back(), w);
      st.push_back(i);
    }

    struct dist_t {
      int time;
      int tp;
      int full;
      int v;

      dist_t() {}
      dist_t(int v) : time(-1), tp(-1), full(-1), v(v) {}
      dist_t(int full, int time, int tp, int v) : time(time),
        tp(tp), full(full), v(v) {}
      dist_t(int v, int w, int sp, dist_t dst) : time(dst.time + w),
        tp(dst.tp), full((time + sp - 1) / sp), v(v) {}

      bool operator<(dist_t const& other) const {
        return other.full < 0 ||
        tie(full, tp, time, v) < tie(other.full, other.tp, other.time, other.v);
      }
    };

    vector<dist_t> dist(nvs);
    iota(dist.begin(), dist.end(), 0);

    set<dist_t> q;
    for (int i = 0; i < nviruses; ++i) {
      auto v = viruses[i];
      dist[v] = {0, 0, i, v};
      q.insert(dist[v]);
    }

    while (!q.empty()) {
      auto dst = *q.begin();
      q.erase(q.begin());

      for (auto[u, w] : tree[dst.v]) {
        dist_t new_dist{u, w, speed[dst.tp], dst};
        if (new_dist < dist[u]) {
          q.erase(dist[u]);
          dist[u] = new_dist;
          q.insert(new_dist);
        }
      }
    }
    for (int i = 0; i < nvertices; ++i) {
      cout << dist[vertices[i]].tp + 1 << ' ';
    }
    cout << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
          chrono::high_resolution_clock::now() - _clock_start).count() << "ms."
       << endl;
#endif
  return 0;
}