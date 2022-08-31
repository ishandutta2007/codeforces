#include <bits/stdc++.h>

#define int long long

#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define rep1(i, n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x, y) x=min(x,y)
#define chmax(x, y) x=max(x,y)
using namespace std;

template< class S, class T >
ostream &operator<<(ostream &o, const pair< S, T > &p) { return o << "(" << p.fs << "," << p.sc << ")"; }

template< class T >
ostream &operator<<(ostream &o, const vector< T > &vc)
{
  o << "sz = " << vc.size() << endl << "[";
  for(const T &v:vc) o << v << ",";
  o << "]";
  return o;
}

int N;
vector< int > G[30];
int xs[30], ys[30];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int v, int p, int x, int y, int dep, int di)
{
  xs[v] = x, ys[v] = y;
  int d = 1LL << (31 - dep);
  int ndi = 0;
  for(int u:G[v])
    if(u != p) {
      if((ndi + 2) % 4 == di) ndi++;
      dfs(u, v, x + dx[ndi] * d, y + dy[ndi] * d, dep + 1, ndi);
      ndi++;
    }
}

signed main()
{
  cin >> N;
  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].pb(b);
    G[b].pb(a);
  }

  for(int i = 0; i < N; i++) {
    if(G[i].size() > 4) {
      cout << "NO" << endl;
      exit(0);
    }
  }


  dfs(0, -1, 0, 0, 0, -1);
  vector< int > X, Y;
  rep(i, N) X.pb(xs[i]), Y.pb(ys[i]);
  sort(all(X));
  sort(all(Y));
  X.erase(unique(X.begin(), X.end()), X.end());
  Y.erase(unique(Y.begin(), Y.end()), Y.end());
  rep(i, N) xs[i] = lower_bound(all(X), xs[i]) - X.begin(), ys[i] = lower_bound(all(Y), ys[i]) - Y.begin();
  rep(i, N) xs[i] *= 2, ys[i] *= 2;

  cout << "YES" << endl;
  rep(i, N) {
    cout << xs[i] << " " << ys[i] << endl;
  }
  return(0);
}