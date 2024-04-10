#include "bits/stdc++.h"

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
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i,n) for(ll i=1;i<=(ll)(n);i++)
#define rrep(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(ll)(n);i>0;i--)
#define REP(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);



//scc : strongly connected component

int n; //
#define N 5010
vii G(N, vi()); //
vii rG(N, vi()); //
vi vr; //
vector<bool> used(N); //
vi cmp(N); //

void add_edge(int from, int to) {
  G[from].push_back(to);
  rG[to].push_back(from);
}

void dfs(int v) {
  used[v] = true;
  for (int i = 0; i < G[v].size(); i++) {
    if (!used[G[v][i]]) {
      dfs(G[v][i]);
    }
  }
  vr.push_back(v);
}

void rdfs(int v, int k) {
  used[v] = true;
  cmp[v] = k;
  for (int i = 0; i < rG[v].size(); i++) {
    if (!used[rG[v][i]]) {
      rdfs(rG[v][i], k);
    }
  }
}


int scc() {
  fill(used.begin(), used.end(), false);
  vr.clear();
  for (int v = 0; v < n; v++) {
    if (!used[v]) dfs(v);
  }
  fill(used.begin(), used.end(), false);
  int k = 0;
  for (int i = vr.size() - 1; i >= 0; i--) {
    if (!used[vr[i]]) rdfs(vr[i], k++);
  }
  return k;
}

int main() {
  int m, s;
  cin >> n >> m >> s;
  s--;
  vi u(m), v(m);
  rep(i, m) {
    cin >> u[i] >> v[i];
    u[i]--; v[i]--;
    add_edge(u[i], v[i]);
  }
  int n2 = scc();
  vii p(n2);
  rep (i, m) {
    if (cmp[v[i]] != cmp[u[i]]) {
      p[cmp[v[i]]].push_back(cmp[u[i]]);
    }
  }
  int ans = 0;
  rep (i, n2) {
    if (p[i].size() == 0 && cmp[s] != i) {
      ans++;
    }
  }
  cout << ans << endl;
}