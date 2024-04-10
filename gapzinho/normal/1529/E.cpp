#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define double long double

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int ms = 3e5+5;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;



int n, t[2 * ms];

void build() {
  for(int i = n; i < 2*n; i++) t[i] = inf;
  for(int i = n - 1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]); // Merge
}

void update(int p, int value) { // set value at position p
  for(t[p += n] = value; p > 1; p >>= 1) t[p>>1] = min(t[p],t[p^1]); // Merge
}

int query(int l, int r) {
  int res = inf;
  for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if(l&1) res = min(res, t[l++]); // Merge
    if(r&1) res = min(res, t[--r]); // Merge
  }
  return res;
}


class HLD {
public:
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
    // edges[v].push_back(u);
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
      ans.emplace_back(in[nxt[u]], in[u] + 1);
      u = p[nxt[u]];
    }
    // this includes the ancestor!
    ans.emplace_back(in[anc], in[u] + 1);
    return ans;
  }
  pair<int,int> getSubtree(int u) {
      return {in[u], out[u]};
  }

  int getIn(int u) {
    //   return u;
    return in[u];
  }
private:
  vector<int> in, out, p, rin, sz, nxt, h;
  vector<vector<int>> edges;
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

vector<int> g[ms];

HLD hld;
int cur = 0;
int ans = 0;

int queryAncestor(int u) {
    auto v = hld.getPathtoAncestor(u, 0);
    int get = inf;
    for(auto e : v) {
        get = min(get, query(e.first, e.second));
    }
    return get;
}

int queryChild(int u) {
    auto v = hld.getSubtree(u);
    return query(v.first, v.second);
}

void solve(int u) {
    int toAncestor = queryAncestor(u);
    int child = queryChild(u);
    // cout << u+1 << " deu " << toAncestor+1 << ' ' << child+1 << endl;
    if(toAncestor < inf) {
        update(hld.getIn(toAncestor), inf);
        update(hld.getIn(u), u);
    } else if(child == inf) {
        update(hld.getIn(u), u);
        cur++;
    }
    // cout << "deu " << cur << endl;
    ans = max(ans, cur);
    // cout << ans << endl;
    for(int v : g[u]) {
        solve(v);
    }
    if(toAncestor < inf) {
        update(hld.getIn(u), inf);
        update(hld.getIn(toAncestor), toAncestor);
    } else if(child == inf) {
        update(hld.getIn(u), inf);
        cur--;
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        hld = HLD();
        hld.init(n);
        build();
        for(int i = 0; i < n; i++) g[i].clear();
        for(int i = 1; i < n; i++) {
            int p;
            cin >> p;
            g[p-1].emplace_back(i);
        }
        for(int i = 1; i < n; i++) {
            int u;
            cin >> u;
            hld.addEdge(u-1, i);
        }
        cur = 0;
        ans = 0;
        hld.setRoot(0);
        solve(0);
        cout << ans << '\n';
    }
    return 0;
}