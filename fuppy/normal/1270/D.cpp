#include <bits/stdc++.h>

#include <unistd.h>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
 
 
typedef long long ll;
#define int ll
 
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
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
//const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

class UnionFind {
public:
  int n;
  vi par; //
  vi ran; //
  vi num; //
  int g; // group
 
  UnionFind(int _n) {
    n = _n;
    g = n;
    par.resize(n); ran.resize(n); num.resize(n);
    for (int i = 0; i < n; i++) {
      par[i] = i; ran[i] = 0; num[i] = 1;
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
    g--;
  }
 
  //xy
  bool same(int x, int y) {
    return find(x) == find(y);
  }
 
};


ll dist(pii a, pii b) {
  return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

pii ask(vi a) {
  cout << "? ";
  rep (i, a.size()) {
    cout << a[i] + 1 << " ";
  }
  cout << endl << flush;
  int pos, x;
  cin >> pos >> x;
  pos--;
  return pii(pos, x);
}

signed main() {
  fio();
  int n, k;
  cin >> n >> k;
  vi a(n, -1);

  vi as;
  rep (i, k) {
    as.push_back(i);
  }
  pii ix = ask(as);
  a[ix.first] = ix.second;
  int ai = ix.first;
  
  as.clear();
  rep (i, k + 1) {
    if (a[i] != -1) continue;
    as.push_back(i);
  }
  ix = ask(as);
  a[ix.first] = ix.second;
  int bi = ix.first;

  vector<bool> ika(k + 1);
  if (a[ai] < a[bi]) ika[ai] = true;
  
  rep (i, k + 1) {
    if (i == ai or i == bi) continue;
    as.clear();
    rep (j, k + 1) {
      if (i == j) continue;
      as.push_back(j);
    }
    pii ix = ask(as);
    int ci = ix.first;
    int x = ix.second;
    if (ci == bi) {
      if (a[ai] < a[bi]) {
        ika[i] = true;
      }
      else {
        ika[i] = false;
      }
    }
    else {
      if (a[ai] < a[bi]) {
        ika[i] = false;
      }
      else {
        ika[i] = true;
      }
    }
    //DEBUG_VEC(ika);
  }
  int cnt = 0;
  rep (i, k + 1) {
    if (i == ai) continue;
    if (i == bi) continue;
    if (ika[i]) cnt++;
  }
  cout << "! " << cnt + 1 << endl << flush;
}