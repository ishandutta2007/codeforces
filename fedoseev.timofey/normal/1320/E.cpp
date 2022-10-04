#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 2e5 + 7;
const int K = 20;

int tin[N], tout[N];
vector <int> g[N];
int go[K][N];
int h[N];

int timer = 0;

void dfs(int u, int p = 0) {
  tin[u] = timer++;
  go[0][u] = p;
  h[u] = h[p] + 1;
  for (int i = 1; i < K; ++i) go[i][u] = go[i - 1][go[i - 1][u]];
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  tout[u] = timer++;
}

bool anc(int a, int b) {
  return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
  if (anc(a, b)) return a;
  for (int i = K - 1; i >= 0; --i) {
    if (!anc(go[i][a], b)) {
      a = go[i][a];
    }
  }
  return go[0][a];
}

int dist(int a, int b) {
  return h[a] + h[b] - 2 * h[lca(a, b)];
}

bool cmp(int a, int b) {
  return tin[a] < tin[b];
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  for (int i = 0; i + 1 < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  int q;
  cin >> q;
  while (q--) {
    int k, m;
    cin >> k >> m;
    vector <int> v(k), s(k);
    vector <int> vr;
    for (int i = 0; i < k; ++i) {
      cin >> v[i] >> s[i];
      --v[i];
      vr.push_back(v[i]);
    }
    vector <int> intr(m);
    for (int i = 0; i < m; ++i) {
      cin >> intr[i];
      --intr[i];
      vr.push_back(intr[i]);
    }
    sort(vr.begin(), vr.end(), cmp);
    int sz = vr.size();
    for (int i = 0; i + 1 < sz; ++i) {
      vr.push_back(lca(vr[i], vr[i + 1]));
    }
    sort(vr.begin(), vr.end(), cmp);
    vr.resize(unique(vr.begin(), vr.end()) - vr.begin());
    auto get_id = [&] (int u) {
      return lower_bound(vr.begin(), vr.end(), u, cmp) - vr.begin();
    };

    int l = vr.size();
    vector <vector <int>> gr(l);
    vector <int> st;
    for (int x : vr) {
      while (!st.empty() && !anc(st.back(), x)) {
        st.pop_back();
      }
      if (!st.empty()) {
        gr[get_id(st.back())].push_back(get_id(x));
        gr[get_id(x)].push_back(get_id(st.back()));
      }
      st.push_back(x);
    }
    vector <pair <int, int>> d(l, make_pair((int)1e9, -1));
    set <pair <pair <int, int>, int>> q;
    vector <bool> used(l);
    for (int i = 0; i < k; ++i) {
      d[get_id(v[i])] = {0, i};
      q.insert({d[get_id(v[i])], get_id(v[i])});
      used[get_id(v[i])] = true;
    } 
    while (!q.empty()) {
      auto p = *q.begin();
      q.erase(q.begin());
      int u = p.second;
      used[u] = true;
      int who = d[u].second;
      for (int to : gr[u]) {
        if (used[to]) continue;
        pair <int, int> nd = make_pair((dist(v[who], vr[to]) + s[who] - 1) / s[who], who);
        if (nd < d[to]) {
          q.erase({d[to], to});
          d[to] = nd;
          q.insert({d[to], to});
        }
      }
    }
    for (int x : intr) {
      cout << d[get_id(x)].second + 1 << ' ';
    }
    cout << '\n';
  }
}