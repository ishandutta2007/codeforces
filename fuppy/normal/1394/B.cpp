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

const int N = 200000;
vector<vector<pii>> G(N);
vector<vector<pii>> rG(N);

vector<vector<set<pii>>> out(10, vector<set<pii>>(10));
vector<vector<bool>> cant(10, vector<bool>(10));

int n, m, k;
int ans = 0;

void dfs(vi& c, int idx) {
    if (idx == k) {
        ans++;
        return;
    }
    for (int add = 0; add <= idx; add++) {
        pii p = pii(idx, add);
        if (cant[p.first][p.second]) continue;
        bool flag = true;
        rep (j, c.size()) {
            pii p2 = pii(j, c[j]);
            if (out[p.first][p.second].count(p2)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            c.push_back(add);
            dfs(c, idx + 1);
            c.pop_back();
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    rep (i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back(pii(w, v));
        rG[v].push_back(pii(w, u));
        // G[u].push_back(w);
    }
    rep (i, n) {
        sort(all(G[i]));
    }

    vii num(10, vi(10));
    rep (u, n) {
        vector<pii> temp;
        rep (i, 10) rep (j, 10) num[i][j] = 0;

        rep (i, rG[u].size()) {
            int v = rG[u][i].second;
            rep (j, G[v].size()) {
                if (G[v][j].second == u) {
                    pii p = pii((int)G[v].size() - 1, j);
                    temp.push_back(p);
                    num[p.first][p.second]++;
                    if (num[p.first][p.second] == 2) cant[p.first][p.second] = true;
                }
            }
        }

        sort(all(temp));
        UNIQUE(temp);
        rep (i, temp.size()) {
            pii p = temp[i];
            rep (j, temp.size()) {
                if (i == j) continue;
                out[p.first][p.second].insert(temp[j]);
            }
        }
    }

    vi c;
    dfs(c, 0);
    cout << ans << endl;
}

signed main() {
    fio();

    int t = 1;
    // cin >> t;
    while (t--) solve();
}