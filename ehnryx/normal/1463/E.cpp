//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1 << 19;
int p[N], path[N], deg[N];
vector<int> adj[N], dag[N];
int pre[N], post[N], sz[N];

int build(int u) {
  pre[u] = pre[0]++;
  sz[u] = 1;
  for(int v : adj[u]) {
    sz[u] += build(v);
  }
  post[u] = post[0]++;
  return sz[u];
}

bool is_anc(int a, int b) {
  return pre[a] < pre[b] && post[a] > post[b];
}

int dsu[N];
int find(int i) {
  if(dsu[i] == 0) return i;
  return dsu[i] = find(dsu[i]);
}
bool link(int i, int j) {
  i = find(i);
  j = find(j);
  if(i == j) return false;
  dsu[i] = j;
  return true;
}

int st[2*N];
void insert(int x, int v) {
  st[x+=N] = v;
  for(x/=2; x>0; x/=2) {
    st[x] = st[x<<1] + st[x<<1|1];
  }
}
int query(int l, int r) {
  int res = 0;
  for(l+=N, r+=N; l<r; l/=2, r/=2) {
    if(l&1) res += st[l++];
    if(r&1) res += st[--r];
  }
  return res;
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  int n, m;
  cin >> n >> m;
  int root = 0;
  for(int i=1; i<=n; i++) {
    cin >> p[i];
    if(p[i] == 0) {
      root = i;
    } else {
      adj[p[i]].push_back(i);
    }
  }
  build(root);

  for(int i=0; i<m; i++) {
    int a, b;
    cin >> a >> b;
    path[a] = b;
    bool bad = false;
    bad |= !link(b, a);
    bad |= is_anc(b, a);
    bad |= is_anc(a, b) && p[b] != a;
    if(bad) {
      cout << 0 << nl;
      return 0;
    }
  }

  for(int i=1; i<=n; i++) {
    if(p[i] == 0) {
      root = find(i);
    } else if(find(p[i]) != find(i)) {
      dag[find(p[i])].push_back(find(i));
      deg[find(i)]++;
    }
  }

  vector<int> out;
  queue<int> bfs;
  if(deg[root] == 0) bfs.push(root);
  while(!bfs.empty()) {
    int u = bfs.front();
    bfs.pop();
    for(int v : dag[u]) {
      if(--deg[v] == 0) {
        bfs.push(v);
      }
    }
    if(!query(pre[u], pre[u]+sz[u])) out.push_back(u);
    insert(pre[u], 1);
    while(path[u]) {
      u = path[u];
      if(!query(pre[u], pre[u]+sz[u])) out.push_back(u);
      insert(pre[u], 1);
    }
  }

  if(out.size() < n) {
    cout << 0 << nl;
  } else {
    for(int it : out) {
      cout << it << " ";
    }
    cout << nl;
  }

  return 0;
}