#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

template< typename T >
struct SparseTable
{
  vector< vector< T > > st;
  using F = function<T(T&, T&)>;
  F f;

  SparseTable() {}

  SparseTable(const vector< T > &v, const F &f) :f(f)
  {
    int b = 0;
    while((1 << b) <= v.size()) ++b;
    st.assign(b, vector< T >(1 << b));
    for(int i = 0; i < v.size(); i++) {
      st[0][i] = v[i];
    }
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= (1 << b); j++) {
        st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  inline T query(int l, int r) // [l, r)
  {
    int b = 32 - __builtin_clz(r - l) - 1;
    return (f(st[b][l], st[b][r - (1 << b)]));
  }
};


int f(int a, int b) {return max(a, b);}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pii> xi;
    int start = -1;
    rep (i, s.size()) {
        if (s[i] == '1') {
            if (start < 0) start = i;
        }
        else {
            if (start >= 0) {
                xi.push_back(pii(i - start, start));
                start = -1;
            }
        }
    }
    if (start >= 0) {
        xi.push_back(pii(n - start, start));
        start = -1;
    }

    vi temp;
    rep (i, xi.size()) temp.push_back(xi[i].first);

    SparseTable<int> spa(temp, f);

    // DEBUG_VEC(xi);
    ll ans = 0;
    rep (i, xi.size()) {
        ll len = xi[i].first;
        int ok = i, ng = -1;
        while (ng + 1 < ok) {
            int mid = (ng + ok) / 2;
            if (spa.query(mid, i) >= len) ng = mid;
            else ok = mid;
        }
        // DEBUG(ng);
        ll l;
        if (ng == -1) l = 0;
        else {
            assert(xi[ng].first >= len);
            l = xi[ng].second + xi[ng].first - (len - 1);
        }

        ng = xi.size() + 1; ok = i + 1;
        while (ok + 1 < ng) {
            int mid = (ng + ok) / 2;
            if (spa.query(i + 1, mid) > len) ng = mid;
            else ok = mid;
        }
        ll r;
        if (ng == xi.size() + 1) r = n;
        else {
            assert(xi[ng - 1].first > len);
            r = xi[ng - 1].second + len;
        }
        // DEBUG(pii(l, r));
        ans += len * (xi[i].second - l + 1) * (r - (xi[i].second + xi[i].first) + 1);
    }
    // DEBUG(ans);

    rep (i, xi.size()) {
        pll temp = xi[i];
        if (temp.first > 2) {
            for (int j = 1; j <= temp.first - 2; j++) {
                ans += (temp.first - 2 - j + 1) * j;
            }
        }

        rep (iii, temp.first - 1) {
            ll l = temp.second + iii + 1;
            ll len = temp.first - iii - 1;

            int ng = xi.size() + 1, ok = i + 1;
            while (ok + 1 < ng) {
                int mid = (ng + ok) / 2;
                if (spa.query(i + 1, mid) > len) ng = mid;
                else ok = mid;
            }

            ll r;
            if (ng == xi.size() + 1) r = n;
            else {
                assert(xi[ng - 1].first > len);
                r = xi[ng - 1].second + len;
            }
            // DEBUG(pii(l, r));
            // DEBUG(xi[i]);
            ans += len * (r - (xi[i].second + xi[i].first) + 1);

            r = l;
            len = iii + 1;
            ok = i; ng = -1;
            while (ng + 1 < ok) {
                int mid = (ng + ok) / 2;
                if (spa.query(mid, i) >= len) ng = mid;
                else ok = mid;
            }

            if (ng == -1) l = 0;
            else {
                assert(xi[ng].first >= len);
                l = xi[ng].second + xi[ng].first - (len - 1);
            }
            ans += len * (xi[i].second - l + 1);
        }
    }

    cout << ans << endl;
}

signed main() {
    fio();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}