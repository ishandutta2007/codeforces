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
// const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

bool dp1[5001][5001];
int dp2[5001][5001];

void solve(int n, vector<pll> tx) {
    vl t, x;
    rep (i, n) {
        t.push_back(tx[i].first);
        x.push_back(tx[i].second);
    }

    rep (i, n + 1) rep (j, n + 1) {
        dp1[i][j] = false;
        dp2[i][j] = inf;
    }

    dp1[0][0] = true;
    for (int i = 0; i < n; i++) {
        ll now;
        if (i == 0) now = 0;
        else now = x[i - 1];
        ll now_time;
        if (i == 0) now_time = 0;
        else now_time = t[i - 1];

        for (int j = i; j <= n; j++) {
            if (not dp1[i][j]) continue;
            if (j > i + 1) {
                if (abs(x[i] - now) <= abs(t[i] - now_time)) {
                    dp1[i + 1][j] = true;
                    if (i + 1 == n) {
                        YES();
                        return;
                    }
                }
            }

            if (j == i + 1) {
                if (j == n) {
                    YES();
                    return;
                }
                for (int nj = j + 1; nj <= n; nj++) {
                    int nex_time = now_time + abs(x[nj - 1] - now);
                    if (nex_time <= t[i]) nex_time = t[i];
                    if (nex_time <= t[nj - 1]) chmin(dp2[i + 1][nj], nex_time);
                }
            }

            if (j == i) {
                if (abs(x[i] - now) <= abs(t[i] - now_time)) {
                    dp1[i + 1][i + 1] = true;
                    if (i + 1 == n) {
                        YES();
                        return;
                    }
                }

                for (int nj = j + 1; nj <= n; nj++) {
                    int nex_time = now_time + abs(x[nj - 1] - now);
                    if (nex_time <= t[nj - 1]) chmin(dp2[i][nj], nex_time);
                }
            }
        }

        for (int j = i + 1; j <= n; j++) {
            if (dp2[i][j] > t[i]) continue;
            if (i == n - 1 and j == n) {
                YES();
                return;
            }

            int now = x[j - 1];
            int now_time = dp2[i][j];
            if (j > i + 1) {
                if (abs(x[i] - now) <= t[i] - now_time) {
                    dp1[i + 1][j] = true;
                    if (i + 1 == n) {
                        YES();
                        return;
                    }
                }
            }
            else if (j == i + 1) {
                if (i != n - 1) {
                    if (abs(x[i + 1] - now) <= t[i + 1] - now_time) {
                        dp1[i + 2][i + 2] = true;
                        if (i + 2 == n) {
                            YES();
                            return;
                        }
                    }
                }

                for (int nj = j + 1; nj <= n; nj++) {
                    int nex_time = now_time + abs(x[nj - 1] - now);
                    if (nex_time <= t[i]) nex_time = t[i];
                    if (nex_time <= t[nj - 1]) chmin(dp2[i + 1][nj], nex_time);
                }
            }
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << dp1[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << dp2[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for (int j = 0; j <= n; j++) {
        if (dp1[n][j]) {
            YES();
            return;
        }
    }
    NO();
}

signed main() {
    fio();

    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pll> tx(n);
        rep (i, n) cin >> tx[i].first >> tx[i].second;
        sort(all(tx));
        
        solve(n, tx);
    }
}