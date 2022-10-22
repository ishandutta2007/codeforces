#include <bits/stdc++.h>

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
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'


using i64 = long long;

struct segment_tree_chminmaxadd_rsq {
  using T = i64;

  const T ide = 0;
  static const T INF = std::numeric_limits<T>::max();
  static const T NINF = std::numeric_limits<T>::min();

  struct node {
    T sum;
    T gst1, gst2, gcnt;
    T lst1, lst2, lcnt;
    i64 len;
    i64 add;
    node(): gst2(NINF), gcnt(1), lst2(INF), lcnt(1), len(1), add(0) {}
  };

  std::vector<node> v;

  i64 n;
  i64 h;

  inline void fix(int k) {
    node& p = v[k];
    node& l = v[k * 2 + 0];
    node& r = v[k * 2 + 1];
    p.sum = l.sum + r.sum;

    if(r.gst1 < l.gst1) {
      p.gst1 = l.gst1;
      p.gcnt = l.gcnt;
      p.gst2 = std::max(l.gst2, r.gst1);
    }
    else if(l.gst1 < r.gst1) {
      p.gst1 = r.gst1;
      p.gcnt = r.gcnt;
      p.gst2 = std::max(l.gst1, r.gst2);
    }
    else {
      p.gst1 = l.gst1;
      p.gcnt = l.gcnt + r.gcnt;
      p.gst2 = std::max(l.gst2, r.gst2);
    }

    if(r.lst1 > l.lst1) {
      p.lst1 = l.lst1;
      p.lcnt = l.lcnt;
      p.lst2 = std::min(l.lst2, r.lst1);
    }
    else if(l.lst1 > r.lst1) {
      p.lst1 = r.lst1;
      p.lcnt = r.lcnt;
      p.lst2 = std::min(l.lst1, r.lst2);
    }
    else {
      p.lst1 = l.lst1;
      p.lcnt = l.lcnt + r.lcnt;
      p.lst2 = std::min(l.lst2, r.lst2);
    }

  }

  segment_tree_chminmaxadd_rsq() {}
  segment_tree_chminmaxadd_rsq(const std::vector<i64>& vec) {
    n = 1;
    h = 1;
    while(n < vec.size()) n <<= 1, h++;
    v.resize(2 * n);
    for(i64 i = 0;i < vec.size();i++) {
      v[i + n].sum = vec[i];
      v[i + n].gst1 = vec[i];
      v[i + n].lst1 = vec[i];
    }
    for(i64 i = n; i --> 1;) {
      fix(i);
      v[i].len = v[i * 2 + 0].len + v[i * 2 + 1].len;
    }
  }

  inline void eff_add(int k, T x) {
    auto& p = v[k];
    p.sum  += x * p.len;
    p.gst1 += x;
    p.lst1 += x;
    p.add += x;
    if(p.gst2 != NINF) p.gst2 += x;
    if(p.lst2 !=  INF) p.lst2 += x;
  }

  inline void eff_chmin(int k, T x) {
    auto& p = v[k];
    p.sum += (x - p.gst1) * p.gcnt;
    if(p.gst1 == p.lst1) {
      p.gst1 = p.lst1 = x;
    }
    else if(p.gst1 == p.lst2) {
      p.gst1 = p.lst2 = x;
    }
    else {
      p.gst1 = x;
    }
  }

  inline void eff_chmax(int k, T x) {
    auto& p = v[k];
    p.sum += (x - p.lst1) * p.lcnt;
    if(p.lst1 == p.gst1) {
      p.lst1 = p.gst1 = x;
    }
    else if(p.lst1 == p.gst2) {
      p.lst1 = p.gst2 = x;
    }
    else {
      p.lst1 = x;
    }
  }

  inline void push(int k) {
    if(k >= n) return;
    auto& p = v[k];
    if(p.add != 0) {
      eff_add(k * 2 + 0, p.add);
      eff_add(k * 2 + 1, p.add);
      p.add = 0;
    }
    if(p.gst1 < v[k * 2 + 0].gst1) eff_chmin(k * 2 + 0, p.gst1);
    if(p.gst1 < v[k * 2 + 1].gst1) eff_chmin(k * 2 + 1, p.gst1);

    if(p.lst1 > v[k * 2 + 0].lst1) eff_chmax(k * 2 + 0, p.lst1);
    if(p.lst1 > v[k * 2 + 1].lst1) eff_chmax(k * 2 + 1, p.lst1);
  }

