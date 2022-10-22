//*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

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
void YES(bool t=true) {cout<<(t?"YES":"NO")<<endl;}
void Yes(bool t=true) {cout<<(t?"Yes":"No")<<endl;}
void yes(bool t=true) {cout<<(t?"yes":"no")<<endl;}
void NO(bool t=true) {cout<<(t?"NO":"YES")<<endl;}
void No(bool t=true) {cout<<(t?"No":"Yes")<<endl;}
void no(bool t=true) {cout<<(t?"no":"yes")<<endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

ll calc(vl& a, int m) {
    if (a.size() <= 2) return 0;

    int n = a.size();
    vll num(m + 1);
    rep (i, n) {
        bool flag = false;
        rrep (j, m) {
            ll mask = 1LL << j;
            if (mask & a[i]) {
                num[j + 1].push_back(a[i]);
                flag = true;
                break;
            }
        }
        if (not flag) num[0].push_back(a[i]);
    }

    ll ans = INF;
    // DEBUG_MAT(num);
    rep (j, m + 1) {
        ll er = 0;
        for (int i = 0; i < j; i++) {
            er += num[i].size();
        }
        if (er > 0) er--;
        for (int i = j + 1; i <= m; i++) {
            if (num[i].size() >= 2) er += num[i].size() - 1;
        }
        er += calc(num[j], m - 1);
        chmin(ans, er);
    }
    // DEBUG_VEC(a);
    // DEBUG(m);
    // DEBUG(ans);
    return ans;
}


class UnionFind {
public:
  int n;
  vi par;
  vi ran;
  vi num;
  int g;
 
  UnionFind(int _n) {
    n = _n;
    g = n;
    par.resize(n); ran.resize(n); num.resize(n);
    for (int i = 0; i < n; i++) {
      par[i] = i; ran[i] = 0; num[i] = 1;
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
 
  void unite(int x, int y) {
    x = find(x); y = find(y);
    int numsum = num[x] + num[y];
    if (x == y) {
      return;
    }
    if (ran[x]<ran[y]) {
      par[x] = y;
    }
    else {
      par[y] = x;
      if (ran[x] == ran[y]) {
        ran[x]++;
      }
    }
    num[x] = num[y] = numsum;
    g--;
  }
 
  //xyW
  bool same(int x, int y) {
    return find(x) == find(y);
  }
 
};


ll guchoku(int n, vl a) {
    int res = inf;
    // DEBUG_VEC(a);
    rep (i, 1 << n) {
        vl b;
        rep (j, n) {
            if (i & (1 << j)) b.push_back(a[j]);
        }
        if (b.size() <= 1) continue;

        UnionFind uf(b.size());
        set<pii> st;
        rep (i, b.size()) {
            pii mi(inf, -1);
            rep (j, b.size()) {
                if (i == j) continue;
                chmin(mi, pii((b[i] ^ b[j]), j));
            }
            // if (a == b) DEBUG(mi);                
            int u = min(i, mi.second), v = max(i, mi.second);
            st.insert(pii(u, v));
            uf.unite(u, v);
        }
        // if (b == a) {
        //     for (auto itr = st.begin(); itr != st.end(); itr++) {
        //         DEBUG(*itr);
        //     }
        //     DEBUG(uf.g);
        //     DEBUG(st.size());
        // }
        if (uf.g == 1 and st.size() == b.size() - 1) {
            chmin(res, n - (int)b.size());
        }
    }
    return res;
}

void solve(int n, vl a) {
    ll ans = calc(a, 35);
    // ll ans2 = guchoku(n, a);
    // if (ans != ans2) {
    //     DEBUG(n);
    //     DEBUG_VEC(a);
    //     DEBUG(pll(ans, ans2));
    //     assert(false);
    // }

    cout << ans << endl;
}

struct dice {
  mt19937 mt;
  dice() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  ll operator()(ll x) { return this->operator()(0, x); }
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

signed main() {
    fio();
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // n = rnd(2, 5);
        vl a(n);
        rep (i, n) cin >> a[i];
        // rep (i, n) {
        //     if (i == 0) a[i] = rnd(8);
        //     else a[i] = a[i - 1] + rnd(1, 8);
        // }
        sort(all(a));
        solve(n, a);
    }
}