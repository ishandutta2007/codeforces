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
  vl kai;
  kai.push_back(0);
  ll now = 1;
  for (ll i = 1; i < 100; i++) {
    kai.push_back(kai[i - 1] + now);
    now *= 4;
    if (kai[i] > 5*INF) break;
  }
  vl pow2(33);
  pow2[0] = 1;
  rep1 (i, pow2.size() - 1) {
    pow2[i] = pow2[i - 1] * 2;
  }
  
  //DEBUG_VEC(kai);
  //DEBUG(kai.size());
  int q;
  cin >> q;
  while (q--) {
    ll n, k;
    cin >> n >> k;
    if (n >= kai.size()) {
      cout << "Yes " << n - 1 << " ";
      continue;
    }
    if (kai[n] < k) {
      cout << "No" << endl;
      continue;
    }
    if (n == 2) {
      if (k <= 2) {
        cout << "Yes " << 1 << endl;
      }
      else if (k == 3) {
        cout << "No" << endl;
      }
      else {
        cout << "Yes " << 0 << endl;
      }
      continue;
    }
    ll ma = 0;
    rep1 (i, n) {
      ma += pow2[i] - 1 + (pow2[i] * 2 - 3) * kai[n - i];
      if (ma >= k) {
        cout << "Yes " << n - i << endl;
        break;
      }
    }
  }
}