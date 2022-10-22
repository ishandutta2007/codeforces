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

const int N = 101234;
vii G(N);
vi d(N);

int dfs1(int now, int par, int tar) {
    // DEBUG(pii(now, tar));
    if (now == tar) return 0;
    for (int ch: G[now]) {
        if (ch == par) continue;
        int res = dfs1(ch, now, tar);
        if (res == -1) continue;
        return res + 1;
    }
    return -1;
}

void dfs2(int now, int par, int dd) {
    d[now] = dd;
    for (int ch: G[now]) {
        if (ch == par) continue;
        dfs2(ch, now, dd + 1);
    }
}


void solve() {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    a--; b--;
    rep (i, n) G[i].clear();
    rep (i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int dist = dfs1(a, -1, b);
    // DEBUG(dist);
    if (dist <= da) {
        cout << "Alice" << '\n';
        return;
    }

    dfs2(0, -1, 0);
    pii ma(-inf, -inf);
    rep (i, n) {
        chmax(ma, pii(d[i], i));
    }
    int u = ma.second;
    dfs2(u, -1, 0);
    ma = pii(-inf, -inf);
    rep (i, n) {
        chmax(ma, pii(d[i], i));
    }

    int md = ma.first;
    // DEBUG(md);
    if (2 * da >= md) {
        cout << "Alice" << '\n';
        return;
    }
    da = min(da, md);
    db = min(db, md);
    if (db > 2 * da) cout << "Bob" << '\n';
    else cout << "Alice" << '\n';
}

signed main() {
    fio();
    int t;
    cin >> t;
    while (t--) solve();
}