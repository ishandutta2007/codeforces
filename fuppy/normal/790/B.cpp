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

const int N = 211111;
vii G(N);
int n, m;

vector<vector<pii>> dp(N, vector<pii>(5));

ll ans = 0;

void dfs(int now, int par) {
    // DEBUG(now);
    vector<pii> res(5);
    res[0] = pii(0, 1);
    for (int ch: G[now]) {
        if (ch == par) continue;
        dfs(ch, now);

        vector<pii> nex = dp[ch];
        vector<pii> nnex(5);
        rep (i, m) {
            if (i == 0) {
                nnex[(i + 1) % m] = nex[i];
                nnex[(i + 1) % m].first += nex[i].second;
            }
            else {
                nnex[(i + 1) % m] = nex[i];
            }
        }
        // for (int i = 0; i < m; i++) {
        //     ans += nnex[i].first;
        // }
        // DEBUG_VEC(res);
        // DEBUG_VEC(nnex);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                ans += res[i].first * nnex[j].second + nnex[j].first * res[i].second; 
                if (i > 0 and j > 0 and i + j <= m) {
                    ans -= (res[i].second * nnex[j].second);
                }
            }
        }

        rep (i, m) {
            res[i].first += nnex[i].first;
            res[i].second += nnex[i].second;
        }
    }
    dp[now] = res;

    // DEBUG(now);
    // DEBUG_VEC(res);
    // DEBUG(ans);
}

signed main() {
    fio();
    cin >> n >> m;    
    rep (i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(0, -1);
    cout << ans << endl;
}