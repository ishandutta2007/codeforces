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



 
#define P pair<ll, pii>
 
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  vector<vector<pll>> G(n);
  rep (i, m) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--; v--;
    G[u].emplace_back(w, v);
    G[v].emplace_back(w, u);
  }
 
  rep (i, n) {
    sort(all(G[i]));
  }
  
  priority_queue<P, vector<P>, greater<P>> pq;
  vector<map<int, ll> > dist(n);
  rep (i, n) {
    rep (j, G[i].size()) {
      int v = G[i][j].second;
      pq.push(make_pair(G[i][j].first, pii(i, v)));
      dist[i][v] = G[i][j].first;
    }
  }
 
  k *= 2;
  set<pii> pst;
  ll last_cost = 0;
  while (k > 0) {
    P now = pq.top();
    pq.pop();
    ll cost = now.first;
    pll uv = now.second;
    if (dist[uv.first][uv.second] < cost) continue;
    if (pst.count(uv)) continue;
    pst.insert(uv);
    /*
    DEBUG(k);
    DEBUG(cost);
    DEBUG(uv);
    //*/
    last_cost = cost;
    k--;
    int u = uv.second;
    int cnt = 0;
    rep (i, G[u].size()) {
      int v = G[u][i].second;
      if (v == uv.first) continue;
      if (pst.count(pii(uv.first, v))) continue;
      ll ncost = cost + G[u][i].first;
      if (dist[uv.first][v] == 0 or dist[uv.first][v] > ncost) {
        dist[uv.first][v] = ncost;
        pq.push(make_pair(ncost, pii(uv.first, v)));
        cnt++;
        if (cnt >= k) break;
      }
    }
  }
  cout << last_cost << endl;
}