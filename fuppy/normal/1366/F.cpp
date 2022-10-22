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
//int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
//int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

vector<vector<pii>> G;
vi max_w;

ll rui(ll n) {
    return n * (n + 1) / 2 % MOD;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    G.resize(n);
    max_w.resize(n);
    rep (i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back(pii(v, w));
        G[v].push_back(pii(u, w));
    }
    rep (i, n) {
        rep (j, G[i].size()) {
            chmax(max_w[i], G[i][j].second);
        }
    }

    vll dp(m + 1, vl(n, -INF));
    dp[0][0] = 0;
    rep (i, m) {
        rep (j, n) {
            if (dp[i][j] == -INF) continue;
            for (pii temp: G[j]) {
                int nj = temp.first;
                ll ncost = dp[i][j] + temp.second;
                chmax(dp[i + 1][nj], ncost);
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ll ma = 0;
        rep (j, n) chmax(ma, dp[i][j]);
        (ans += ma) %= MOD;
    }

    vl dp2(n);
    int max_idx = -1;
    ll max_value = -1;
    rep (i, n) {
        rep (t, m + 1) {
            chmax(dp2[i], dp[t][i] + (ll)(m - t) * max_w[i]);
        }
        if (max_value < dp2[i]) {
            max_value = dp2[i];
            max_idx = i;
        }
    }
    // DEBUG(ans);
    
    ll turn = m;
    // DEBUG(max_idx);
    while (turn < q) {
        int next_idx = -1;
        ll min_turn = q + 1;
        rep (i, n) {
            if (i == max_idx) continue;
            if (max_w[i] <= max_w[max_idx]) continue;
            ll nturn = (dp2[i] - dp2[max_idx] - m * (max_w[i] - max_w[max_idx])) / (max_w[max_idx] - max_w[i]) + 1;
            if (turn + 1 < nturn and nturn < min_turn) {
                min_turn = nturn;
                next_idx = i;
            }
        }
        // DEBUG(next_idx);
        // DEBUG(min_turn)

        ans += (min_turn - turn - 1) * dp2[max_idx] % MOD;
        // DEBUG(ans);
        ans -= m * max_w[max_idx] % MOD * (min_turn - turn - 1) % MOD;
        ans += max_w[max_idx] * (rui(min_turn - 1) - rui(turn)) % MOD;
        ans %= MOD;

        turn = min_turn - 1;
        max_idx = next_idx;
        max_value = dp2[max_idx] + (min_turn - 1 - m) * max_w[max_idx];
    }
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << endl;
}

signed main() {
    fio();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}