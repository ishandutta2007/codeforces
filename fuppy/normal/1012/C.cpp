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
const ll INF = 2e18;
const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);

#define vlll vector<vll>
vlll dp(2, vll(5020, vl(3, INF)));

int main () {
  fio();
  int n;
  cin >> n;
  vl h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  h.push_back(0);
  dp[0][0][1] = 0;
  for (int i = 0; i < n; i++) {
    int i0 = i % 2;
    for (int j = 0; j < 5020; j++) {
      for (int k = 0; k < 3; k++) {
        dp[1 - i0][j][k] = INF;
      }
    }
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 3; k++) {
        if (dp[i0][j][k] >= INF / 2) {
          continue;
        }
        ll pre, now;
        if (k == 0) {
          pre = h[i - 1];
          now = min(h[i], pre - 1);
          chmin(dp[1 - i0][j][1], dp[i0][j][k] + max(now - h[i + 1] + 1, 0LL));
          if (now >= h[i + 1]) {
            chmin(dp[1 - i0][j][2], dp[i0][j][k]);
          }
        }
        else if (k == 1) {
          if (i == 0) {
            pre = 0;
          }
          else {
            pre = min(h[i - 1], h[i] - 1);
          }
          now = h[i];
          int nex = h[i + 1];
          chmin(dp[1 - i0][j + 1][0], dp[i0][j][k] + max(0LL, nex - now + 1));
          chmin(dp[1 - i0][j][1], dp[i0][j][k] + max(now - nex + 1, 0LL));
          if (now >= nex) {
            chmin(dp[1 - i0][j][2], dp[i0][j][k]);
          }
        }
        else {
          pre = h[i - 1];
          now = h[i];
          int nex = h[i + 1];
          chmin(dp[1 - i0][j][1], dp[i0][j][k] + max(0LL, now - nex + 1));
          if (now >= nex) {
            chmin(dp[1 - i0][j][2], dp[i0][j][k]);
          }
        }
      }
    }
  }
  ll mi = INF;
  vl ans(n / 2 + 5);
  for (int j = (n + 1) / 2; j > 0; j--) {
    for (int k = 0; k < 3; k++) {
      mi = min(mi, dp[n % 2][j][k]);
    }
    ans[j] = mi;
  }
  for (int i = 1; i <= (n + 1) / 2; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;      
}