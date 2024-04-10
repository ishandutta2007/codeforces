#include <bits/stdc++.h>

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
const ll INF = 1e18;
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair


int main() {
  fio();
  ll n, s;
  cin >> n >> s;
  if (s == n * (n + 1) / 2) {
    cout << "Yes" << endl;
    for (int i = 2; i <= n; i++) {
      cout << i - 1 << " ";
    }
    cout << endl;
    return 0;
  }
  if (s < n + (n - 1) || s > n * (n + 1) / 2) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  ll x;
  for (x = 2; x < n; x++) {
    ll n2 = n;
    ll sum = 0;
    ll d = 1, k = 1;
    while (n2 > 0) {
      if (n2 < k) {
        sum += d * n2;
        n2 = 0;
      }
      else {
        sum += d * k;
        n2 -= k;
      }
      k *= x;
      d++;
    }
    if (sum <= s) {
      break;
    }
  }
  vii a(n);
  ll u = 0;
  ll d = 0, k = 1;
  ll sum = 0;
  while (u < n) {
    if (u + k - 1 < n) {
      rep (i, k) {
        a[d].push_back(u);
        u++;
        sum += d + 1;
      }
    }
    else {
      ll u2 = u;
      rep (i, n - u2) {
        a[d].push_back(u);
        u++;
        sum += d + 1;
      }
    }
    d++;
    k *= x;
  }
  assert(sum <= s);
  vi p(n, -1);
  rep1 (i, n - 1) {
    p[i] = (i - 1) / x;
  }
  ll max_d = d;
  ll _d = d;
  for (int d = _d - 1; d > 0; d--) {
    if (sum == s) break;
    int j = a[d].size() - 1;
    while (j > 0) {
      int u = a[d][j];
      a[d].pop_back();
      if (max_d - d + sum <= s) {
        sum += max_d - d;
        a[max_d].push_back(u);
        p[u] = a[max_d - 1][0];
        max_d++;
      }
      else {
        ll add = s - sum;
        sum += add;
        a[d + add].push_back(u);
        p[u] = a[d + add - 1][0];
      }
      j--;
      if (sum == s) break;
    }
    if (sum == s) break;
  }
  rep1 (i, n - 1) {
    cout << p[i] + 1 << " ";
  }
  cout << endl;
}