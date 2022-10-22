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


struct dice {
  mt19937 mt;
  dice() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  // [0, x)
  ll operator()(ll x) { return this->operator()(0, x); }
  // [x, y)
  ll operator()(ll x, ll y) {
    uniform_int_distribution<ll> dist(x, y - 1);
    return dist(mt);
  }
  vl operator()(int n, ll x, ll y) {
    vl res(n);
    for (int i = 0; i < n; i++) res[i] = this->operator()(x, y);
    return res;
  }
} rnd;


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

  // km[hx]s
  inline void eval(int k, int l, int r) {
    if (lazy[k] != e2) { // Change
      node[k] = eval_func(node[k], lazy[k], l, r);
      if (r - l > 1) {
        lazy[2 * k + 1] = update_func(lazy[2*k + 1], lazy[k]);
        lazy[2 * k + 2] = update_func(lazy[2*k + 2], lazy[k]);
      }
      lazy[k] = e2; // Change
    }
  }

  // [a, b)x
  void update(int a, int b, T2 x, int k, int l, int r) {
    // k m[hx]s
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

ll f(ll a, ll b) {return a + b;}
ll g(ll a, ll b) {return a + b;}
ll h(ll a, ll b, int l, int r) {return a + b * (r - l);}


vl solve2(int n, vl a) {
  bool updated = true;
  while (updated) {
    updated = false;
    rep (i, n - 1) {
      while (a[i] + 2 <= a[i + 1]) {
        a[i]++;
        a[i + 1]--;
        updated = true;
      }
    }
  }
  return a;
}

using P = pair<ll, pii>;
void fix(vector<P>& p) {

}

void solve() {
    int n;
    cin >> n;
    // n = rnd(2, 100);
    // DEBUG(n);
    vl a(n);
    ll sum = 0;
    ll pre = 0;
    rep (i, n) {
        cin >> a[i];
        // ll add = rnd(100);
        // a[i] = pre + add;
        // pre += add;
        // sum += a[i];
    }
    // DEBUG_VEC(a);
    // vl ans2 = solve2(n, a);
    // DEBUG_VEC(ans2);

    vi flat;
    LazySegmentTree<ll, ll> seg(vl(n), f, g, h, 0, 0);
    seg.update(0, 1, a[0], 0, 0, seg.n);

    vector<P> p;
    p.push_back(P(a[0], pii(0, 1)));
    for (int i = 1; i < n; i++) {
        // DEBUG_VEC(flat);
        while (flat.size()) {
            // ll last = seg.query(i - 1, i, 0, 0, seg.n);
            ll last = p.back().first + p.back().second.second - p.back().second.first - 1;
            int l = flat.back();
            int r = i;
            if (a[i] - (r - l) >= last + 1) {
                flat.pop_back();
                P p1 = p.back();
                p.pop_back();
                P p2 = p.back();
                p.pop_back();
                p.push_back(P(p2.first, pii(p2.second.first, p1.second.second)));
                // seg.update(l, r, 1, 0, 0, seg.n);
                a[i] -= r - l;
            }
            else {
                ll add = a[i] - (last + 1);
                if (add == -1) {
                    flat.push_back(i);
                    p.push_back(P(a[i], pii(i, i + 1)));
                    // seg.update(i, i + 1, a[i], 0, 0, seg.n);
                }
                else {
                    flat.pop_back();
                    // seg.update(l, l + add, 1, 0, 0, seg.n);
                    P temp = p.back();
                    p.pop_back();
                    p.back().second.second = l + add;
                    // p.push_back(P(temp.first + 1, pii(l, l + add)));
                    p.push_back(P(temp.first, pii(l + add, i)));
                    flat.push_back(l + add);
                    // seg.update(i, i + 1, a[i] - add, 0, 0, seg.n);
                    p.back().second.second++;
                    // p.push_back(P(a[i] - add, pii(i, i + 1)));
                }
                break;
            }
        }

        // rep (i, n) {
        //     cout << seg.query(i, i + 1, 0, 0, seg.n) << " ";
        // }
        // cout << endl;

        if (flat.size() == 0) {
            ll add = i;
            // ll last = seg.query(i - 1, i, 0, 0, seg.n);
            ll last = p[0].first + i - 1;

            ll x = (a[i] - last) / (1 + add);
            p[0].first += x;
            // seg.update(0, i, x, 0, 0, seg.n);
            a[i] -= x * add;
            // while (seg.query(i - 1, i, 0, 0, seg.n) + 1 <= a[i] - add) {
            //     seg.update(0, i, 1, 0, 0, seg.n);
            //     a[i] -= add;
            // }
            add = a[i] - (p[0].first + i - 1 + 1);
            // add = a[i] - (seg.query(i - 1, i, 0, 0, seg.n) + 1);
            if (add == -1) {
                flat.push_back(i);
                p.push_back(P(a[i], pii(i, i + 1)));
                // seg.update(i, i + 1, a[i], 0, 0, seg.n);
            }
            else {
                if (add != 0) {
                  P temp = p[0];
                  p.pop_back();
                  p.push_back(P(temp.first + 1, pii(0, add)));
                  p.push_back(P(temp.first + add, pii(add, i)));
                  // seg.update(0, add, 1, 0, 0, seg.n);
                  flat.push_back(add);
                }
                p.back().second.second++;
                // p.push_back(P(a[i] - add, pii(i, i + 1)));
                // seg.update(i, i + 1, a[i] - add, 0, 0, seg.n);
            }
        }
        // DEBUG_VEC(p);

        // rep (i, n) {
        //     cout << seg.query(i, i + 1, 0, 0, seg.n) << " ";
        // }
        // cout << endl;
    }

    // vl ans;
    // DEBUG_VEC(p);
    rep (i, p.size()) {
      rep (_, p[i].second.second - p[i].second.first) {
        // ans.push_back(p[i].first);
        cout << p[i].first << " ";
        p[i].first++;
      }
    }
    // rep (i, n) {
    //     // ans.push_back(seg.query(i, i + 1, 0, 0, seg.n));
    //     cout << seg.query(i, i + 1, 0, 0, seg.n) << " ";
    // }
    cout << endl;
    // assert(ans == ans2);
}

signed main() {
    fio();

    int t = 1;
    // cin >> t;
    while (t--) solve();
}