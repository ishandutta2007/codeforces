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
//#define endl '\n'

int n, m;
vi c;

vll hyou(555, vl(555, -1));

ll f(int l, int r) {
  if (r == l) return 1;
  if (r - l == 1) return 1;
  if (hyou[l][r] >= 0) return hyou[l][r];
  //DEBUG(pii(l, r));

  
  int mi = inf;
  int idx = -1;
  for (int i = l; i < r; i++) {
    if (mi > c[i]) {
      mi = c[i];
      idx = i;
    }
  }

  ll temp = 0;
  for (int j = idx + 1; j <= r; j++) {
    // (add *= f(idx, idx + 1)) %= MOD;
    ll temp2 = 1;

    if (j - (idx + 1) >= 2) {
      (temp2 *= f(idx + 1, j)) %= MOD;
    }
    if (r - j >= 2) {
      (temp2 *= f(j, r)) %= MOD;
    }
    temp = (temp + temp2) % MOD;
  }
  
  
  ll res = 0;
  for (int i = l; i <= idx; i++) {
    ll add = 1;
    if (i - l >= 2) {
      (add *= f(l, i)) %= MOD;
    }
    if (idx - i >= 2) {
      (add *= f(i, idx)) %= MOD;
    }
    /*
    for (int j = idx + 1; j <= r; j++) {
      ll temp = 1;
      // (add *= f(idx, idx + 1)) %= MOD;
      if (j - (idx + 1) >= 2) {
        (temp *= f(idx + 1, j)) %= MOD;
      }
      if (r - j >= 2) {
        (temp *= f(j, r)) %= MOD;
      }
      res += temp * add % MOD;
      res %= MOD;
    }
    //*/
    res += temp * add;
    res %= MOD;
  }
  hyou[l][r] = res;
  //DEBUG(res);
  
  return res;
}

int main() {
  fio();
  cin >> n >> m;
  assert(n == m);
  c.resize(n);
  rep (i, n) cin >> c[i];

  ll ans = f(0, n) % MOD;
  ans = (ans + MOD) % MOD;
  cout << ans << endl;
}