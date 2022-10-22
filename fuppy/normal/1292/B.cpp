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

ll dist(pll a, pll b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

signed main() {
  fio();
  vl xy0(2), a(2), b(2);
  rep (i, 2) {
    cin >> xy0[i];
  }
  rep (i, 2) {
    cin >> a[i];
  }
  rep (i, 2) {
    cin >> b[i];
  }

  pll s;
  ll t;
  cin >> s.first >> s.second;
  cin >> t;

  vector<pll> xy(1, pll(xy0[0], xy0[1]));
  while (xy.back().first <= 4e16 and xy.back().second <= 4e16) {
    ll x = xy.back().first, y = xy.back().second;
    ll nx = a[0] * x + b[0], ny = a[1] * y + b[1];
    xy.push_back(pll(nx, ny));
  }
  //DEBUG(xy.size());
  //DEBUG_VEC(xy);

  ll ans = 0;
  int n = xy.size();
  rep (_, 2) {
    rep (i, xy.size()) {
      ll cost = 0;
      cost += dist(xy[i], s);
      if (cost > t) continue;
      ll score = 1;
      chmax(ans, score);
      ll ma = 0;
      for (int j = 0; j <= i; j++) {
        ll ncost = cost + dist(xy[j], xy[i]);
        if (ncost > t) continue;
        ll nscore = score + i - j;
        chmax(ans, nscore);
        for (int k = i + 1; k < n; k++) {
          ll nncost = ncost + dist(xy[j], xy[k]);
          if (nncost > t) continue;
          ll nnscore = nscore + k - i;
          chmax(ans, nnscore);
        }
      }
    }
    reverse(all(xy));
  }
  cout << ans << endl;
}