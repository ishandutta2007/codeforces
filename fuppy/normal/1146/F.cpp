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
//#define mp make_pair

vi p;
vii childs;
vll dp;

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


void dfs(int now, int par) {
  if (childs[now].size() == 0) {
    dp[now][0] = 0;
    dp[now][1] = 0;
    dp[now][2] = 1;
    return;
  }
  ll zen = 1;
  ll mul = 1;
  rep (i, childs[now].size()) {
    int ch = childs[now][i];
    dfs(ch, now);
    (zen *= (dp[ch][0] + dp[ch][1] + dp[ch][2]*2) % MOD) %= MOD;
    (mul *= (dp[ch][0] + dp[ch][2]) % MOD) %= MOD;
  }
  dp[now][0] = 1;
  dp[now][1] = 0;
  rep (i, childs[now].size()) {
    int ch = childs[now][i];
    (dp[now][0] *= (dp[ch][0] + dp[ch][2]) % MOD) %= MOD;
    (dp[now][1] += (dp[ch][1] + dp[ch][2]) % MOD * mul % MOD * mod_inverse((dp[ch][0] + dp[ch][2]) % MOD) % MOD) %= MOD;
  }
  //DEBUG(zen);
  //DEBUG(dp[now][0]);
  //DEBUG(dp[now][1]);
  dp[now][2] = (zen - dp[now][0] - dp[now][1]) % MOD;
  dp[now][2] = (dp[now][2] + MOD) % MOD;
  //DEBUG(dp[now][2]);
}

int main() {
  int n;
  cin >> n;
  p.resize(n);
  p[0] = -1;
  childs.resize(n);

  rep1 (u, n - 1) {
    cin >> p[u];
    p[u]--;
    childs[p[u]].push_back(u);
  }
  rep (i, n) sort(all(childs[i]));

  dp.resize(n);
  rep (i, n) dp[i].resize(3);

  dfs(0, -1);
  cout << (dp[0][0] + dp[0][2]) % MOD << endl;
}