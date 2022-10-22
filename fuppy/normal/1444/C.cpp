#include <bits/stdc++.h>

// #include <atcoder/all>

using namespace std;
// using namespace atcoder;

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
vi dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
// const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

const int N = 511111;
vi c(N);
vii G(N), G2(N);

vector<int> color(N, -1);
bool color_dfs(int now, int now_color) {
    color[now] = now_color;
    bool res = true;
    int base = now_color / 2 * 2;
    int op;
    if (now_color == base) op = base + 1;
    else op = base;
    for (int ch: G2[now]) {
        if (color[ch] == -1) {
            bool flag = color_dfs(ch, op);
            if (not flag) res = false;
        }
        else {
            if (color[ch] == now_color) res = false;
        }
    }
    return res;
}

vii G3;
vi color3;
vi path;

bool color_dfs3(int now, int now_color) {
    path.push_back(now);
    color3[now] = now_color;
    bool res = true;
    int base = now_color / 2 * 2;
    int op;
    if (now_color == base) op = base + 1;
    else op = base;
    for (int ch: G3[now]) {
        if (color3[ch] == -1) {
            bool flag = color_dfs3(ch, op);
            if (not flag) res = false;
        }
        else {
            if (color3[ch] == now_color) res = false;
        }
    }
    return res;
}


signed main() {
    fio();

    int n, m, K;
    cin >> n >> m >> K;
    rep (i, n) {
        cin >> c[i];
        c[i]--;
    }

    map<pii, vector<pii>> mp;
    rep (i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
        if (c[u] == c[v]) {
            G2[u].push_back(v);
            G2[v].push_back(u);
        }
        else {
            mp[pii(min(c[u], c[v]), max(c[u], c[v]))].push_back(pii(u, v));
        }
    }

    set<int> ok;
    rep (i, K) ok.insert(i);

    int num = 0;
    rep (i, n) {
        if (color[i] != -1) continue;
        if (not color_dfs(i, num)) {
            ok.erase(c[i]);
        }
        num += 2;
    }

    G3.resize(num);
    color3.resize(num, -1);
    for (int i = 0; i < num; i += 2) {
        G3[i].push_back(i + 1);
        G3[i + 1].push_back(i);
    }

    ll ans = (ll)ok.size() * ((ll)ok.size() - 1) / 2;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        pii c12 = itr->first;
        if (ok.count(c12.first) == 0 or ok.count(c12.second) == 0) continue;
        path.clear();

        vector<pii> temp = itr->second;
        for (pii tt: temp) {
            int u = tt.first, v = tt.second;
            u = color[u]; v = color[v];
            G3[u].push_back(v);
            G3[v].push_back(u);
        }

        bool suc = true;
        for (pii tt: temp) {
            int u = tt.first, v = tt.second;
            u = color[u]; v = color[v];
            if (color3[u] == -1) {
                bool flag = color_dfs3(u, 0);
                if (not flag) {
                    suc = false;
                    break;
                }
            }
            if (color3[v] == -1) {
                bool flag = color_dfs3(v, 0);
                if (not flag) {
                    suc = false;
                    break;
                }
            }
        }

        if (not suc) ans--;

        for (pii tt: temp) {
            int u = tt.first, v = tt.second;
            u = color[u]; v = color[v];
            G3[u].pop_back();
            G3[v].pop_back();
        }

        for (int u: path) color3[u] = -1;
    }
    cout << ans << endl;
}