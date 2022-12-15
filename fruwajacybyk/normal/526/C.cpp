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

int main(){
  make3(c,h1,h2);
  make2(w1,w2);
  lint ans = 0;
  int x = 0;
  if(w1==w2){
    printf("%I64d\n",(c/w1)*1LL*max(h1,h2));
    return 0;
  }
  if(w1<w2){
    swap(w1,w2);
    swap(h1,h2);
  }
  if(w2==1){
    lint ans1 = c*1LL*h2;
    lint ans2 = (c/w1)*1LL*h1+(c%w1)*1LL*h2;
    printf("%I64d\n",max(ans1,ans2));
    return 0;
  }
  if(w2==2){
  lint act = 0;
  while(0 <= c){
    ans = max(ans,act+ (c>>1)*1LL*h2);
    c-=w1;
    act+=h1;
  }
  printf("%I64d\n",ans);
  return 0; 
  }
  lint act = 0;
  while(0 <= c){
    ans = max(ans,act+ (c/w2)*1LL*h2);
    c-=w1;
    act+=h1;
  }
  printf("%I64d\n",ans);

}