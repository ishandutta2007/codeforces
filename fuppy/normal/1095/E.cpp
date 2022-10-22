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
#define Sp(p) cout<<setprecision(15)<< fixed<<p;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt1 = 0, cnt2 = 0;
  char x;
  rep (i, n) {
    if (s[i] == '(') {
      cnt1++;
    }
    else {
      cnt2++;
    }
  }
  if (cnt1 - cnt2 == 2) {
    x = '(';
  }
  else if (cnt2 - cnt1 == 2) {
    string t;
    rrep (i, n) {
      if (s[i] == '(') {
        t += ')';
      }
      else {
        t += '(';
      }
    }
    s = t;
    x = '(';
  }
  else {
    cout << 0 << endl;
    return 0;
  }
  vi num(n + 1);
  rep (i, n) {
    if (s[i] == '(') {
      num[i + 1] = num[i] + 1;
    }
    else {
      num[i + 1] = num[i] - 1;
    }
    if (num[i + 1] < 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  vi mi(n);
  rrep (i, n) {
    if (i == n - 1) {
      mi[i] = num[n];
    }
    else {
      mi[i] = min(mi[i + 1], num[i + 1]);
    }
  }
  /*
  DEBUG(s);
  DEBUG_VEC(num);
  DEBUG_VEC(mi);
  //*/
  int cnt = 0;
  rep (i, n) {
    if (s[i] == '(' && mi[i] >= 2) {
      cnt++;
    }
  }
  cout << cnt << endl;
}