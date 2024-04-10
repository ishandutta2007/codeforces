#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}

using namespace std;

const int max_n = 1e5+5;

int n,m;
VI g[max_n];
VI val[max_n];
int parent[max_n][20];
VI mini[max_n][20];
int level[max_n];
int lg[max_n];

void dfs(int v, int poziom) {
  level[v] = poziom;
  FORE(i,g[v]) {
    if(level[*i] == -1) {
      parent[*i][0] = v;
      dfs(*i, poziom+1);
    }
  }
}

VI merge(VI& v1, VI& v2) {
  VI ans;
  int i = 0, j = 0;
  while(i<v1.size() && j<v2.size()) {
    if(v1[i] < v2[j]){
      ans.pb(v1[i]); i++;
    } else {
      ans.pb(v2[j]); j++;
    }
    if(ans.size()==10) return ans;
  }
  while (i<v1.size()) {
    ans.pb(v1[i]);
    if(ans.size()==10) return ans;
    i++;
  }
  while (j<v2.size()) {
    ans.pb(v2[j]);
    if(ans.size()==10) return ans;
    j++;
  }
  return ans;
}

void prepare() {
  parent[0][0] = 0;
  FOR(i,1,19) {
    FOR(j,0,n) {
      parent[j][i] = parent[parent[j][i-1]][i-1];
    }
  }
  FOR(i,0,n) {
      FOR(j,0,min((int)val[i].size(),10)) mini[i][0].pb(val[i][j]);   
  }
  
  FOR(i,1,19) {
    FOR(j,0,n) {
      mini[j][i] = merge(mini[j][i-1], mini[parent[j][i-1]][i-1]);
    }
  }
  
}

int lca(int u, int v) {
  if(level[v] > level[u]) return lca(v,u);
  int x = level[u]-level[v];
  while (level[v] != level[u]) {
    u = parent[u][lg[x & (-x)]];
    x ^= (x&(-x));
  }
  
  int j = 18;
  while(1) {
    while(j >=0 && parent[v][j] == parent[u][j]) j--;
    if(j==-1) {
      if(u==v) return u;
      else return parent[u][0];
    } else { 
      v = parent[v][j];
      u = parent[u][j];
    }
  }
}

void rob(int u, int v, int a) {
    if(u==v) {
      printf("%d ",min(a,(int)val[u].size()));
      FOR(i,0,min(a,(int)val[u].size())) printf("%d ",val[u][i]);
      printf("\n");
      return ;
    }
   int w = lca(u,v);
   VI ans = val[w];
   int x = level[u]-level[w];
   while (x!=0) {
    VI ans2 = merge(ans, mini[u][lg[x & (-x)]]);
    u = parent[u][lg[x&(-x)]];
    x^=(x&(-x));
    ans = ans2;
   }
   x = level[v] - level[w];
   while (x!=0) {
    VI ans2 = merge(ans, mini[v][lg[x & (-x)]]);
    v = parent[v][lg[x&(-x)]];
    x^=(x&(-x));
    ans = ans2;
   }
   printf("%d ", min((int)ans.size(), a));
   FOR(i,0,min((int)ans.size(),a)) {
     printf("%d ", ans[i]);
   }
   printf("\n");
}

int main(){
  FOR(i,0,20) {
    if( (1<<i) < max_n) lg[1<<i] = i;
  }
  read2(n,m);
  make(q);
  FOR(i,0,n-1) {
    make2(a,b);
    a--; b--;
    g[a].pb(b); g[b].pb(a);
  }
  FOR(i,0,m) {
    make(a); a--;
    val[a].pb(i+1);
  }
  FOR(i,0,n) sort(all(val[i]));
  FOR(i,0,n) level[i] = -1;
  dfs(0,0);
  prepare();

  while(q--) {
    make3(u,v,a);
    u--; v--;
    rob(u,v,a);
  }
  return 0;
}