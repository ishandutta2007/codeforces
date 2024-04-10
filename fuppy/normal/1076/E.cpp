#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl

typedef long long ll;
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
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = 1e18;
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair

class LazySegmentTree {
public:
  int n;
  vl node, lazy;

  LazySegmentTree(vl a) {
    int _n = a.size();
    n = 1; while (n < _n) n *= 2;
    node.resize(2 * n - 1);
    lazy.resize(2 * n - 1, 0);
    for (int i = 0; i < _n; i++) node[i + n - 1] = a[i];
    for (int i = n - 2; i >= 0; i--) {
      node[i] = node[i * 2 + 1] + node[i * 2 + 2];
    }
  }

  // k
  inline void eval(int k, int l, int r) {
    if (lazy[k] != 0) {
      node[k] += (r - l) * lazy[k]; /////
      if (r - l > 1) {
        lazy[2 * k + 1] += lazy[k]; /////
        lazy[2 * k + 2] += lazy[k]; /////
      }
      lazy[k] = 0;
    }
  }

  // [a, b)x
  void add(int a, int b, ll x, int k, int l, int r) {
    // k 
    eval(k, l, r);
    if (b <= l || r <= a) return;
    if (a <= l && r <= b) {
      lazy[k] += x;
      eval(k, l, r);
    }
    else {
      add(a, b, x, 2 * k + 1, l, (l + r) / 2);
      add(a, b, x, 2 * k + 2, (l + r) / 2, r);
      node[k] = node[2 * k + 1] + node[2 * k + 2];
    }
  }

  ll getsum(int a, int b, int k, int l, int r) {
    eval(k, l, r);
    if (b <= l || r <= a) return 0;
    if (a <= l && r <= b) return node[k];
    ll resl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
    ll resr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
    return resl + resr;
  }
};


const int N = 300010;
vii G(N), tree(N);
vi parent(N, -1);
vi depth(N);
vector<vector<pll> > q(N);
vl ans(N);
vl tmp(N);
LazySegmentTree lst(tmp);

void dfs1(int now, int par) {
  parent[now] = par;
  rep (i, G[now].size()) {
    if (G[now][i] == par) continue;
    dfs1(G[now][i], now);
  }
}

void dfs2(int now, int depth) {
  //  DEBUG(now);
  //DEBUG(lst.getsum(depth, depth + 1, 0, 0, lst.n))
  rep (i, q[now].size()) {
    ll d = q[now][i].first, x = q[now][i].second;
    //DEBUG(depth); DEBUG(d); DEBUG(x);
    lst.add(depth, min(depth + d + 1, (ll)N), x, 0, 0, lst.n);
  }
  //DEBUG(lst.getsum(depth, depth + 1, 0, 0, lst.n))
  ans[now] = lst.getsum(depth, depth + 1, 0, 0, lst.n);
  rep (i, tree[now].size()) {
    dfs2(tree[now][i], depth + 1);
  }
  rep (i, q[now].size()) {
    ll d = q[now][i].first, x = q[now][i].second;
    lst.add(depth, min(depth + d + 1, (ll)N), -x, 0, 0, lst.n);
  }
}
  

int main() {
  int n;
  scanf(" %d", &n);
  rep (i, n - 1) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs1(0, -1);
  rep1 (i, n - 1) {
    tree[parent[i]].push_back(i);
  }
  rep (i, n) {
    sort(all(tree[i]));
  }
  int m;
  scanf("%d", &m);
  rep (i, m) {
    int u, d, x;
    scanf("%d %d %d", &u, &d, &x);
    u--;
    q[u].push_back(pll(d, x));
  }
  dfs2(0, 0);
  rep (i, n) {
    cout << ans[i] << " ";
  }
  cout << endl;
}