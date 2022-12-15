#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

const int mod = 998244353;

const int inf = 0x3f3f3f3f3f3f3f3f;
const int ms = 2e5+5;

int fExp(int a, int b) {
  int ans = 1;
  while(b) {
    if(b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

class HLD {
public:
  vector<int> in, out, p, rin, sz, nxt, h;
  vector<vector<int>> edges;
  void init(int n) {
    // this doesn't delete edges!
    sz.resize(n);
    in.resize(n);
    out.resize(n);
    rin.resize(n);
    p.resize(n);
    edges.resize(n);
    nxt.resize(n);
    h.resize(n);
  }

  void addEdge(int u, int v) {
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  void setRoot(int n) {
    t = 0;
    p[n] = n;
    h[n] = 0;
    prep(n, n);
    nxt[n] = n;
    hld(n);
  }

  int getLCA(int u, int v) {
    while(!inSubtree(nxt[u], v)) {
      u = p[nxt[u]];
    }
    while(!inSubtree(nxt[v], u)) {
      v = p[nxt[v]];
    }
    return in[u] < in[v] ? u : v;
  }

  bool inSubtree(int u, int v) {
    // is v in the subtree of u?
    return in[u] <= in[v] && in[v] < out[u];
  }

  vector<pair<int, int>> getPathtoAncestor(int u, int anc) {
    // returns ranges [l, r) that the path has
    vector<pair<int, int>> ans;
    //assert(inSubtree(anc, u));
    while(nxt[u] != nxt[anc]) {
      ans.emplace_back(in[nxt[u]], in[u]);
      u = p[nxt[u]];
    }
    // this includes the ancestor!
    ans.emplace_back(in[anc], in[u]);
    return ans;
  }
private:
  int t;

  void prep(int on, int par) {
    sz[on] = 1;
    p[on] = par;
    for(int i = 0; i < (int) edges[on].size(); i++) {
      int &u = edges[on][i];
      if(u == par) {
        swap(u, edges[on].back());
        edges[on].pop_back();
        i--;
      } else {
        h[u] = 1 + h[on];
        prep(u, on);
        sz[on] += sz[u];
        if(sz[u] > sz[edges[on][0]]) {
          swap(edges[on][0], u);
        }
      }
    }
  }

  void hld(int on) {
    in[on] = t++;
    rin[in[on]] = on;
    for(auto u : edges[on]) {
      nxt[u] = (u == edges[on][0] ? nxt[on] : u);
      hld(u);
    }
    out[on] = t;
  }
};

int n, t[2 * ms], q;

void update(int p, int value) { // set value at position p
  p += n+1;
  for(t[p] = (t[p] + value) % mod; p > 1; p >>= 1) t[p>>1] = (t[p] + t[p^1]) % mod; // Merge
}

int query(int l, int r) {
  int res = 0;
  for(l += n+1, r += n+2; l < r; l >>= 1, r >>= 1) {
    if(l&1) res = (res  + t[l++]) % mod; // Merge
    if(r&1) res = (res + t[--r]) % mod; // Merge
  }
  return res;
}


HLD hld;
int lazy[ms];
int msz[ms];
int mtotal[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cin >> n >> q;
  int in = fExp(n, mod - 2);
  hld.init(n+1);
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    // cout << "adicionando " << u << " - > " << v << endl;
    hld.addEdge(u, v);
  }
  hld.setRoot(1);
  for(int i = 1; i <= n; i++) {
    msz[hld.in[i]] = hld.sz[i]*in%mod;
    mtotal[i] = (n-hld.sz[i])*in%mod;
    // cout << "= " << hld.in[i] << endl;
  }
  int total = 0;
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      int v, d;
      cin >> v >> d;
      int temp = (d*mtotal[v]%mod);
      total = (total + d + mod - temp) % mod;
      update(hld.in[v], temp);
      lazy[hld.in[v]] = (lazy[hld.in[v]] + d) % mod;
      if(hld.edges[v].size() > 0) {
        update(hld.in[hld.edges[v][0]], mod - (msz[hld.in[hld.edges[v][0]]]*d) % mod);
      }
    } else {
      int v;
      cin >> v;
      auto ans = hld.getPathtoAncestor(v, 1);
      int cur = total;
      for(int i = 0; i < ans.size(); i++) {
        // cout << "dbg: " << ans[i].first << ' ' << ans[i].second << endl;
        cur = (cur + query(ans[i].first, ans[i].second)) % mod;
        if(i + 1 != ans.size()) {
          cur = ((cur - msz[ans[i].first] * lazy[ans[i+1].second]) % mod + mod) % mod;
        }
      }
      cout << cur << '\n';
    }
  }
}