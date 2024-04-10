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

const int N = 511111;
// const int N = 5;
vii G1(N);
vector<vector<pll>> G2(N);

using P = array<ll, 3>;
vl ans(N);
vector<vector<P>> res(N);

int dfs1(int now, int par, int dep) {
    int idx = now;
    for (int ch: G1[now]) {
        if (ch == par) continue;
        int idx2 = dfs1(ch, now, dep + 1);

        if (res[idx].size() < res[idx2].size()) swap(idx, idx2);
        rep (i, res[idx2].size()) {
            int u = res[idx][res[idx].size() - 1 - i][1], v = res[idx2][res[idx2].size() - 1 - i][1];
            ll cntu = res[idx][res[idx].size() - 1 - i][0], cntv = res[idx2][res[idx2].size() - 1 - i][0];
            ans[v] += cntu * (dep + 1);
            ans[u] += cntv * (dep + 1);
            res[idx][res[idx].size() - 1 - i][0] += res[idx2][res[idx2].size() - 1 - i][0];
            res[idx][res[idx].size() - 1 - i][1] = u;
            res[idx][res[idx].size() - 1 - i][2] = ans[u];

            G2[u].push_back(pll(v, ans[v] - ans[u]));
        }
    }
    res[idx].push_back({1, now, dep});
    ans[now] = dep;
    return idx;
}

vector<bool> visited(N);
void dfs2(int now) {
    visited[now] = true;
    for (pll temp: G2[now]) {
        auto [u, dif] = temp;
        ans[u] = ans[now] + dif;
        dfs2(u);
    }
}

void dfs3(int now, int par) {
    for (int ch: G1[now]) {
        if (ch == par) continue;
        ans[ch] += ans[now];
        dfs3(ch, now);
    }
}

signed main() {
    int n;
    cin >> n;
    int root1;
    rep (i, n) {
        int p;
        cin >> p;
        if (p == 0) root1 = i;
        else {
            p--;
            G1[p].push_back(i);
            G1[i].push_back(p);
        }
    }

    dfs1(root1, -1, 0);
    rep (i, n) {
        if (not visited[i]) {
            dfs2(i);
        }
    }

    dfs3(root1, -1);

    rep (i, n) {
        cout << ans[i] << " ";
    }
    cout << endl;
}