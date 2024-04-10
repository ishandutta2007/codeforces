#include <bits/stdc++.h>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
#define int ll
 
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
//int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
//int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
//const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'


void solve() {
    int n;
    cin >> n;
    if (n <= 2) {
        cout << -1 << endl;
        return;
    }
    if (n == 3) {
        cout << 1 << " " << 2 << " " << 8 << '\n';
        cout << 7 << " " << 3 << " " << 4 << '\n';
        cout << 6 << " " << 5 << " " << 9 << '\n';
        return;
    }

    vii a = {
        {4, 3, 6, 12},
        {7, 5, 9, 15},
        {14, 1, 11, 10},
        {13, 8, 16, 2}
    };

    vii ans(n, vi(n));
    int cnt = 1;
    rep (j, 4) {
        if (j % 2 == 0) {
            for (int i = 0; i < n - 4; i++) {
                ans[i][j] = cnt++;
            }
        }
        else {
            for (int i = n - 5; i >= 0; i--) {
                ans[i][j] = cnt++;
            }
        }
    }

    bool zen = true;
    rep (i, n) {
        if (i == n - 2) continue;
        if (zen) {
            for (int j = 4; j < n; j++) {
                ans[i][j] = cnt++;
            }
        }
        else {
            for (int j = n - 1; j >= 4; j--) {
                ans[i][j] = cnt++;
            }
        }
        zen = !zen;
    }
    if (zen) {
        for (int j = 4; j < n; j++) {
            ans[n - 2][j] = cnt++;
        }
    }
    else {
        for (int j = n - 1; j >= 4; j--) {
            ans[n - 2][j] = cnt++;
        }
    }

    rep (i, 4) {
        rep (j, 4) {
            ans[i + n - 4][j] = a[i][j] + cnt - 1;
        }
    }

    rep (i, n) {
        rep (j, n) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}


signed main() {
    fio();
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}