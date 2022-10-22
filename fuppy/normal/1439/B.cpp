//*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/
 
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
void YES(bool t=true) {cout<<(t?"YES":"NO")<<endl;}
void Yes(bool t=true) {cout<<(t?"Yes":"No")<<endl;}
void yes(bool t=true) {cout<<(t?"yes":"no")<<endl;}
void NO(bool t=true) {cout<<(t?"NO":"YES")<<endl;}
void No(bool t=true) {cout<<(t?"No":"Yes")<<endl;}
void no(bool t=true) {cout<<(t?"no":"yes")<<endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'
 
 
const int N = 100111;
vector<unordered_set<int>> G(N);
bitset<N> alive;
vi num(N);
int n, m, k;
vi cl;
 
bool judge(int u) {
    cl = vi(1, u);
    for (auto itr = G[u].begin(); itr != G[u].end(); itr++) {
        int v = *itr;
        if (G[v].size() < k - 1) return false;
        cl.push_back(v);
    }
 
    rep (i, (int)cl.size()) {
        int u = cl[i];
        REP (j, i + 1, (int)cl.size()) {
            int v = cl[j];
            if (G[u].count(v) == 0) return false;
        }
    }
    return true;
}
 
void solve() {
    cin >> n >> m >> k;
    rep (i, n) {
        G[i].clear();
        num[i] = 0;
        alive[i] = true;
    }
 
    rep (i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].insert(v);
        G[v].insert(u);
        num[u]++; num[v]++;
    }
 
    if (k > 480) {
        cout << -1 << '\n';
        return;
    }
    if (k == 1) {
        cout << 2 << '\n';
        cout << 1 << '\n';
        return;
    }
 
    queue<int> qu;
    rep (i, n) {
        if (num[i] < k - 1) {
            qu.push(i);
        }
        else if (num[i] == k - 1) {
            if (judge(i)) {
                cout << 2 << '\n';
                for (int u: cl) {
                    cout << u + 1 << " ";
                }
                cout << '\n';
                return;
            }
            qu.push(i);
        }
    }
 
    int alive_num = n;
    while (qu.size()) {
        int u = qu.front();
        qu.pop();
        alive[u] = false;
        alive_num--;
        vi judge_list;
        for (auto itr = G[u].begin(); itr != G[u].end(); itr++) {
            int v = *itr;
            G[v].erase(u);
            num[v]--;
            if (num[v] == k - 1) {
                judge_list.push_back(v);
                qu.push(v);
            }
        }
        G[u].clear();
        for (int v: judge_list) {
            if (judge(v)) {
                cout << 2 << '\n';
                for (int u: cl) {
                    cout << u + 1 << " ";
                }
                cout << '\n';
                return;
            }
        }
    }
 
    if (alive_num > 0) {
        assert(alive_num >= k + 1);
        vi temp;
        rep (i, n) {
            if (alive[i]) temp.push_back(i);
        }
        cout << 1 << " " << temp.size() << '\n';
        for (auto itr = temp.begin(); itr != temp.end(); itr++) {
            cout << *itr + 1 << " ";
        }
        cout << '\n';
    }
    else {
        cout << -1 << '\n';
    }
}
 
signed main() {
    fio();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}