#include <bits/stdc++.h>
 
#include <unistd.h>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
 
 
typedef long long ll;
//#define int ll
 
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
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx_ori[4] = { -1,0, 1,0 }, dy_ori[4] = { 0,1,0,-1 };
int dx[4] = {0, 0, 0, 0}, dy[4] = {0, 0, 0, 0};
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
//const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'
 
vector<set<pll>> to, from;
 
void merge(int u, int v, ll d) {
  if (u == v) return;
  auto itr = to[u].lower_bound(pll(v, -1));
 
  ll d2 = d;
  if (itr != to[u].end() and itr->first == v) {
    d2 += itr->second;
    to[u].erase(itr);
  }
  to[u].insert(pll(v, d2));
  //DEBUG(pll(d, d2));
  d2 = d;
  itr = from[v].lower_bound(pll(u, -1));
  if (itr != from[v].end() and itr->first == u) {
    d2 += itr->second;
    from[v].erase(itr);
  }
  from[v].insert(pll(u, d2));
  //DEBUG(pll(d, d2));
}
 
signed main() {
  int n, m;
  scanf("%d %d", &n, &m);
  to.resize(n); from.resize(n);
  rep (i, m) {
    int u, v;
    ll d;
    scanf("%d %d %lld", &u, &v, &d);
    u--; v--;
    merge(v, u, d);
    //from[u].insert(pii(v, d));
    //to[v].insert(pii(u, d));
  }
 
  bool updated = true;
  while (updated) {
    updated = false;
    //for (int u: vi({1, 0, 2})) {
    rep (u, n) {
      while (to[u].size() > 0 and from[u].size() > 0) {
        updated = true;
        auto itr1 = to[u].begin(), itr2 = from[u].begin();
        pll to1 = *itr1, from1 = *itr2;
        to[u].erase(to[u].begin()); from[u].erase(from[u].begin());
        int tov = to1.first, fromv = from1.first;
        if (tov == fromv) {
          ll d1 = to1.second, d2 = from1.second;
          from[tov].erase(pll(u, d1));
          to[fromv].erase(pll(u, d2));
          if (d1 == d2) {
          }
          else if (d1 > d2) {
            merge(u, tov, d1 - d2);
            //to[u].insert(pii(tov, d1 - d2));
            //from[tov].insert(pii(u, d1 - d2));
          }
          else {
            merge(fromv, u, d2 - d1);
            //from[u].insert(pii(fromv, d2 - d1));
            //to[fromv].insert(pii(u, d2 - d1));
          }
        }
        else {
          ll d1 = to1.second, d2 = from1.second;
          from[tov].erase(pll(u, d1));
          to[fromv].erase(pll(u, d2));
          if (d1 == d2) {
            merge(fromv, tov, d1);
            //to[fromv].insert(pii(tov, d1));
            //from[tov].insert(pii(fromv, d1));
          }
          else if (d1 > d2) {
            merge(u, tov, d1 - d2);
            merge(fromv, tov, d2);
            // to[u].insert(pii(tov, d2));
            // from[tov].insert(pii(u, d2));
            // to[fromv].insert(pii(tov, d1 - d2));
            // from[tov].insert(pii(fromv, d1 - d2));
          }
          else {
            merge(fromv, tov, d1);
            merge(fromv, u, d2 - d1);
            // from[tov].insert(pii(fromv, d1));
            // to[fromv].insert(pii(tov, d1));
            // from[u].insert(pii(fromv, d2 - d1));
            // to[fromv].insert(pii(u, d2 - d1));
          }
        }
      }
    }
  }
  
  int cnt = 0;
  rep (u, n) {
    assert(from[u].size() == 0 or to[u].size() == 0);
    //DEBUG(from[u].size());
    //DEBUG(to[u].size());
    cnt += from[u].size() + to[u].size();
  }
  assert(cnt % 2 == 0);
  cout << cnt / 2 << endl;
 
  rep (u, n) {
    if (from[u].size() > 0) {
      for (auto itr = from[u].begin(); itr != from[u].end(); itr++) {
        int v = itr->first;
        ll d = itr->second;
        printf("%d %d %lld\n", u + 1, v + 1, d);
      }
    }
  }
}