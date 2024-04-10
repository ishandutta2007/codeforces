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

double ans = 0;
void solve(vector<double> &a, int l, int r) {
  if (r - l == 1) {
    chmax(ans, abs(a[l]));
    return;
  }

  int m = (l + r) / 2;
  solve(a, l, m);
  solve(a, m, r);

  double mi1 = INF, ma1 = -INF;
  double sum = 0;
  for (int i = m - 1; i >= l; i--) {
    sum += a[i];
    chmin(mi1, sum);
    chmax(ma1, sum);
  }
  
  sum = 0;
  double mi2 = INF, ma2 = -INF;
  for (int i = m; i < r; i++) {
    sum += a[i];
    chmin(mi2, sum);
    chmax(ma2, sum);
  }
  chmax(ans, abs(mi1 + mi2));
  chmax(ans, abs(ma1 + ma2));
}


int main() {
  fio();
  int n;
  cin >> n;
  vector<double> a(n);
  rep (i, n) {
    cin >> a[i];
  }

  double mi = -11111, ma = 11111;
  vector<double> a1(n), a2(n);
  double phi = (1 + sqrt(5)) / 2;
  bool pre_1 = false, pre_2 = false;
  double res_1 = 0, res_2 = 0;
  //double phi = 2;
  rep (_, 80) {
    //DEBUG(make_pair(mi, ma));
    double x1 = (mi * phi + ma) / (1 + phi), x2 = (mi + ma * phi) / (1 + phi);
    rep (i, n) {
      a1[i] = a[i] - x1;
      a2[i] = a[i] - x2;
    }

    double y1;
    if (pre_1) {
      y1 = res_2;
    }
    else {
      ans = 0;
      solve(a1, 0, n);
      y1 = ans;
    }
    //DEBUG(make_pair(x1, y1));

    double y2;
    if (pre_2) {
      y2 = res_1;
    }
    else {
      ans = 0;
      solve(a2, 0, n);
      y2 = ans;
    }
    //DEBUG(make_pair(x2, y2));

    res_1 = y1;
    res_2 = y2;
    if (y1 > y2) {
      mi = x1;
      pre_1 = true;
      pre_2 = false;
    }
    else {
      ma = x2;
      pre_2 = true;
      pre_1 = false;
    }
  }

  //DEBUG(make_pair(mi, ma));
  rep (i, n) a[i] = a[i] - mi;
  ans = 0;
  solve(a, 0, n);
  Sp(ans);
}