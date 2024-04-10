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

const int N = 100011;
vii G(N);

vii dp(N, vi(2));
vi d(N);

int ans = 0;

void dfs(int now, int par) {
    int res1 = 0, res2 = 0;
    int ch_num = 0;
    for (int ch: G[now]) {
        if (ch == par) continue;
        dfs(ch, now);
        chmax(res1, dp[ch][0]);
        chmax(res2, dp[ch][1]);
        ch_num++;
    }
    dp[now][0] = max(res1, res2) + ch_num - 1;
    dp[now][1] = res1 + 1;
    int add = 0;
    if (par != -1) add++;
    chmax(ans, max(dp[now][1], dp[now][0] + add));
    chmax(dp[now][1], dp[now][0]);

    vi use(2), un(2);
    if (ch_num >= 2) {
        for (int ch: G[now]) {
            if (use[0] <= dp[ch][1]) {
                use[1] = use[0];
                use[0] = dp[ch][1];
            }
            else if (use[1] <= dp[ch][1]) {
                use[1] = dp[ch][1];
            }

            if (un[0] <= dp[ch][0]) {
                un[1] = un[0];
                un[0] = dp[ch][0];
            }
            else if (un[1] <= dp[ch][0]) {
                un[1] = dp[ch][0];
            }
        }
    }
    chmax(ans, use[0] + use[1] + ch_num - 2 + add);
    chmax(ans, un[0] + un[1] + 1);
}

void dfs1(int now, int par, int dis) {
    d[now] = dis;
    for (int ch: G[now]) {
        if (ch == par) continue;
        dfs1(ch, now, dis + 1);
    }
}

signed main() {
    int n;
    cin >> n;
    rep (i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(0, -1);
    cout << ans << endl;
    // pii ma(0, -1);
    // rep (i, n)
    // cout << max(dp[0][0], dp[0][1]) << endl;
}