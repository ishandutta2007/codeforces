#include "bits/stdc++.h"

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl

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
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i,n) for(ll i=1;i<=(ll)(n);i++)
#define rrep(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(ll)(n);i>0;i--)
#define REP(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = 1e18;
const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define mp make_pair



int main() {
  fio();
  int n;
  cin >> n;
  vl a(n);
  bool plus = false, minus = false;
  rep (i, n) {
    cin >> a[i];
    if (a[i] >= 0) {
      plus = true;
    }
    if (a[i] <= 0) {
      minus = true;
    }
  }
  if (n == 1) {
    cout << a[0] << endl;
    return 0;
  }
  if (!plus) {
    ll ans = 0;
    ll ma = -INF;
    rep (i, n) {
      ma = max(ma, a[i]);
      ans -= a[i];
    }
    ans += 2 * ma;
    cout << ans << endl;
  }
  else if (!minus) {
    ll ans = 0;
    ll mi = INF;
    rep (i, n) {
      mi = min(mi, a[i]);
      ans += a[i];
    }
    ans -= 2 * mi;
    cout << ans << endl;
  }
  else {
    ll ans = 0;
    rep (i, n) {
      if (a[i] >= 0) {
        ans += a[i];
      }
      else {
        ans -= a[i];
      }
    }
    cout << ans << endl;
  }
}