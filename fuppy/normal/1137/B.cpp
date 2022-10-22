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
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair


vi z_algorithm(string s) {
  int n = s.size();
  vi a(n);
  int c = 0;
  for (int i = 1; i < n; i++){
    if (i+a[i-c] < c+a[c]) {
      a[i] = a[i-c];
    } else {
      int j = max(0, c+a[c]-i);
      while (i+j < n && s[j] == s[i+j]) ++j;
      a[i] = j;
      c = i;
    }
  }
  a[0] = n;
  return a;
}

int main() {
  fio();
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  vi a = z_algorithm(t);
  //DEBUG_VEC(a);

  int st;
  for (st = 1; st < m; st++) {
    if (a[st] == m - st) break;
  }
  st = m - st;
  //DEBUG(st);
  
  vi num(2);
  rep (i, n) {
    num[s[i] - '0']++;
  }

  string ans;
  int i = 0;
  while (num[0] || num[1]) {
    if (num[t[i] - '0'] > 0) {
      ans += t[i];
      num[t[i] - '0']--;
    }
    else {
      if (num[0] == 0) {
        ans += '1';
        num[1]--;
      }
      else {
        ans += '0';
        num[0]--;
      }
    }
    i++;
    if (i == m) i = st;
  }
  cout << ans << endl;
}