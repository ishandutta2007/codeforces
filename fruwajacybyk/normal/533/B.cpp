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
VI g[max_n];
int eff[max_n];

lint b[max_n];
lint ch[max_n];

void dfs(int i){
  if(g[i].size()==0){
    b[i] = eff[i];
    ch[i] = 0;
  }
  else{
    FOR(j,0,g[i].size()) dfs(g[i][j]);
    int mam = 0;
    lint minst = 1e9;
    minst *= 100000LL;
    lint sum = 0;
    FOR(j,0,g[i].size()){
      int v = g[i][j];
      if(b[v] >= ch[v]){
        mam = 1-mam;
        minst = min(minst,b[v]-ch[v]);
      }
      if(b[v] < ch[v]){
        minst = min(minst,ch[v]-b[v]);
      }
      sum+= max(b[v],ch[v]);
    }
    lint x,y;
    if(mam==0){
      x = sum;
      y = sum-minst;
    }
    else{
      y = sum;
      x = sum-minst;
    }
    ch[i] = x;
    b[i] = max(x+eff[i],y);
  } 
}

int main(){
  read(n);
  FOR(i,0,n){
    make2(a,b);
    eff[i] = b;
    a--;
    if(a!=-2) g[a].pb(i);
  }
  dfs(0);
  printf("%I64d\n",max(b[0],ch[0]));

}