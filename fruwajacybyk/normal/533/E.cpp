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

char s[max_n];
char t[max_n];


int main(){
  make(n);
  scanf("%s",s);
  scanf("%s",t);
  if(n==1){
    if(s[0]==t[0]) printf("51\n");
    else printf("2\n");
    return 0;
  }
  int fd = -1, ld = -1;
  FOR(i,0,n){
    if(s[i]!=t[i]){
      fd = i;
      break;
    }
  }
  FORD(i,n-1,0){
    if(s[i]!=t[i]){
      ld = i;
      break;
    }
  }
  if(fd==-1){
    int ans = 0;
    FOR(i,0,n) if(i==0 || s[i]!=s[i-1]){
      ans++; 
    }
    ans +=50;
    FOR(i,1,n){
      if(s[i]==s[i-1]) ans+=25;
      else ans+=24;
    }
    printf("%d\n",ans);
  }
  else{
    if(fd==ld){
      printf("2\n"); return 0;
    }
    int ans = 0;
    bool ok = true;
    FOR(i,fd,ld){
      if(s[i]!=t[i+1]) ok = false;
    }
    if(ok) ans++;
    ok = true;
    FOR(i,fd,ld){
      if(t[i]!=s[i+1]) ok = false;
    }
    if(ok) ans++;


    printf("%d\n",ans);
  }

  
}