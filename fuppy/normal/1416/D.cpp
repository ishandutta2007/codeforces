#include <bits/stdc++.h>

// #include <atcoder/all>

using namespace std;
// using namespace atcoder;
 
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
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
// const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'



class UnionFind {
public:
  int n;
  vi par;
  vi num;
  int g;
 
  UnionFind(int _n) {
    n = _n;
    g = n;
    par.resize(n); num.resize(n);
    for (int i = 0; i < n; i++) {
      par[i] = i; num[i] = 1;
    }
  }
 
  int find(int x) {
    if (par[x] == x) {
      return x;
    }
    else {
      return par[x] = find(par[x]);
    }
  }

  int which(int x, int y) {
      x = find(x); y = find(y);
      if (num[x] < num[y]) return x;
      else return y;
  }
 
  void unite(int x, int y) {
    x = find(x); y = find(y);
    int numsum = num[x] + num[y];
    if (x == y) {
      return;
    }
    if (num[x]<num[y]) {
      par[x] = y;
    }
    else {
      par[y] = x;
    }
    num[x] = num[y] = numsum;
    g--;
  }
 
  bool same(int x, int y) {
    return find(x) == find(y);
  }
};


signed main() {
    fio();
    int n, m, q;
    cin >> n >> m >> q;
    vi p(n);
    vi score2idx(n + 1);
    rep (i, n) {
        cin >> p[i];
        score2idx[p[i]] = i;
    }
    vector<pii> edges(m);
    rep (i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[i] = pii(u, v);
    }

    vector<pii> query(q);
    vector<bool> del(m);
    rep (i, q) {
        int t, v;
        cin >> t >> v;
        v--;
        query[i] = pii(t, v);
        if (t == 2) {
            del[v] = true;
        }
    }
    UnionFind uf(n);
    rep (i, m) {
        if (not del[i]) {
            uf.unite(edges[i].first, edges[i].second);
        }
    }

    vii merge(q);
    vector<pii> merge_to(q);
    vector<set<int>> st(n);
    vi position(n);
    rep (i, n) {
        int root = uf.find(i);
        st[root].insert(p[i]);
        position[i] = root;
    }

    rrep (i, q) {
        if (query[i].first == 1) continue;
        int idx = query[i].second;
        int u = edges[idx].first, v = edges[idx].second;
        u = uf.find(u); v = uf.find(v);
        if (uf.same(u, v)) continue;

        int die_root = uf.which(u, v);
        int new_root;
        if (die_root == u) new_root = v;
        else new_root = u;
        int die_idx = die_root;
        int new_idx = new_root;
        while (st[die_idx].size() > 0) {
            auto itr = st[die_idx].begin();
            merge[i].push_back(*itr);
            st[new_idx].insert(*itr);
            int u = score2idx[*itr];
            position[u] = new_idx;
            st[die_idx].erase(itr);
        }

        merge_to[i] = pii(new_idx, die_idx);
        uf.unite(u, v);
    }

    rep (i, q) {
        // DEBUG_VEC(position);
        // rep (i, cnt) {
        //     DEBUG(st[i].size());
        // }
        if (query[i].first == 1) {
            int u = query[i].second;
            int pos = position[u];
            if (st[pos].size() == 0) {
                cout << 0 << '\n';
            }
            else {
                auto itr = st[pos].end();
                itr--;
                cout << *itr << '\n';
                st[pos].erase(itr);
            }
        }
        else {
            int old_idx = merge_to[i].first, new_idx = merge_to[i].second;
            for (int sc: merge[i]) {
                if (st[old_idx].count(sc)) {
                    st[old_idx].erase(sc);
                    st[new_idx].insert(sc);
                }
                int u = score2idx[sc];
                // assert(position[u] == old_idx);
                position[u] = new_idx;
            }
        }
    }
}