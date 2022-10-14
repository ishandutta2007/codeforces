#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma 03

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

//I REALLY can't be bothered to debug that mess of a solution so I'll just take tourist's template instead
//why not
template <typename T>
class graph {
 public:
  struct edge {
    int from;
    int to;
    T cost;
  };

  vector<edge> edges;
  vector<vector<int>> g;
  int n;

  graph(int _n) : n(_n) {
    g.resize(n);
  }

  virtual int add(int from, int to, T cost) = 0;
};

template <typename T>
class undigraph : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  undigraph(int _n) : graph<T>(_n) {
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

template <typename T>
vector<int> find_eulerian_path(const graph<T> &g, int &root) {
  vector<int> in_deg(g.n, 0);
  vector<int> out_deg(g.n, 0);
  int cnt_edges = 0;
  for (int id = 0; id < (int) g.edges.size(); id++) {
    cnt_edges++;
    auto &e = g.edges[id];
    out_deg[e.from]++;
    in_deg[e.to]++;
  }
  root = -1;
  int odd = 0;
  for (int i = 0; i < g.n; i++) {
    if ((in_deg[i] + out_deg[i]) % 2 == 1) {
      odd++;
      if (root == -1 || out_deg[i] - in_deg[i] > out_deg[root] - in_deg[root]) {
        root = i;
      }
    }
  }
  if (odd > 2) {
    root = -1;
    return vector<int>();
  }
  if (root == -1) {
    root = 0;
    while (root < g.n && in_deg[root] + out_deg[root] == 0) {
      root++;
    }
    if (root == g.n) {
      root = 0;
      return vector<int>();
    }
  }
  vector<bool> used(g.edges.size(), false);
  vector<int> ptr(g.n, 0);
  vector<int> balance(g.n, 0);
  vector<int> res(cnt_edges);
  int stack_ptr = 0;
  int write_ptr = cnt_edges;
  int v = root;
  while (true) {
    bool found = false;
    while (ptr[v] < (int) g.g[v].size()) {
      int id = g.g[v][ptr[v]++];
      if (used[id]) {
        continue;
      }
      used[id] = true;
      res[stack_ptr++] = id;
      auto &e = g.edges[id];
      balance[v]++;
      v ^= e.from ^ e.to;
      balance[v]--;
      found = true;
      break;
    }
    if (!found) {
      if (stack_ptr == 0) {
        break;
      }
      int id = res[--stack_ptr];
      res[--write_ptr] = id;
      auto &e = g.edges[id];
      v ^= e.from ^ e.to;
    }
  }
  int disbalance = 0;
  for (int i = 0; i < g.n; i++) {
    disbalance += abs(balance[i]);
  }
  if (write_ptr != 0 || disbalance > 2) {
    root = -1;
    return vector<int>();
  }
  return res;
  // returns edge ids in the path (or the cycle if it exists)
  // root == -1 if there is no path
  // (or res.empty(), but this is also true when there are no edges)
}

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int32_t main() {
    fastio;
    int n; cin>>n;
    int a[n], b[n]; rep(i, n) cin>>a[i]>>b[i];
    for(int i=20; i>=0; i--) {
        int msk=(1<<i)-1;
        vi deg(msk+1, 0);
        dsu D(msk+1);
        rep(i, n) {
            int u=a[i]&msk, v=b[i]&msk;
            D.unite(u, v);
            deg[u]++; deg[v]++;
        }
        bool ok=1;
        rep(i, msk+1) if(deg[i]&1) {ok=0; break;}
        if(!ok) continue;
        int z=-1;
        rep(i, msk+1) if(deg[i]) {
            int x=D.get(i);
            if (z==-1) z=x;
            else if (z!=x) {ok=0; break;}
        }
        if(!ok) continue;
        undigraph<int> g(msk+1);
        rep(i, n) g.add(a[i]&msk, b[i]&msk);
        int root;
        auto path=find_eulerian_path(g, root);
        cout<<i<<endl;
        rep(i, n) {
            int j=path[i], u=a[j]&msk, v=b[j]&msk;
            if(u==root) {
                cout<<2*j+1<<' '<<2*j+2<<' ';
                root=v;
            }
            else {
                cout<<2*j+2<<' '<<2*j+1<<' ';
                root=u;
            }
        }
        cout<<endl; break;
    }
    return 0;
}