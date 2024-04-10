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
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'


signed main() {
    fio();
    
    vector<vector<pll>> dp(1, vector<pll>(1, pll(-1, 0)));
    dp[0].push_back(pll(-1, 0));
    vector<vector<pll>> ma(1, vector<pll>(1, pll(-1, 0)));
    vl ws(1, 0);
    int cnt = 1;
    int q;
    cin >> q;
    vl power2(q + 1);
    power2[0] = 1;
    rep (i, q) {
        power2[i + 1] = power2[i] * 2 % MOD;
    }
    ll last = 0;
    while (q--) {
        ll t, u, w;
        cin >> t >> u >> w;
        u = u ^ last;
        w = w ^ last;
        u--;
        if (t == 1) {
            ws.push_back(w);
            dp.push_back(vector<pll>(1, pll(-1, 0)));
            ma.push_back(vector<pll>(1, pll(-1, 0)));
            cnt++;
            int now = cnt - 1;
            int par = u;

            ma[cnt - 1].push_back(pll(par, w));
            int i = 1;
            ll mm = w;
            while (true) {
                int to = ma[cnt - 1][i].first;
                if (to == -1) break;
                int ni = i;
                // if (ni >= ma[to].size()) ni = (int)ma[to].size() - 1;
                if (ni >= ma[to].size()) break;
                chmax(mm, ma[to][ni].second);
                ma[cnt - 1].push_back(pll(ma[to][ni].first, mm));
                i++;
            }
            while (par != -1 and ws[par] < w) {
                rrep (i, ma[par].size()) {
                    if (ma[par][i].second >= w) continue;
                    par = ma[par][i].first;
                    break;
                }
            }

            dp[cnt - 1].push_back(pll(par, w));
            i = 1;
            while (true) {
                int to = dp[cnt - 1][i].first;
                if (to == -1) break;
                int ni = i;
                // if (ni >= dp[to].size()) ni = (int)dp[to].size() - 1;
                if (ni >= dp[to].size()) break;
                ll nw = dp[cnt - 1][i].second + dp[to][ni].second;
                dp[cnt - 1].push_back(pll(dp[to][ni].first, nw));
                i++;
            }
        }
        else {
            ll sum = 0;
            int ans = 0;
            while (u != -1) {
                // DEBUG(u);
                rrep (i, dp[u].size()) {
                    if (sum + dp[u][i].second > w) continue;
                    if (i != 0) {
                        sum += dp[u][i].second;
                        ans += power2[i - 1];
                    }
                    u = dp[u][i].first;
                    break;
                }
            }
            cout << ans % MOD << endl;
            last = ans;
        }
        // DEBUG_MAT(ma);
        // DEBUG_MAT(dp);
    }
}