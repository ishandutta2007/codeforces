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
// #define endl '\n'

int n;
vi a, b;

int solve1() {
  set<int> te;
  rep (i, n) {
    if (a[i] >= 0) {
      te.insert(a[i]);
    }
  }
  
  int res = 0;
  int nex = b.back() + 1;
  while (nex < n) {
    if (te.count(nex)) {
      te.insert(b[res]);
      res++;
      nex++;
    }
    else {
      res = -1;
      break;
    }
  }
  return res;
}

int main() {
  fio();
  cin >> n;
  a.resize(n); b.resize(n);
  
  rep (i, n) {
    cin >> a[i];
    a[i]--;
  }
  rep (i, n) {
    cin >> b[i];
    b[i]--;
  }
  if (b.back() >= 0) {
    int last = b.back();
    int i = 0;
    bool flag = true;
    for (int j = n - 1 - last; j < n; j++) {
      if (b[j] != i) flag = false;
      i++;
    }
    if (flag) {
      int res = solve1();
      if (res >= 0) {
        cout << res << endl;
        return 0;
      }
    }
  }

  int ng = n - 1, ok = 2 * n;
  while (ng + 1 < ok) {
    int mid = (ng + ok) / 2;
    bool flag =  true;
    rep (i, n) {
      if (b[i] >= 0) {
        int t = b[i] - n + 1 + mid;
        if (t < i + 2) {
          flag = false;
          break;
        }
      }
    }
    if (flag) {
      ok = mid;
    }
    else {
      ng = mid;
    }
  }
  cout << ok << endl;
}