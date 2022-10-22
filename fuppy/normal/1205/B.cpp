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
//#define endl '\n'

int ans = inf;
vii G;
int n;

void search(int root) {
  vi used(n);
  used[root] = true;
  using P = pair<int, pii>;
  queue<P> qu;
  qu.push(make_pair(0, pii(root, -1)));
  vi dist(n, inf);
  dist[root] = 0;
  while (not qu.empty()) {
    int cost = qu.front().first;
    int now = qu.front().second.first, par = qu.front().second.second;
    qu.pop();
    rep (i, G[now].size()) {
      if (G[now][i] == par) continue;
      int nex = G[now][i];
      if (dist[nex] == inf) {
        dist[nex] = cost + 1;
        qu.push(make_pair(cost + 1, pii(nex, now)));
      }
      else {
        chmin(ans, dist[nex] + cost + 1);
      }
    }
  }
}


int main() {
  cin >> n;
  vl a;
  rep (i, n) {
    ll temp;
    cin >> temp;
    if (temp != 0) a.push_back(temp);
  }
  n = a.size();

  vl num(62);
  rep (i, n) {
    ll mask = 1;
    rep (j, 62) {
      if (a[i] & mask) {
        num[j]++;
        if (num[j] == 3) {
          cout << 3 << endl;
          return 0;
        }
      }
      mask <<= 1;
    }
  }

  G.resize(n);
  rep (i, n) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] & a[j]) {
        G[i].push_back(j);
        G[j].push_back(i);
      }
    }
  }

  rep (i, n) {
    search(i);
  }

  if (ans >= inf / 2) {
    cout << -1 << endl;
  }
  else {
    cout << ans << endl;
  }
}