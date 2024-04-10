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
//const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define mp make_pair

bool cmp(pair<pll, int> a, pair<pll, int> b) {
  if (a.first.second - a.first.first < b.first.second - b.first.first) {
    return true;
  }
  else {
    return false;
  }
}

int main() {
  fio();

  int n, m;
  cin >> n >> m;
  vector<pair<pll, int> > a(n);
  ll sumb = 0;
  rep (i, n) {
    cin >> a[i].first.first >> a[i].first.second;
    sumb += a[i].first.first;
    a[i].second = i;
  }
  auto b = a;
  sort(all(a), cmp);
  //DEBUG_VEC(a);
  vii G(n);
  rep (i, m) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  /*
  rep (i, n) {
    G[i].push_back(i);
  }
  //*/
  
  vl ans(n);
  ll suma = 0;
  rep (i, n) {
    sumb -= a[i].first.first;
    //DEBUG(suma);
    //DEBUG(sumb);
    int j = a[i].second;
    ans[j] = suma + (ll)i * a[i].first.first + sumb + (ll)(n - 1 - i) * a[i].first.second;
    suma += a[i].first.second;
  }
  //DEBUG_VEC(ans);
  rep (i, n) {
    rep (j, G[i].size()) {
      int u = i, v = G[i][j];
      //DEBUG(u);
      //DEBUG(v);
      ll mi = min(b[u].first.first + b[v].first.second, b[u].first.second + b[v].first.first);
      ans[u] -= mi;
    }
  }
  rep (i, n) {
    cout << ans[i] << " ";
  }
  cout << endl;
      
}