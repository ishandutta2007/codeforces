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

VI g[max_n];

lint ans = 0;
int ile = 1;

int sp[max_n];
int d[max_n];
int nrsp;
int x[2];

void dfs(int v,int p,int a){
  sp[v] = a;
  d[v] = p;
  x[p]++;
  FORE(i,g[v]){
    int w = *i;
    if(sp[w]==-1) dfs(w,1-p,a);
    else{
      if(d[w]==d[v]) ile = 0;
    }
  }
}

int main(){
  make2(n,m);
  FOR(i,0,m){
    make2(a,b); a--; b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  if(m==0){
    printf("3 %I64d\n",(n*1LL*(n-1)*1LL*(n-2))/6);
    return 0;
  }
  bool dwa = true;
  FOR(i,0,n){
    if(g[i].size()>=2) dwa = false;
  }
  if(dwa){
    printf("2 %I64d\n",m*1LL*(n-2));
    return 0;
  }
  FOR(i,0,n) sp[i] = -1;
  nrsp = 0;
  FOR(i,0,n){
    if(sp[i]==-1){
      x[0] = x[1] = 0;
      dfs(i,0,nrsp);
      ans += (x[0]*1LL*(x[0]-1))/2 + (x[1]*1LL*(x[1]-1))/2;
      nrsp++;
      if(ile==0){
        printf("0 1\n");
        return 0;
      }
    }
  }
  printf("1 %I64d\n",ans);

  



}