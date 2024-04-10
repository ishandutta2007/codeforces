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
const ll INF = 1e18;
const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define mp make_pair


int main(){
  fio();
  int n, m, k;
  cin >> n >> m >> k;
  vector<bool> used(n);
  vector<set<int> > G(n);
  vi x(m), y(m);
  rep (i, m) {
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
    G[x[i]].insert(y[i]);
    G[y[i]].insert(x[i]);
  }
  bool flag = true;
  int nokori = n;
  vector<int> ans;
  queue<int> q;
  rep (u, n) {
    if (G[u].size() < k && !used[u]) {
      q.push(u);
      used[u] = true;
      nokori--;
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto itr = G[u].begin(); itr != G[u].end(); itr++) {
      int v = *itr;
      G[v].erase(u);
      if (G[v].size() < k && !used[v]) {
        q.push(v);
        used[v] = true;
        nokori--;
      }
    }
    G[u].clear();
  }
  ans.push_back(nokori);
  rrep (i, m) {
    G[x[i]].erase(y[i]);
    G[y[i]].erase(x[i]);
    queue<int> q;
    if (G[x[i]].size() < k && !used[x[i]]) {
      q.push(x[i]);
      used[x[i]] = true;
      nokori--;
    }
    if (G[y[i]].size() < k && !used[y[i]]) {
      q.push(y[i]);
      used[y[i]] = true;
      nokori--;
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto itr = G[u].begin(); itr != G[u].end(); itr++) {
        int v = *itr;
        G[v].erase(u);
        if (G[v].size() < k && !used[v]) {
          q.push(v);
          used[v] = true;
          nokori--;
        }
      }
      G[u].clear();
    }
    ans.push_back(nokori);
  }
  rrep (i, m) {
    cout << ans[i] << endl;
  }
}