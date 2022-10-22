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
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

vi judge(vector<vector<pii>> G) {
    int n = G.size();
    vector<set<int>> dp(n);
    dp[0].insert(0);
    rep (i, n) {
        for (auto itr = dp[i].begin(); itr != dp[i].end(); itr++) {
            int x = *itr;
            for (pii temp: G[i]) {
                int v = temp.first;
                int cost = temp.second;
                dp[v].insert(x + cost);
            }
        }
    }

    vi res;
    for (auto itr = dp[n - 1].begin(); itr != dp[n - 1].end(); itr++) res.push_back(*itr);
    return res;
}

signed main() {
    int l, r;
    cin >> l >> r;

    int n;
    int s;
    vector<vector<pii>> G;
    if (l == 1) {
        n = 22;
        s = 0;
        G.resize(n);
    }
    else {
        n = 23;
        s = 1;
        G.resize(n);
        G[0].push_back(pii(s, l - 1));
    }
    G[s].push_back(pii(n - 1, 0));

    int tar = r - l;
    int now = 0;
    for (int keta = 19; keta >= 0; keta--) {
        int mask = 1 << keta;
        if (mask & tar) {
            G[s].push_back(pii(s + (21 - (keta + 1)), now));
            now |= mask;
        }
    }
    // DEBUG_MAT(G);
    for (int keta = 19; keta >= 0; keta--) {
        for (int nketa = keta - 1; nketa >= 0; nketa--) {
            G[s + (21 - (keta + 1))].push_back(pii(s + (21 - (nketa + 1)), 1 << nketa));
        }
    }

    for (int keta = 19; keta >= 0; keta--) {
        G[s + (21 - (keta + 1))].push_back(pii(n - 1, 0));
    }

    int m = 0;
    rep (i, n) {
        rep (j, G[i].size()) {
            int u = i;
            int v = G[i][j].first;
            if (u == s or v == n - 1) {
                G[i][j].second++;
            }
            m++;
        }
    }

    YES();
    cout << n << " " << m << endl;
    rep (i, n) {
        rep (j, G[i].size()) {
            int u = i;
            int v = G[i][j].first;
            cout << u + 1 << " " << v + 1 << " " << G[i][j].second << endl;
        }
    }


    // vi temp = judge(G);
    // DEBUG_VEC(temp);
}