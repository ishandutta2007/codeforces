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
//#define mp make_pair

ll gcd(ll a, ll b) {
  if (b > a) {
    swap(a, b);
  }
  ll r = a%b;
  while (r != 0) {
    a = b;
    b = r;
    r = a%b;
  }
  return b;
}


int main() {
  ll m, a, b;
  cin >> m >> a >> b;
  ll can = 1;
  ll ans = 1;

  priority_queue<ll, vector<ll>, greater<ll> > pq;
  vector<int> state(10000000);
  state[0] = 2;
  state[a] = 1;
  pq.push(a);
  ll g = __gcd(a, b);
  ll i = 1;
  while (true) {
    while (pq.top() <= i) {
      int u = pq.top();
      pq.pop();
      state[u] = 2;
      can++;
      int v = u - b;
      if (v >= 0 && state[v] == 0) {
        state[v] = 1;
        pq.push(v);
      }
      v = u + a;
      if (v < 10000000 && state[v] == 0) {
        state[v] = 1;
        pq.push(v);
      }
    }
    ans += can;
    if (i >= a && i >= b && i % g == 0 && can == i / g + 1) break;
    if (i == m) break;
    i++;
  }
  if (i != m) {
    ll c = (m + 1) / g;
    //DEBUG(c);
    ll add = g * c * (c + 1) / 2;
    add -= g * (can - 1) * can / 2;
    add -= can;
    add += (m - (c*g - 1)) * (m / g + 1);
    ans += add;
  }
  cout << ans << endl;
}