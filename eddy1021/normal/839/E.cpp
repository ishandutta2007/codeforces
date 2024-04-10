#include <bits/stdc++.h>
using namespace std;
#define N 99
#define FZ(X) memset(X,0,sizeof(X))
struct MaxClique {
  static const int MV = 210;
  int V , ans , dp[MV];
  int el[MV][MV/30+1], s[MV][MV/30+1];
  vector<int> sol;
  void init(int v) {
    V = v; ans = 0;
    FZ(el); FZ(dp);
  }
  /* Zero Base */
  void addEdge(int u, int v) {
    if(u > v) swap(u, v);
    if(u == v) return;
    el[u][v/32] |= (1<<(v%32));
  }
  bool dfs(int v, int k) {
    int c = 0, d = 0;
    for(int i=0; i<(V+31)/32; i++) {
      s[k][i] = el[v][i];
      if(k != 1) s[k][i] &= s[k-1][i];
      c += __builtin_popcount(s[k][i]);
    }
    if(c == 0) {
      if(k > ans) {
        ans = k;
        sol.clear();
        sol.push_back(v);
        return 1;
      }
      return 0;
    }
    for(int i=0; i<(V+31)/32; i++) {
      for(int a = s[k][i]; a ; d++) {
        if(k + (c-d) <= ans) return 0;
        int lb = a&(-a), lg = 0;
        a ^= lb;
        while(lb!=1) {
          lb = (unsigned int)(lb) >> 1;
          lg ++;
        }
        int u = i*32 + lg;
        if(k + dp[u] <= ans) return 0;
        if(dfs(u, k+1)) { 
          sol.push_back(v); 
          return 1;
        }
      }
    }
    return 0;
  }
  int solve() {
    for(int i=V-1; i>=0; i--) {
      dfs(i, 1);
      dp[i] = ans;
    }
    return ans;
  }
} solver;
int n , k;
int main(){
  cin >> n >> k;
  solver.init( n );
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 , x ; j < n ; j ++ ){
      cin >> x;
      if( x ) solver.addEdge( i , j );
    }
  int mx = solver.solve();
  double per = (double)k / mx;
  double ans = per * per * mx * ( mx - 1 ) * 0.5;
  cout << fixed << setprecision( 12 ) << ans << endl;
}