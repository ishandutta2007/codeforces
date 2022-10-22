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

int add_ver;
vii G2;
vii G1;
vector<bool> visited;
set<pii> used;
map<int, int> conv;

void dfs1(int now) {
    visited[now] = true;
    for (int u: G1[now]) {
        if (not visited[u]) {
            used.insert(pii(now, u));
            used.insert(pii(u, now));
            G2[now].push_back(u);
            G2[u].push_back(now);
            dfs1(u);
        }
        else {
            if (used.count(pii(now, u)) == 0) {
                G2[now].push_back(add_ver);
                G2[add_ver].push_back(now);
                used.insert(pii(now, u));
                used.insert(pii(u, now));
                conv[add_ver] = u;
                add_ver++;
            }
        }
    }
}


vii op;
int dfs2(int now, int par) {
    visited[now] = true;
    vi res;
    for (int ch: G2[now]) {
        if (ch == par) continue;
        int temp = dfs2(ch, now);
        if (temp != -1) res.push_back(temp);
    }
    while (res.size() >= 2) {
        int u = res.back();
        res.pop_back();
        int v = res.back();
        res.pop_back();
        op.push_back({u, now, v});
    }
    if (res.size() == 1 and par != -1) {
        op.push_back({res[0], now, par});
        return -1;
    }
    else {
        return now;
    }
}


signed main() {
    int n, m;
    cin >> n >> m;
    G1.resize(n);
    rep (i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G1[u].push_back(v);
        G1[v].push_back(u);
    }

    add_ver = n;
    visited.resize(n);
    G2.resize(n + m + 10);

    rep (i, n) {
        if (not visited[i]) {
            dfs1(i);
        }
    }

    visited.resize(add_ver);
    fill(all(visited), false);
    rep (i, n) {
        if (not visited[i]) {
            dfs2(i, -1);
        }
    }

    rep (i, n) conv[i] = i;
    cout << op.size() << endl;
    rep (i, op.size()) {
        rep (j, 3) {
            cout << conv[op[i][j]] + 1;
            if (j == 2) cout << endl;
            else cout << " ";
        }
    }
}