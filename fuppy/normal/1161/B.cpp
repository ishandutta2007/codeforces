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
using ull = unsigned long long;
using P = pair<ll, ull>;

class RollingHash {
public:
  const ll B1 = 100000007;
  const ll M = 1000000009;
  const ull B2 = 100000009;
  
  int n;
  vi s;
  vector<P> hash;
  vector<ll> Bpower1;
  vector<ull> Bpower2;

  RollingHash(vi s) :s(s), n(s.size()) {
    hash.resize(n + 1); Bpower1.resize(n + 1); Bpower2.resize(n + 1);
    Bpower1[0] = Bpower2[0] = 1;
    for (int i = 0; i < n; i++) {
      hash[i + 1].first = (hash[i].first * B1 % M + s[i]) % M;
      hash[i + 1].second = hash[i].second * B2 + s[i];
      Bpower1[i + 1] = Bpower1[i] * B1 % M;
      Bpower2[i + 1] = Bpower2[i] * B2;
    }
  }

  //S[l, r)
  P part(int l, int r) {
    P res = hash[r];
    (res.first -= hash[l].first * Bpower1[r - l] % M) %= M;
    res.first = (res.first + M) % M;
    res.second -= hash[l].second * Bpower2[r - l];
    return res;
  }
};

int main() {
  fio();
  int n, m;
  cin >> n >> m;
  vii G(n);
  rep (i, m) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  rep (i, n) {
    rep (j, G[i].size()) {
      G[i][j] = (G[i][j] - i + n) % n;
    }
    sort(all(G[i]));
  }

  vector<P> h(n);
  rep (i, n) {
    h[i] = RollingHash(G[i]).part(0, G[i].size());
  }

  //DEBUG_VEC(h);

  vi div;
  rep1 (i, n - 1) {
    if (n % i == 0) div.push_back(i);
  }

  rep (i, div.size()) {
    int d = div[i];
    bool flag = true;
    for (int u = 0; u < n; u++) {
      int v = (u + d) % n;
      if (h[u] != h[v]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}