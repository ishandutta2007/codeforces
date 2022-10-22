// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <assert.h>
#include <iomanip>

using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
// #define int ll
 
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
// vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
// const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

template <typename T>
class SegmentTree {
public:
  using F = function<T(T&, T&)>;
  int n;
  vector<T > dat;
  T e; // P
  F query_func;
  F update_func;
  
  SegmentTree(vector<T> a, F query_func, F update_func, T e) :n(a.size()), query_func(query_func), update_func(update_func), e(e) {
    dat.resize(4 * n);
    init(0, 0, n, a);
  }

  void init(int k, int l, int r, vector<T> &a) {
    if (r - l == 1) {
      dat[k] = a[l];
    }
    else {
      int lch = 2 * k + 1, rch = 2 * k + 2;
      init(lch, l, (l + r) / 2, a);
      init(rch, (l + r) / 2, r, a);
      dat[k] = query_func(dat[lch], dat[rch]);
    }
  }

  //klaX
  void update(int k, T a, int v, int l, int r) {
    if (r - l == 1) {
      dat[v] = update_func(dat[v], a);
    }
    else {
      if (k < (l + r) / 2)
        update(k, a, 2 * v + 1, l, (l + r) / 2);
      else {
        update(k, a, 2 * v + 2, (l + r) / 2, r);
      }
      dat[v] = query_func(dat[v * 2 + 1], dat[v * 2 + 2]);
    }
  }
    

  //[a,b)l
  //vZP
  //k_,l,r_[l,r)\
  //]AOquery(a,b,0,0,n)
  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) {
      return e;
    }
    if (a <= l && r <= b) {
      return dat[k];
    }
    else {
      T ul = query(a, b, k * 2 + 1, l, (l + r) / 2);
      T ur = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return query_func(ul, ur);
    }
  }

  // ET
  int find(int a, int b, int k, int l, int r, int x) {
    // 
    if (dat[k] < x || r <= a || b <= l) return -1;
    if (l + 1 == r) {
      // 
      if (dat[k] >= x) return l;
      else return -1;
    }
    int rv = find(a, b, 2 * k + 2, (l + r) / 2, r, x);
    if (rv != -1) return rv;
    return find(a, b, 2 * k + 1, l, (l + r) / 2, x);
  }
};

class RangeEdges {
    // https://twitter.com/noshi91/status/1193177214453338113
    public:
    int n; // 
    int V; // 
    vector<vector<pll>> G;

    // 0 ~ n - 1: 
    // n, n + 2, n + 4, ..., n + 2 * (K - 1): out
    // n + 1, n + 3, ..., n + 2 * K - 1: in
    // n + 2 * K ~ 

    RangeEdges(int n): n(n), V(n) {
        G.resize(9 * n);
        init(0, 0, n);
    }

    void init(int k, int l, int r) {
        if (r - l == 1) {
            G[n + 2 * k].push_back(pll(0, l));
            G[l].push_back(pll(0, n + 2 * k + 1));
            chmax(V, n + 2 * k + 2);
            return;
        }

        int lch = 2 * k + 1, rch = 2 * k + 2;
        G[n + 2 * k].push_back(pll(0, n + 2 * lch));
        G[n + 2 * k].push_back(pll(0, n + 2 * rch));
        G[n + 2 * lch + 1].push_back(pll(0, n + 2 * k + 1));
        G[n + 2 * rch + 1].push_back(pll(0, n + 2 * k + 1));
        init(lch, l, (l + r) / 2);
        init(rch, (l + r) / 2, r);
    }

    void get_ranges(int a, int b, int k, int l, int r, vector<int>& res) {
        if (r <= a || b <= l) {
            return;
        }
        if (a <= l && r <= b) {
            res.push_back(k);
            return;
        }
        else {
            get_ranges(a, b, k * 2 + 1, l, (l + r) / 2, res);
            get_ranges(a, b, k * 2 + 2, (l + r) / 2, r, res);
            return;
        }
    }

    // [lr1.first, lr1.second) -> [lr2.first, lr2.second)cost
    void add_edge(pii lr1, pii lr2, ll cost) {
        vector<int> in_ranges;
        get_ranges(lr1.first, lr1.second, 0, 0, n, in_ranges);
        rep (i, in_ranges.size()) in_ranges[i] = n + in_ranges[i] * 2 + 1;
        vector<int> out_ranges;
        get_ranges(lr2.first, lr2.second, 0, 0, n, out_ranges);
        rep (i, out_ranges.size()) out_ranges[i] = n + out_ranges[i] * 2;
        // DEBUG_VEC(in_ranges);
        // DEBUG_VEC(out_ranges);

        V += 2;
        while (G.size() < V) G.push_back(vector<pll>());

        for (int u: in_ranges) {
            G[u].push_back(pll(0, V - 2));
        }
        G[V - 2].push_back(pll(cost, V - 1));
        for (int v: out_ranges) {
            G[V - 1].push_back(pll(0, v));
        }
    }

    vl dijkstra(int s) {
        vl dist(V, INF);
        dist[s] = 0;
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push(pll(0, s));
        while (pq.size()) {
            pll temp = pq.top();
            pq.pop();
            int u = temp.second;
            ll cost = temp.first;
            if (dist[u] < cost) continue;
            rep (i, G[u].size()) {
                int v = G[u][i].second;
                ll ncost = cost + G[u][i].first;
                if (dist[v] > ncost) {
                    dist[v] = ncost;
                    pq.push(pll(ncost, v));
                }
            }
        }

        dist.resize(n);
        return dist;
    }    
};


signed main() {
    fio();
    
    int n, q, s;
    cin >> n >> q >> s;
    s--;

    RangeEdges graph(n);

    // DEBUG_MAT(graph.G);
    while (q--) {
        int type;
        cin >> type;
        pll lr1, lr2;
        ll w;
        if (type == 1) {
            ll v, u;
            cin >> v >> u >> w;
            lr1 = pll(v - 1, v);
            lr2 = pll(u - 1, u);
        }
        else {
            ll v, l, r;
            cin >> v >> l >> r >> w;
            if (type == 2) {
                lr1 = pll(v - 1, v);
                lr2 = pll(l - 1, r);
            }
            else {
                lr1 = pll(l - 1, r);
                lr2 = pll(v - 1, v);
            }
        }

        graph.add_edge(lr1, lr2, w);
        // DEBUG(graph.V);
    }

    vl ans = graph.dijkstra(s);
    rep (i, n) {
        if (ans[i] == INF) ans[i] = -1;
        cout << ans[i] << " ";
    }
    cout << endl;
}