  inline void infuse(int k) {
    k = k >> __builtin_ctz(k);
    while(k >>= 1) fix(k);
  }

  inline void infiltrate(int k) {
    if(k == n << 1) return;
    int kc = __builtin_ctz(k);
    for(int i = h; i --> kc;) push(k >> i);
  }

  inline void infiltrate(int l, int r) {
    if(r == n << 1) infiltrate(l);
    else {
      int hh = h;
      int x = l ^ r;
      for(; !(x >> --hh) && hh;) push(l >> hh);
      int lc = __builtin_ctz(l);
      for(int i = hh + 1; i --> lc;) push(l >> i);
      int rc = __builtin_ctz(r);
      for(int i = hh + 1; i --> rc;) push(r >> i);
    }
  }

  void subtree_chmin(int k, T x) {
    if(v[k].gst1 <= x) return;
    if(v[k].gst2 < x) {
      eff_chmin(k, x);
      return;
    }
    push(k);
    subtree_chmin(k * 2 + 0, x);
    subtree_chmin(k * 2 + 1, x);
    fix(k);
  }

  void subtree_chmax(int k, T x) {
    if(x <= v[k].lst1) return;
    if(x < v[k].lst2) {
      eff_chmax(k, x);
      return;
    }
    push(k);
    subtree_chmax(k * 2 + 0, x);
    subtree_chmax(k * 2 + 1, x);
    fix(k);
  }

  void range_chmin(int a, int b, T x) {
    int l = a + n;
    int r = b + n;
    infiltrate(l, r);
    while(l < r) {
      if(l & 1) subtree_chmin(l++, x);
      if(r & 1) subtree_chmin(--r, x);
      l >>= 1;
      r >>= 1;
    }
    infuse(a + n);
    infuse(b + n);
  }

  void range_chmax(int a, int b, T x) {
    int l = a + n;
    int r = b + n;
    infiltrate(l, r);
    while(l < r) {
      if(l & 1) subtree_chmax(l++, x);
      if(r & 1) subtree_chmax(--r, x);
      l >>= 1;
      r >>= 1;
    }
    infuse(a + n);
    infuse(b + n);
  }

  void range_add(int a, int b, T x) {
    int l = a + n;
    int r = b + n;
    infiltrate(l, r);
    while(l < r) {
      if(l & 1) eff_add(l++, x);
      if(r & 1) eff_add(--r, x);
      l >>= 1;
      r >>= 1;
    }
    infuse(a + n);
    infuse(b + n);
  }

  T range_sum(int l, int r) {
    l += n;
    r += n;
    infiltrate(l, r);
    T lx = ide;
    T rx = ide;
    while(l < r) {
      if(l & 1) lx = lx + v[l++].sum;
      if(r & 1) rx = v[--r].sum + rx;
      l >>= 1;
      r >>= 1;
    }
    return lx + rx;
  }
};

vll yakusuu_rekkyo(int M) {
    vll res(M + 1);
    for (int i = 1; i <= M; i++) {
        for (int j = 1; i * j <= M; j++) {
            res[i * j].push_back(i);
        }
    }
    return res;
}

signed main() {
    int n;
    cin >> n;
    vi a(n);
    rep (i, n) cin >> a[i];

    int M = 200000;
    // int M = 6;
    vl temp(n);
    rep (i, n) temp[i] = i;
    segment_tree_chminmaxadd_rsq next(temp);

    vll yaku = yakusuu_rekkyo(M);
    vll bai(1 + M);
    rep (i, a.size()) {
        int x = a[i];
        for (int g: yaku[x]) {
            bai[g].push_back(i);
        }
    }

    vl h(M + 1);
    for (int x = M; x >= 0; x--) {
        h[x] = (ll)n*n - next.range_sum(0, n);
        // DEBUG(x);
        // DEBUG_VEC(h);

        if (x == 0) break;
        if (bai[x].size() <= 1) continue;

        int i0 = bai[x][0];
        int j0 = bai[x][bai[x].size() - 2];
        next.range_chmax(0, i0 + 1, j0);
        int i1 = bai[x][1];
        int j1 = bai[x][bai[x].size() - 1];
        next.range_chmax(i0 + 1, i1 + 1, j1);
        next.range_chmax(i1 + 1, n, n);
    }

    for (int x = M; x >= 1; x--) {
        h[x] -= h[x - 1];
    }

    ll ans = 0;
    rep1 (i, M) ans += i * h[i];
    cout << ans << endl;
}