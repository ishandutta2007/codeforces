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

const int M = 10000;
const int G = 1000;
// const int M = 5;
// const int G = 11;
vll dp(M, vl(G, INF));
vl d;
int g, r;
int n, m;

ll calc(int i, int j) {
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    dp[i][j] = INF;
    ll res = 0;
    if (j == 0) res += r;

    ll mi = INF;
    if (i != 0) {
        int ni = i - 1;
        int nj = j + d[i] - d[i - 1];
        if (nj <= g) {
            chmin(mi, calc(ni, nj % g) + (d[i] - d[i - 1]));
        }
    }
    if (i != m - 1) {
        int ni = i + 1;
        int nj = j + d[i + 1] - d[i];
        if (nj <= g) {
            chmin(mi, calc(ni, nj % g) + (d[i + 1] - d[i]));
        }
    }
    if (mi <= INF / 2) {
        dp[i][j] = mi + res;
    }
    return dp[i][j];
}

void solve() {
    cin >> n >> m;
    d.resize(m);
    rep (i, m) {
        cin >> d[i];
    }
    sort(all(d));
    cin >> g >> r;

    using P = pair<ll, pii>;
    priority_queue<P, vector<P>, greater<P>> pq;

    rep (i, m) {
        rep (j, g) {
            if (i == m - 1) {
                dp[i][j] = 0;
                pq.push({0, pii(i, j)});
                continue;
            }
            int dist = n - d[i];
            if (j + dist <= g) {
                dp[i][j] = dist;
                if (j == 0) dp[i][j] += r;
                pq.push({dp[i][j], pii(i, j)});
            }
        }
    }
    //DEBUG_MAT(dp);

    while (pq.size() > 0) {
        P temp = pq.top();
        pq.pop();
        ll cost = temp.first;
        int i = temp.second.first, j = temp.second.second;
        if (cost > dp[i][j]) continue;
        if (j == 0) j = j + g;
        if (i != 0) {
            int ni = i - 1;
            int nj = j - (d[i] - d[i - 1]);
            if (nj >= 0) {
                ll ncost = cost + d[i] - d[i - 1];
                if (nj == 0) ncost += r;
                if (dp[ni][nj] > ncost) {
                    dp[ni][nj] = ncost;
                    pq.push({ncost, pii(ni, nj)});
                }
            }
        }
        if (i != m - 1) {
            int ni = i + 1;
            int nj = j - (d[i + 1] - d[i]);
            if (nj >= 0) {
                ll ncost = cost + d[i + 1] - d[i];
                if (nj == 0) ncost += r;
                if (dp[ni][nj] > ncost) {
                    dp[ni][nj] = ncost;
                    pq.push({ncost, pii(ni, nj)});
                }
            }
        }
    }

    //DEBUG_MAT(dp);
    if (dp[0][0] > INF / 2) {
        cout << -1 << endl;
    }
    else {
        cout << dp[0][0] - r << endl;
    }
}

signed main() {
    fio();
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}