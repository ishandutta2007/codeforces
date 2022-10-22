#include <bits/stdc++.h>
 
//#include <unistd.h>
//#include <iostream>
 
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
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
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
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
//const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'
 
vii G;
vi c;
vi a;
vi p;
vi depth;

void dfs1(int now, int par, int d) {
  depth[now] = d;
  for (int ch: G[now]) {
    if (ch == par) continue;
    dfs1(ch, now, d + 1);
  }
}

pii cd;
int u;
void dfs2(int now, int par) {
  pii res = pii(c[now], depth[now]);
  if (a[now] == -1 and cd > res) {
    cd = res;
    u = now;
  }
  for (int ch: G[now]) {
    if (ch == par) continue;
    dfs2(ch, now);
  }
}

signed main() {
  fio();
  int n;
  cin >> n;
  G.resize(n); c.resize(n);
  a.resize(n); depth.resize(n);
  p.resize(n);
  fill(all(a), -1);

  int root;
  rep (i, n) {
    cin >> p[i] >> c[i];
    p[i]--;
    if (p[i] == -1) root = i;
    else {
      G[i].push_back(p[i]);
      G[p[i]].push_back(i);
    }
  }

  dfs1(root, -1, 0);

  rep1 (x, n) {
    cd = pii(inf, inf);
    dfs2(root, -1);
    if (c[u] != 0) {
      cout << "NO" << endl;
      return 0;
    }
    a[u] = x;
    while (u != -1) {
      c[u]--;
      u = p[u];
    }
  }
  cout << "YES" << endl;
  rep (i, n) {
    cout << a[i] << " ";
  }
  cout << endl;
}