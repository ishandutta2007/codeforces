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

bool check(string& s) {
    int cnt = 0;
    if (s[0] == 'R') cnt++;
    if (s[2] == 'L') cnt++;
    if (cnt == 0 or cnt == 2) return true;
    if (s[0] == 'R') return s[1] == 'L';
    if (s[2] == 'L') return s[1] == 'R';
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vii> dp(n + 1, vii(2, vi(2, inf)));

    int ans = inf;
    rep (i1, 2) {
        rep (j1, 2) {
            rep (i, n + 1) rep (j, 2) rep (k, 2) dp[i][j][k] = inf;
            string ini;
            if (i1 == 0) ini += 'L';
            else ini += 'R';
            if (j1 == 0) ini += 'L';
            else ini += 'R';

            dp[2][i1][j1] = 0;
            rep (i, 2) if (ini[i] != s[i]) dp[2][i1][j1]++;

            for (int i = 2; i < n; i++) {
                rep (j, 2) {
                    rep (k, 2) {
                        if (dp[i][j][k] == inf) continue;

                        rep (add, 2) {
                            string temp;
                            if (j == 0) temp += 'L';
                            else temp += 'R';
                            if (k == 0) temp += 'L';
                            else temp += 'R';
                            if (add == 0) temp += 'L';
                            else temp += 'R';

                            int score = 0;
                            if (s[i] != temp.back()) score = 1;
                            if (check(temp)) {
                                chmin(dp[i + 1][k][add], dp[i][j][k] + score);
                            }
                        }
                    }
                }
            }

            rep (j, 2) {
                rep (k, 2) {
                    string temp;
                    if (j == 0) temp += 'L';
                    else temp += 'R';
                    if (k == 0) temp += 'L';
                    else temp += 'R';
                    temp += ini;
                    string temp1 = temp.substr(0, 3), temp2 = temp.substr(1, 3);
                    if (check(temp1) and check(temp2)) chmin(ans, dp[n][j][k]);
                }
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    fio();

    int t = 1;
    cin >> t;
    while (t--) solve();
}