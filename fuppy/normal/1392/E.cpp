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


void solve(int n, vll a, ll s) {
    int i = 0, j = 0;
    ll nex = 2;
    vector<pii> res;
    while (i < n - 1 or j < n - 1) {
        // DEBUG(pii(i, j));
        s -= a[i][j];
        res.push_back(pii(i, j));
        if (s % nex == 0) {
            if (i + 1 < n and a[i + 1][j] == nex) i++;
            else j++;
        }
        else {
            if (i + 1 < n and a[i + 1][j] != nex) i++;
            else j++;
        }
        nex *= 2;
    }
    assert(s == a[n - 1][n - 1]);
    res.push_back(pii(i, j));

    rep (i, res.size()) {
        cout << res[i].first + 1 << " " << res[i].second + 1 << endl;
    }
}

void solve() {
    int n;
    cin >> n;

    vll a(n, vl(n));
    ll nex = 1;
    for (int j = 1; j < n; j++) {
        int jj = j, ii = 0;
        int cnt = 0;
        while (jj >= 0) {
            if (cnt % 2 == 0) a[ii][jj] = nex;
            else a[ii][jj] = nex * 2;
            ii++;
            jj--;
            cnt++;
        }
        nex *= 2;
    }
    for (int i = 1; i < n; i++) {
        int ii = i, jj = n - 1;
        int cnt = 0;
        while (ii < n) {
            if (cnt % 2 == 0) a[ii][jj] = nex;
            else a[ii][jj] = nex * 2;
            ii++;
            jj--;
            cnt++;
        }
        nex *= 2;
    }

    rep (i, n) {
        rep (j, n) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


    int q;
    cin >> q;
    while (q--) {
        ll s;
        cin >> s;
        solve(n, a, s);
    }
}

signed main() {
    // fio();

    int t = 1;
    // cin >> t;
    while (t--) solve();
}