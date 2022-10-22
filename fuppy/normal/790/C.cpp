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
//const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'


signed main() {
    fio();
    int n;
    cin >> n;
    string s;
    cin >> s;

    vi num(3);
    rep (i, n) {
        if (s[i] != 'V' and s[i] != 'K') s[i] = '?';
        if (s[i] == 'V') num[0]++;
        else if (s[i] == 'K') num[1]++;
        else num[2]++;
    }

    vector<vector<vii>> dp(n + 1, vector<vii>(num[0] + 1, vii(num[1] + 1, vi(3, inf))));
    dp[0][0][0][2] = 0;

    // DEBUG_VEC(num);

    vi num2(3);
    rep (i, n) {
        rep (j, num[0] + 1) {
            rep (k, num[1] + 1) {
                rep (l, 3) {
                    if (dp[i][j][k][l] == inf) continue;
                    rep (nl, 3) {
                        if (l == 0 and nl == 1) continue;
                        int x = i - j - k;
                        if (j == num[0] and nl == 0) continue;
                        if (k == num[1] and nl == 1) continue;
                        if (x == num[2] and nl == 2) continue;

                        int cost = 0;
                        fill(all(num2), 0);
                        rep (i, n) {
                            if (s[i] == 'V') {
                                if (num2[0] < j) num2[0]++;
                                else {
                                    if (nl == 0) break;
                                    else cost++;
                                }
                            }
                            else if (s[i] == 'K') {
                                if (num2[1] < k) num2[1]++;
                                else {
                                    if (nl == 1) break;
                                    else cost++;
                                }
                            }
                            else {
                                if (num2[2] < x) num2[2]++;
                                else {
                                    if (nl == 2) break;
                                    else cost++;
                                }
                            }
                        }

                        int nj = j, nk = k;
                        if (nl == 0) nj++;
                        if (nl == 1) nk++;
                        chmin(dp[i + 1][nj][nk][nl], dp[i][j][k][l] + cost);
                    }
                }
            }
        }
    }

    int ans = inf;
    rep (i, 3) chmin(ans, dp[n][num[0]][num[1]][i]);
    cout << ans << endl;
}