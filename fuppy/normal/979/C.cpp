#include <bits/stdc++.h>

using namespace std;
 
#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl
 
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
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define in(x, a, b) a <= x && x < b
const int inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000007;
//const ll mod = 1000000009;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p <<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };





const int N = 300010;
vii G(N);
ll bee, flower;
vi subnum(N);
ll n, x, y;

int dfs0(int now, int parent) {
  int res = -1;
  rep (i, G[now].size()) {
    if (G[now][i] == parent) {
      continue;
    }
    if (G[now][i] == y) {
      return now;
    }
    res = max(res, dfs0(G[now][i], now));
  }
  return res;
}

int dfs1(int now, int parent) {
  int cnt = 1;
  rep (i, G[now].size()) {
    if (G[now][i] == parent) {
      continue;
    }
    cnt += dfs1(G[now][i], now);
  }
  subnum[now] = cnt;
  return cnt;
}

int main() {
  cin >> n >> x >> y;
  x--; y--;
  bool flag = false;
  rep (i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    if (pii(u, v) == pii(x, y) || pii(u, v) == pii(y, x)) {
      flag = true;
    }
    G[u].push_back(v); G[v].push_back(u);
  }

  if (!flag) {
    int root = dfs0(x, -1);
    //DEBUG(root);
    dfs1(root, -1);
    flower = subnum[x];
    bee = subnum[y];
  }
  else {
    dfs1(x, -1);
    bee = subnum[y];
    flower = n - bee;
  }
  //DEBUG(flower); DEBUG(bee);
  cout << n * (n - 1) - flower * bee << endl;
}