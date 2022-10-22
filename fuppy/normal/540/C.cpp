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
int popcount(ll t) { return __builtin_popcountll(t); }
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(25);
    }
} setup_io;
// const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

int visited[555][555];
int h, w;

bool dfs(pii now, pii goal, vector<string> &s) {
    visited[now.first][now.second] = true;
    rep (k, 4) {
        pii nex = now;
        nex.first += dy[k]; nex.second += dx[k];
        if (not in(nex.first, 0, h) or not in(nex.second, 0, w)) continue;
        if (nex == goal) return true;
        if (visited[nex.first][nex.second]) continue;
        if (s[nex.first][nex.second] == 'X') continue;
        if (dfs(nex, goal, s)) return true;
    }
    return false;
}

signed main() {
    cin >> h >> w;
    vector<string> s(h);
    rep (i, h) cin >> s[i];

    pii now, goal;
    cin >> now.first >> now.second;
    cin >> goal.first >> goal.second;
    now.first--; now.second--;
    goal.first--; goal.second--;
    if (now == goal) {
        int cnt = 0;
        rep (k, 4) {
            pii nex = goal;
            nex.first += dy[k]; nex.second += dx[k];
            if (not in(nex.first, 0, h) or not in(nex.second, 0, w)) continue;
            if (s[nex.first][nex.second] == '.') cnt++;
        }
        if (cnt >= 1) YES();
        else NO();
        return 0;
    }

    bool flag = dfs(now, goal, s);
    if (not flag) {
        NO();
        return 0;
    }

    if (s[goal.first][goal.second] == 'X') {
        YES();
        return 0;
    }
    int cnt = 0;
    bool st_ad = false;
    rep (k, 4) {
        pii nex = goal;
        nex.first += dy[k]; nex.second += dx[k];
        if (not in(nex.first, 0, h) or not in(nex.second, 0, w)) continue;
        if (s[nex.first][nex.second] == '.') cnt++;
        if (nex == now) st_ad = true;
    }
    if (cnt >= 2 or (cnt == 1 and st_ad)) YES();
    else NO();
}