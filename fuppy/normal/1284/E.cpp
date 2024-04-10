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
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
//const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'
 
 
int syou(pll a) {
  int x = a.first, y = a.second;
  if (x > 0 and y >= 0) return 1;
  else if (x <= 0 and y > 0) return 2;
  else if (x < 0 and y <= 0) return 3;
  else return 4;
}
 
 
bool cmp(pll a, pll b) {
  int ta = syou(a), tb = syou(b);
  if (ta != tb) return ta < tb;
  ll ax = a.first, ay = a.second;
  ll bx = b.first, by = b.second;
  if (ta == 2 or ta == 3) {
    ax *= -1; ay *= -1;
    bx *= -1; by *= -1;
  }
  ay *= bx; by *= ax;
  return ay < by;
}
 
ll solve(vector<pll> xy) {
  ll n = xy.size();
  ll ng = 0;
  int m = 0;
  double offset = 0;
  int offset_t = 0;
  rep (i, n) {
    int t1 = syou(xy[i]);
    t1 += 2;
    double theta = atan2(xy[i].second, xy[i].first);
    if (theta < 0) theta += 2 * pi;
    theta += pi;
    while (true) {
      int t2 = syou(xy[m]);
      if (t2 + offset_t > t1) break;
      if (t2 + offset_t == t1) {
        pll a = xy[i];
        a.first *= -1; a.second *= -1;
        pll b = xy[m];
        assert(syou(a) == syou(b));
        if (cmp(a, b)) break;
      }
      //double theta2 = atan2(xy[m].second, xy[m].first);
      //if (theta2 < 0) theta2 += 2 * pi;
      //if (theta2 + offset >= theta) break;
      m++;
      if (m == n) {
        m = 0;
        offset += 2 * pi;
        offset_t += 4;
      }
    }
    ll x = (m - i - 1 + n) % n;
    ll y = n - 1 - x;
    if (x >= 3) {
      ng += x * (x - 1) * (x - 2) / 6;
    }
    if (y >= 3) {
      ng += y * (y - 1) * (y - 2) / 6;
    }
  }
  assert(ng % 2 == 0);
  ng /= 2;
  return n * (n - 1) * (n - 2) * (n - 3) / 24 - ng;
}
 
signed main() {
  fio();
  int n;
  cin >> n;
 
  vector<pll> xy(n);
  rep (i, n) {
    cin >> xy[i].first >> xy[i].second;
  }
 
 
  ll ans = 0;
  rep (i, n) {
    pll ori = xy[i];
    vector<pll> xy2;
    rep (j, n) {
      if (i == j) continue;
      xy2.push_back(xy[j] - ori);
    }
    sort(all(xy2), cmp);
    //DEBUG_VEC(xy2);
    ans += solve(xy2);
    //DEBUG(ans);
  }
  cout << ans << endl;
}