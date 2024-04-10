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

vii G;
const int N = 112345;
vi p(N), h(N);
vi num(N);

int dfs0(int now, int par) {
    num[now] = p[now];
    for (int v: G[now]) {
        if (v == par) continue;
        num[now] += dfs0(v, now);
    }
    return num[now];
}

pii dfs1(int now, int par) {
    if ((num[now] + h[now]) % 2 != 0) return pii(-1, -1);
    int x = (num[now] + h[now]) / 2;
    int y = num[now] - x;
    if (x < 0 or y < 0) return pii(-1, -1);

    pii ch(0, 0);
    for (int v: G[now]) {
        if (v == par) continue;
        pii temp = dfs1(v, now);
        if (temp.first == -1) return temp;
        ch = ch + temp;
    }
    int ch_x = ch.first, ch_y = ch.second;

    assert(ch_x + ch_y + p[now] == x + y);

    if (ch_x > x) return pii(-1, -1);
    else return pii(x, y);
}

void solve() {
    int n, m;
    cin >> n >> m;
    G = vii(n);
    rep (i, n) cin >> p[i];
    rep (i, n) cin >> h[i];

    rep (i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs0(0, -1);
    if (dfs1(0, -1).first == -1) cout << "NO" << endl;
    else cout << "YES" << endl;
}

signed main() {
    fio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}