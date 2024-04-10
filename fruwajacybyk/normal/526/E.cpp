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

#define max_n 1000005

int za[max_n];

int main(){
  make2(n,q);
  makev(v,n);
  lint sum = 0;
  FOR(i,0,n) sum += v[i];
  FOR(i,0,n) v.pb(v[i]);
  while(q--){
    lint b; scanf("%I64d",&b);
    if(b>=sum){
      printf("1\n");
      continue;
    }
    lint act = 0;
    int aj = 0, nxt = 0;
    while(aj!=n){
      while(act+v[nxt]<=b){
        act+=v[nxt]; nxt++;
      }
      za[aj] = nxt;
      act-=v[aj];
      aj++;
    } 
    int mini = n+5, dla = -1;
    aj = 0;
    int ans = 0;
    VI kto; kto.pb(0);
    while(aj<n){
      aj = za[aj];
      kto.pb(aj);
      ans++;
    }
    FOR(i,0,kto.size()-1){
      mini = min(mini,kto[i+1]-kto[i]);
      if(mini==kto[i+1]-kto[i]) dla = i;
    }
    FOR(kk,kto[dla],kto[dla+1]+1){
      int k = kk%n;
      int myans = 0;
      bool okr = false; 
      int ja = k;
      while(!okr || ja<k){
        ja = za[ja];
        myans++;
        if(ja>=n && !okr) okr = true, ja=ja%n;
      }
      ans = min(ans,myans);
    }
    printf("%d\n",ans);
  }
    
}