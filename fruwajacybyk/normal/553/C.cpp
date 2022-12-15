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

#define max_n 100005

int mod = 1e9+7;

vector<PII> g[max_n];
int od[max_n];

bool dfs(int v,int p,int lub){
  od[v] = (od[p]+lub)%2;
  FOR(i,0,g[v].size()){
    int w = g[v][i].st;
    if(od[w]==-1) {if(!dfs(w,v,g[v][i].nd)) return false;}
    else if(od[w]==2){
      if(od[v]!=g[v][i].nd) return false;
    }
    else if( (od[v]+g[v][i].nd)%2 != od[w]) return false;
  }
  return true;
}

int main(){
  make2(n,m);
  FOR(i,0,m){
    make3(a,b,c);
    a--; b--;
    c = 1-c;
    g[a].pb(mp(b,c));
    g[b].pb(mp(a,c));
  }
  FOR(i,0,n) od[i] = -1;
  int sp = 0;
  FOR(i,0,n){
    if(od[i]==-1){
      od[i] = 2;
      sp++;
      FOR(j,0,g[i].size()){
        if(!dfs(g[i][j].st,i,g[i][j].nd)){
          printf("0\n");
          return 0;
        }
      }
    }
  }
  int ans = 1;
  FOR(i,0,sp-1) ans = (ans+ans)%mod;
  printf("%d\n",ans);

}