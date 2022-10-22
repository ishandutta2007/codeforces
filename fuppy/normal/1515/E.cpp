/*
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
int popcount(ll t) { return __builtin_popcountll(t); }
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(25);
    }
} setup_io;
// const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

ll C[544][544];
int n;
ll MOD;

void solve() {
    cin >> n >> MOD;

    C[0][0] = 1;
    rep1 (i, 444) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 or j == i) C[i][j] = 1;
            else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }

    vl num(n + 1);
    rep (i, n + 1) {
        if (i <= 1) {
            num[i] = 1;
            continue;
        }

        num[i] = 2;
        for (int k = 1; k < i - 1; k++) {
            int l = k;
            int r = i - 1 - l;
            num[i] += C[l + r][l];
        }
        num[i] %= MOD;
    }
    // DEBUG_VEC(num);

    vector<vll> dp1(n + 1, vll(n + 1, vl(2))), dp2(n + 1, vll(n + 1, vl(2)));

    dp1[0][0][0] = 1;
    rep (i, n) {
        rep (j, n + 1) {
            rep (k, n + 1) {
                rep (l, 2) {
                    dp2[j][k][l] = 0;
                }
            }
        }

        rep (j, n + 1) {
            rep (k, n + 1) {
                rep (l, 2) {
                    if (dp1[j][k][l] == 0) continue;

                    // not use
                    if (l == 1) {
                        (dp2[j + k][0][0] += dp1[j][k][l] * C[j + k][k] % MOD * num[k]) %= MOD;
                    }
                    // use
                    (dp2[j][k + 1][1] += dp1[j][k][l]) %= MOD;
                }
            }
        }

        // DEBUG(i);
        // rep (j, n + 1) {
        //     rep (k, n + 1) {
        //         cout << dp[i + 1][j][k] << " ";
        //     }
        //     cout << endl;
        // }
        swap(dp1, dp2);
    }

    vl ans(n + 1);
    rep (j, n + 1) {
        rep (k, n + 1) {
            if (dp1[j][k][1] == 0) continue;
            (ans[j + k] += dp1[j][k][1] * C[j + k][k] % MOD * num[k]) %= MOD;
        }
    }

    ll sum = 0;
    rep (i, n + 1) sum += ans[i];
    sum %= MOD;
    cout << sum << endl;
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}