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

#define max_n 200005

int n;
int par[max_n];
VI g[max_n];
int ile[max_n];
int pier[max_n];
int drug[max_n];

void dfs(int v,int kto){
  FOR(i,0,g[v].size()) dfs(g[v][i],1-kto);
  ile[v] = 0;
  if(g[v].size()==0){
    ile[v] = 1;
    pier[v] = 1;
    drug[v] = 1;
    return;
  }
  FOR(i,0,g[v].size()) ile[v]+=ile[g[v][i]];
  if(kto==0){
    int best = -1e9;
    FOR(i,0,g[v].size()) best = max(best,pier[g[v][i]]-ile[g[v][i]]);
    pier[v] = ile[v]+best;

    int sum = 0;
    FOR(i,0,g[v].size()) sum+=drug[g[v][i]];
    drug[v] = sum;
  }
  else{
    int best = 1e9;
    FOR(i,0,g[v].size()) best = min(best,drug[g[v][i]]);
    drug[v] = best;

    int sum = 0;
    FOR(i,0,g[v].size()) sum+=pier[g[v][i]]-1;
    sum++;
    pier[v] = sum;
  }
}

int main(){
  read(n);
  FOR(i,0,n-1){
    make2(a,b); a--; b--;
    g[a].pb(b);
    par[b] = a;
  }
  dfs(0,0);
  printf("%d %d\n",pier[0],drug[0]);
}