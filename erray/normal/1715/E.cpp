// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;


template<typename T, bool MAX = false, typename R = T>
struct LiChaoTree {
  using F = pair<R, R>;
  struct node {
    T l, r;
    node *lv = NULL, *rv = NULL;
    F x;
  };

  R gen(F x, T p) {
    return x.second + x.first * p;
  }

  bool cmp(F x, F y, T p) {
    return (gen(x, p) < gen(y, p)) ^ MAX;
  }

  node *root;
  LiChaoTree(T l, T r) {
    root = new node();
    root->l = l;
    root->r = r;
  }

  void add(node* v, F x) {
    T mid = (v->l + v->r) >> 1;
    if (cmp(x, v->x, mid)) {
      swap(x, v->x);
    }
    if (v->l == v->r) {
      return;
    }

    if (cmp(x, v->x, v->l)) {
      if (v->lv == NULL) {
        v->lv = new node();
        v->lv->l = v->l;
        v->lv->r = mid;
        v->lv->x = x;
      } else {
        add(v->lv, x);
      }
    } else {
      if (v->rv == NULL) {
        v->rv = new node();
        v->rv->l = mid + 1;
        v->rv->r = v->r;
        v->rv->x = x;
      } else {
        add(v->rv, x);        
      }
    }
  }

  R best(R& x, const R& y) {
    return x = ((x < y) ^ MAX ? x : y);
  }

  R get(node* v, T p) {
    R res = gen(v->x, p);
    T mid = (v->l + v->r) >> 1;
    if (p <= mid) {
      if (v->lv != NULL) {
        best(res, get(v->lv, p));
      }
    } else {
      if (v->rv != NULL) {
        best(res, get(v->rv, p));
      }
    }
    return res;
  }

  bool first = true;
  void add(F x) {
    if (first) {
      root->x = x;
      first = false;
    } else {
      add(root, x);
    }
  }

  void add(R x, R y) {
    add(F{x, y});
  }

  R get(T x) {
    assert(!first && x >= root->l && x <= root->r);
    return get(root, x);
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<array<int, 2>>> g(N);
  for (int i = 0; i < M; ++i) {
    int V, U, W;
    cin >> V >> U >> W;
    --V, --U;
    g[V].push_back({U, W});
    g[U].push_back({V, W});
  }
  const long long inf = (long long) 1e17;
  vector<long long> dist(N, inf);
  dist[0] = 0;
  auto Djikstra = [&] {
    using T = pair<long long, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    for (int i = 0; i < N; ++i) {
      pq.emplace(dist[i], i);
    }
    while (!pq.empty()) {
      auto[d, v] = pq.top();
      pq.pop();
      if (d > dist[v]) {
        continue;
      }
      for (auto[u, w] : g[v]) {
        if (dist[u] > dist[v] + w) {
          dist[u] = dist[v] + w;
          pq.emplace(dist[u], u);
        }
      }
    }
  };
  for (int it = 0; it < K; ++it) {
    Djikstra();
    LiChaoTree<long long> lct(0, N - 1);
    for (int i = 0; i < N; ++i) {
      lct.add(-2 * i, dist[i] + 1LL * i * i); 
    }
    for (int i = 0; i < N; ++i) {
      dist[i] = lct.get(i) + 1LL * i * i;
    }
  }
  Djikstra();
  for (int i = 0; i < N; ++i) {
    cout << dist[i] << " \n"[i == N - 1];
  }
}