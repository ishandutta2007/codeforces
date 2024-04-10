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
int deg[max_n];
int zle[max_n];
int byl[max_n];
int isfort[max_n];

int n;
VI fort;

double fact = 0.;
VI ok;


bool check(double x){
  VI que; 
  FOR(i,0,n) zle[i] = 0, byl[i] = 0;
  FOR(i,0,fort.size()){
    que.pb(fort[i]);
    byl[fort[i]] = 1;
  }
  int u = 0;
  while(u<que.size()){
    int v = que[u]; u++;
    FORE(j,g[v]){
      int w = *j;
      if(byl[w]) continue;
      zle[w]++;
      if( ((deg[w]-zle[w])*1.) < (deg[w]*1.*x)){
        byl[w] = 1;
        que.pb(w);
      }
    }
  }
  VI my;
  double myfact = 1.;
  FOR(i,0,n){
    if(byl[i]==0){
      myfact = min(myfact,(deg[i]-zle[i])*1./deg[i]);
      my.pb(i);
    }
  }
  if(my.size()==0) return false;
  ok = my;
  fact = myfact;
  return true;
}

int main(){
  read(n);
  make2(m,k);
  FOR(i,0,n) isfort[i] = 0;
  FOR(i,0,k){
    make(a); a--;
    fort.pb(a);
    isfort[a] = 1;
  }
  FOR(i,0,n) deg[i] = 0;

  FOR(i,0,m){
    make2(a,b); a--; b--;
    g[a].pb(b);
    g[b].pb(a);
    deg[a]++;
    deg[b]++;
  }


  double best = 0.;
  double l = 0., p =1.0;
  while(p-l>1e-9){
    double mid = (p+l)*0.5;
    if(check(mid)) l = fact;
    else p = mid;
  }
  if(fact==0.){
    printf("1\n");
    FOR(i,0,n){
      if(isfort[i]==0){
        printf("%d\n",i+1);
        return 0;
      }
    }
  }
  printf("%d\n",ok.size());
  FOR(i,0,ok.size()){
    printf("%d ",ok[i]+1);
  }
  printf("\n");

  

}