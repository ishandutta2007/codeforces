/*
 * author:  ADMathNoob
 * created: 05/02/21 10:34:14
 * problem: https://codeforces.com/contest/1515/problem/F
 */

/*
g++ 1515F.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1515F.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wfatal-errors -O3


*/

#include <bits/stdc++.h>

using namespace std;

class Dsu {
 public:
  int n;
  vector<int> p;
  vector<int> sz;  // get that inverse Ackermann time complexity
  vector<int> v;   // version
  int comps;
  int ver;

  Dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    sz.resize(n, 1);
    v.resize(n, 0);
    comps = n;
    ver = 0;
  }

  inline int get(int x) {
    if (v[x] != ver) {
      p[x] = x;
      sz[x] = 1;
      v[x] = ver;
    }
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool same(int x, int y) {
    return (get(x) == get(y));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return false;
    }
    if (sz[x] > sz[y]) {
      swap(x, y);
    }
    p[x] = y;
    sz[y] += sz[x];
    --comps;
    return true;
  }

  inline void reset() {
    comps = n;
    ++ver;
  }
};

const int N = 300005;
const int M = 300005;

int n, m;
long long x;
int a[N];

vector<int> g[N];
int from[M], to[M];

int deg[N];
bool done[N];
vector<int> leaves;
vector<int> res;

void Solve(int sz) {
  if (sz == 1) {
    return;
  }
  assert(!leaves.empty());
  int v = leaves.back();
  leaves.pop_back();
  int not_done = 0;
  for (int id : g[v]) {
    int u = from[id] ^ to[id] ^ v;
    if (done[u]) {
      continue;
    }
    ++not_done;
    if (--deg[u] == 1) {
      leaves.push_back(u);
    }
    done[v] = true;
    if (a[v] + a[u] >= x) {
      a[u] += a[v] - x;
      res.push_back(id);
      Solve(sz - 1);
    } else {
      Solve(sz - 1);
      res.push_back(id);
    }
  }
  assert(not_done == 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long total = accumulate(a, a + n, 0LL);
  if (total < (n - 1) * x) {
    cout << "NO\n";
    return 0;
  }
  Dsu d(n);
  vector<int> tree_ids;
  for (int i = 0; i < m; i++) {
    cin >> from[i] >> to[i];
    --from[i];
    --to[i];
    if (!d.same(from[i], to[i])) {
      d.unite(from[i], to[i]);
      g[from[i]].emplace_back(i);
      g[to[i]].emplace_back(i);
      tree_ids.push_back(i);
    }
  }
  d.reset();
  for (int id : tree_ids) {
    assert(d.unite(from[id], to[id]));
  }
  for (int i = 0; i < n; i++) {
    deg[i] = (int) g[i].size();
    if (deg[i] == 1) {
      leaves.push_back(i);
    }
  }
  Solve(n);
  cout << "YES\n";
  for (int id : res) {
    cout << id + 1 << '\n';
  }
  return 0;
}