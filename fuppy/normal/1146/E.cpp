#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}


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
const ll INF = (ll)1e18 + 1;
//const ll MOD = 1000000007;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { -1,0, 1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair

template <typename T1, typename T2>
class LazySegmentTree {
public:
  using F = function<T1(T1&, T1&)>; // query_func
  using G = function<T2(T2&, T2&)>; // update_func
  using H = function<T1(T1&, T2&, int, int)>; // lazy to node (node, lazy, left, right)
  int n;
  vector<T1> node;
  vector<T2> lazy;
  T1 e1;
  T2 e2;
  F query_func;
  G update_func;
  H eval_func;

  LazySegmentTree(vector<T1> a, F query_func, G update_func, H eval_func, T1 e1, T2 e2)
    :query_func(query_func), update_func(update_func), eval_func(eval_func), e1(e1), e2(e2)
  {
    int _n = a.size();
    n = 1; while (n < _n) n *= 2;
    node.resize(2 * n - 1, e1);
    lazy.resize(2 * n - 1, e2);
    for (int i = 0; i < _n; i++) node[i + n - 1] = a[i];
    for (int i = n - 2; i >= 0; i--) {
      node[i] = query_func(node[i * 2 + 1], node[i * 2 + 2]);
    }
  }

  // k
  inline void eval(int k, int l, int r) {
    node[k] = eval_func(node[k], lazy[k], l, r);
    if (r - l > 1) {
      lazy[2 * k + 1] = update_func(lazy[2*k + 1], lazy[k]);
      lazy[2 * k + 2] = update_func(lazy[2*k + 2], lazy[k]);
    }
    lazy[k] = e2; // Change
  }

  // [a, b)x
  void update(int a, int b, T2 x, int k, int l, int r) {
    // k 
    eval(k, l, r);
    if (b <= l || r <= a) return;
    if (a <= l && r <= b) {
      lazy[k] = update_func(lazy[k], x);
      eval(k, l, r);
    }
    else {
      update(a, b, x, 2 * k + 1, l, (l + r) / 2);
      update(a, b, x, 2 * k + 2, (l + r) / 2, r);
      node[k] = query_func(node[2 * k + 1], node[2 * k + 2]);
    }
  }

  T1 query(int a, int b, int k, int l, int r) {
    eval(k, l, r);
    if (b <= l || r <= a) return e1;
    if (a <= l && r <= b) return node[k];
    T1 resl = query(a, b, 2 * k + 1, l, (l + r) / 2);
    T1 resr = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return query_func(resl, resr);
  }
};

int f1(int a, int b) {return max(a, b);}
int f2(int a, int b) {
  if (b == 0) {
    a = a;
  }
  else if (b == 1) {
    a ^= 1;
  }
  else {
    a = b;
  }
  return a;
}
int f3(int a, int b, int l, int r) {
  if (b == 0) {
    a = a;
  }
  else if (b == 1) {
    a ^= 1;
  }
  else {
    a = b;
  }
  return a;
}

int main() {
  int n, q;
  cin >> n >> q;
  vi a(n);
  rep (i, n) {
    cin >> a[i];
  }
  int m = 100010;
  
  LazySegmentTree<int, int> seg(vi(m), f1, f2, f3, -inf, 0);
  rep (i, q) {
    char c;
    int x;
    cin >> c >> x;
    if (c == '>') {
      if (x >= 0) {
        seg.update(x + 1, seg.n, 3, 0, 0, seg.n);
      }
      else {
        seg.update(-x, seg.n, 3, 0, 0, seg.n);
        seg.update(0, -x, 1, 0, 0, seg.n);
      }
    }
    else {
      if (x >= 0) {
        seg.update(x, seg.n, 2, 0, 0, seg.n);
        seg.update(0, x, 1, 0, 0, seg.n);
      }
      else {
        seg.update(-x + 1, seg.n, 2, 0, 0, seg.n);
      }
    }
    rep (i, 6) {
      //cout << seg.query(i, i + 1, 0, 0, seg.n) << " ";
    }
    //cout << endl;
  }

  rep (i, n) {
    int f = seg.query(abs(a[i]), abs(a[i]) + 1, 0, 0, seg.n);
    if (f == 0) {
      cout << a[i];
    }
    else if (f == 1) {
      cout << -a[i];
    }
    else if (f == 2) {
      cout << abs(a[i]);
    }
    else {
      cout << -abs(a[i]);
    }
    cout << " ";
  }
  cout << endl;
}