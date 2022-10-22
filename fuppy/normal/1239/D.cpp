#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
 
 
typedef long long ll;
 
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
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { -1,0, 1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
// #define mp make_pair
//#define endl '\n'

void decide_cat(vii &c2p, vii& p2c, vi& cat, int now) {
  cat[now] = true;
  rep (i, c2p[now].size()) {
    int nex = c2p[now][i];
    if (cat[nex] == true) continue;
    decide_cat(c2p, p2c, cat, nex);
  }
}

void decide_people(vii &c2p, vii& p2c, vi& peo, int now) {
  peo[now] = true;
  rep (i, p2c[now].size()) {
    int nex = p2c[now][i];
    if (peo[nex] == true) continue;
    decide_people(c2p, p2c, peo, nex);
  }
}


void solve() {
  int n, m;
  cin >> n >> m;
  vii c2p(n), p2c(n);
  rep (i, m) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    p2c[u].push_back(v);
    c2p[v].push_back(u);
  }
  vi cat(n);
  decide_cat(c2p, p2c, cat, 0);
  int cnt = 0;
  rep (i, n) {
    if (cat[i]) cnt++;
  }
  if (cnt >= 1 and cnt < n) {
    cout << "Yes" << '\n';
    cout << n - cnt << " " << cnt << '\n';
    rep (i, n) {
      if (not cat[i]) {
        cout << i + 1 << " ";
      }
    }
    cout << '\n';
    rep (i, n) {
      if (cat[i]) {
        cout << i + 1 << " ";
      }
    }
    cout << '\n';
    return;
  }

  vi peo(n);
  decide_people(c2p, p2c, peo, 0);

  cnt = 0;
  rep (i, n) {
    if (peo[i]) cnt++;
  }
  if (cnt >= 1 and cnt < n) {
    cout << "Yes" << '\n';
    cout << cnt << " " << n - cnt << '\n';
    rep (i, n) {
      if (peo[i]) {
        cout << i + 1 << " ";
      }
    }
    cout << '\n';
    rep (i, n) {
      if (not peo[i]) {
        cout << i + 1 << " ";
      }
    }
    cout << '\n';
    return;
  }
  cout << "No" << '\n';
  return;
}


int main() {
  fio();
  int t;
  cin >> t;
  rep (i, t) {
    solve();
  }

}