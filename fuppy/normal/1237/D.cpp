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

struct P {
  int x, y, z, i;
  P(){}
  P(int x, int y, int z, int i):x(x), y(y), z(z), i(i){}
  bool operator<( const P& ot ) const {
    pair<pii, int> me = make_pair(pii(x, y), z);
    pair<pii, int> ai = make_pair(pii(ot.x, ot.y), ot.z);
    return me < ai;
  }
};

vi a;

class UnionFind {
public:
  int n;
  vi par; //
  vi ran; //
  vi num; //
  vi high; //
  int g; // group
 
  UnionFind(int _n) {
    n = _n;
    g = n;
    par.resize(n); ran.resize(n); num.resize(n); high.resize(n);
    for (int i = 0; i < n; i++) {
      par[i] = i; ran[i] = 0; num[i] = 1;
      high[i] = a[i];
    }
  }
 
  //
  int find(int x) {
    if (par[x] == x) {
      return x;
    }
    else {
      return par[x] = find(par[x]);
    }
  }
 
  //xy
  void unite(int x, int y) {
    x = find(x); y = find(y);
    int numsum = num[x] + num[y];
    int highest = max(high[x], high[y]);
    if (x == y) {
      return;
    }
    if (ran[x]<ran[y]) {
      par[x] = y;
    }
    else {
      par[y] = x;
      if (ran[x] == ran[y]) {
        ran[x]++;
      }
    }
    num[x] = num[y] = numsum;
    high[x] = high[y] = highest;
    g--;
  }
 
  //xy
  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

pair<int, pii> merge(pair<int, pii> a, pair<int, pii> b) {
  return make_pair(max(a.first, b.first), pii(a.second.first, b.second.second));
}

int main() {
  fio();
  int n;
  cin >> n;
  a.resize(n);
  int ma = 0, mi = inf;
  rep (i, n) {
    cin >> a[i];
    chmin(mi, a[i]);
    chmax(ma, a[i]);
  }

  if (mi > (ma - 1) / 2) {
    rep (i, n) {
      cout << -1 << " ";
    }
    cout << endl;
    return 0;
  }

  deque<pair<int, pii>> xlr;
  int nokori = n;
  vi end(n, -1);
  rep (_i, 3*n) {
    int i = _i % n;
    if (xlr.size() == 0) {
      xlr.push_back(make_pair(a[i], pii(_i, _i + 1)));
    }
    else {
      while (xlr.size() > 0) {
        int ma = xlr[0].first;
        pii lr = xlr[0].second;

        if (a[i] <= (ma - 1) / 2) {
          for (int j = lr.first; j < lr.second; j++) {
            if (end[j % n] == -1) {
              end[j % n] = _i;
              nokori--;
            }
          }
          xlr.pop_front();
        }
        else {
          break;
        }
      }
      pair<int, pii> now = make_pair(a[i], pii(_i, _i + 1));
      while (xlr.size() > 0 and xlr.back().first <= a[i]) {
        now = merge(xlr.back(), now);
        xlr.pop_back();
      }
      xlr.push_back(now);
    }
    //DEBUG_VEC(xlr);
    //DEBUG_VEC(end);
    if (nokori == 0) break;
  }

  rep (i, n) {
    cout << end[i] - i << " ";
  }
  cout << endl;
}