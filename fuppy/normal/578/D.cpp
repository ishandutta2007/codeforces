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


int main() {
  fio();
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;

  vi right(n);
  int l = 0;
  while (l < n) {
    if (l == n - 1) {
      right[l] = l;
      break;
    }
    string temp;
    temp += s[l];
    temp += s[l + 1];
    int r = l + 2;
    while (r < n) {
      if (s[r] == s[r - 2]) {
        r++;
      }
      else {
        break;
      }
    }
    for (int i = l; i < r; i++) {
      right[i] = r - 1;
    }
    l = r - 1;
  }
  //DEBUG_VEC(right);
  
  // rep (i, n) {
  //   string temp;
  //   right[i] = i + 1;
  //   for (int j = i + 2; j < n; j++) {
  //     int idx = (j - i) % 2;
  //     if (s[j] == temp[idx]) right[i] = j;
  //     else break;
  //   }
  // }
  
  ll ans = (m - 1) * n;

  vi a(n);
  for (int i = n - 1; i > 0; i--) {
    if (s[i] == s[i - 1]) continue;
    ans += i * (m - 1);
    a[i] = 1;
  }
  vi sum(n + 1);
  rep (i, n) sum[i + 1] = sum[i] + a[i];

  //DEBUG_VEC(a);
  //DEBUG_VEC(sum);
  rep (i, n - 1) {
    if (s[i] == s[i + 1]) continue;
    //DEBUG(i);
    //DEBUG(right[i]);
    //DEBUG(sum[right[i] + 1] - sum[i + 1]);
    ans += (n - i - 1) * (m - 1);
    ans -= sum[right[i] + 1] - sum[i + 1];
  }
  
  cout << ans << endl;
  return 0;

  rep (i, n) {
    for (int j = i; j < n; j++) {
      if (i == j) {
        ans += m - 1;
        continue;
      }

      bool f1 = false, f2 = false;
      if (s[i] != s[i + 1]) {
        f1 = true;
        ans += m - 1;
      }
      if (s[j] != s[j - 1]) {
        f2 = true;
        ans += m - 1;
      }
      if (f1 and f2) {
        // char c1 = s[i], c2 = s[i + 1];
        // string temp;
        // for (int k = i; k <= j; k++) {
        //   if ((k - i) % 2 == 0) temp += c1;
        //   else temp += c2;
        // }
        // if (s.substr(i, (j - i + 1)) == temp) {
        //   ans--;
        // }
        if (j <= right[i]) {
          ans--;
        }
      }
    }
  }
}