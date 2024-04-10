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
//const ll MOD = 1000000007;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { -1,0, 1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
// #define mp make_pair
// #define endl '\n'


ll mod_pow(ll x, ll p, ll M = MOD) {
  ll a = 1;
  while (p) {
    if (p % 2)
      a = a*x%M;
    x = x*x%M;
    p /= 2;
  }
  return a;
}

ll mod_inverse(ll a, ll M = MOD) {
  return mod_pow(a, M - 2, M);
}


ll dp[55][55][55];
int n, m;
ll s = 0;

ll rec(int i, int j, int k, int x, vi &p) {
  if (dp[i][j][k] != -1) {
    return dp[i][j][k];
  }
  if (i + j + k == m) {
    dp[i][j][k] = (p[0] + x*i) % MOD;
    return dp[i][j][k];
  }

  ll ans = 0;
  ll bunbo = s + x * i + j - k;
  ans += rec(i + 1, j, k, x, p) * (p[0] + x*i % MOD) % MOD * mod_inverse(bunbo) % MOD;
  ans %= MOD;
  ans += rec(i, j + 1, k, x, p) * (p[1] + j) % MOD * mod_inverse(bunbo) % MOD;
  ans %= MOD;
  ans += rec(i, j, k + 1, x, p) * (p[2] - k) % MOD * mod_inverse(bunbo) % MOD;
  ans %= MOD;
  ans = (ans + MOD) % MOD;
  dp[i][j][k] = ans;
  return ans;
}

int main() {
  cin >> n >> m;
  vi a(n);
  rep (i, n) {
    cin >> a[i];
  }

  vl w(n);
  vi p(3);
  rep (i, n) {
    cin >> w[i];
    s += w[i];
    if (a[i] == 0) {
      p[2] += w[i];
    }
    else {
      p[1] += w[i];
    }
  }

  rep (x, n) {
    vi pp = p;
    if (a[x] == 0) {
      pp[2] -= w[x];
    }
    else {
      pp[1] -= w[x];
    }
    pp[0] = w[x];
    rep (i, 55) rep (j, 55) rep (k, 55) dp[i][j][k] = -1;
    rec(0, 0, 0, 2*a[x] - 1, pp);
    cout << dp[0][0][0] << endl;
  }
}