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
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vl a(n);
    rep (i, n) cin >> a[i];

    ll mask = 1LL << 40;
    int cnt = 0;
    while (mask > 0) {
        cnt = 0;
        rep (i, n) {
            if (a[i] & mask) cnt++;
        }
        if (cnt % 2 == 1) break;
        mask >>= 1;
    }
    if (mask == 0) {
        cout << "DRAW" << '\n';
        return;
    }

    int ncnt = n - cnt;
    string ans;
    if (cnt % 4 == 0 or cnt % 4 == 3) {
        if (ncnt % 2 == 0) ans = "LOSE";
        else ans = "WIN";
    }
    else if (cnt % 4 == 1) ans = "WIN";
    else {
        if (ncnt % 2 == 0) ans = "WIN";
        else ans = "LOSE";
    }
    cout << ans << '\n';
}

int N = 100;
vector<vector<vector<vector<int>>>> win(N, vector<vector<vector<int>>>(N, vii(2, vi(2))));

bool dfs(int i, int j, int k, int l) {
    if (win[i][j][k][l] != 0) {
        return win[i][j][k][l] == 1;
    }

    bool win1 = true, win2 = true;
    if (i > 0) {
        win1 = dfs(i - 1, j, l, 1 - k);
    }
    if (j > 0) {
        win2 = dfs(i, j - 1, l, k);
    }
    if (win1 == false or win2 == false) win[i][j][k][l] = 1;
    else win[i][j][k][l] = -1;
    return win[i][j][k][l] == 1;
}

signed main() {
    // win[0][0][0][0] = -1;
    // win[0][0][1][0] = 1;
    // win[0][0][0][1] = -1;
    // win[0][0][1][1] = 1;
    // rep (i, N) {
    //     rep (j, N) {
    //         rep (k, 2) {
    //             rep (l, 2) {
    //                 dfs(i, j, k, l);
    //             }
    //         }
    //     }
    // }

    // rep (i, 20) {
    //     rep (j, 20) {
    //         cout << win[i][j][0][0] << " ";
    //     }
    //     cout << endl;
    // }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}