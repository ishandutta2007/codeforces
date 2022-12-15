#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)

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
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));

using namespace std;
#define max_n 100005

lint dp[100][100];
VI eq[205];
VI geq[205];
VI leq[205];
VI le[205];
VI ge[205];

int n,k;

lint rob(int a,int b, int zost){
  if(dp[a][b]!=-1) return dp[a][b];
  if(zost==0) return 1;
  lint loc = 0;
  // dwa z prawej 
    if(b<2*n-2){
      int x1 = b+1,x2 = b+2;
      bool ok = true;
      FORE(j,eq[x1]) if(*j!=x1 && *j!=x2) ok = false;
      FORE(j,eq[x2]) if(*j!=x1 && *j!=x2) ok = false;
      FORE(j,geq[x1]) if( *j>=a && *j<=b) ok = false;
      FORE(j,geq[x2]) if( *j>=a && *j<=b) ok = false;
      FORE(j,ge[x1])  if( *j>=a && *j<=b+2) ok = false;
      FORE(j,ge[x2])  if( *j>=a && *j<=b+2) ok = false;
      if(ok) loc += rob(a,b+2,zost-1);
    }
  // dwa z lewej
    if(a>1){
      int x1 = a-1, x2 = a-2;
      bool ok = true;
      FORE(j,eq[x1]) if(*j!=x1 && *j!=x2) ok = false;
      FORE(j,eq[x2]) if(*j!=x1 && *j!=x2) ok = false;
      FORE(j,geq[x1]) if( *j>=a && *j<=b) ok = false;
      FORE(j,geq[x2]) if( *j>=a && *j<=b) ok = false;
      FORE(j,ge[x1])  if( *j>=a-2 && *j<=b) ok = false;
      FORE(j,ge[x2])  if( *j>=a-2 && *j<=b) ok = false;
      if(ok) loc += rob(a-2,b,zost-1);
    }
  // z lewej i z prawej
  if(a>0 && b<2*n-1){
    int x1 = a-1, x2 = b+1;
      bool ok = true;
      FORE(j,eq[x1]) if(*j!=x1 && *j!=x2) ok = false;
      FORE(j,eq[x2]) if(*j!=x1 && *j!=x2) ok = false;
      FORE(j,geq[x1]) if( *j>=a && *j<=b) ok = false;
      FORE(j,geq[x2]) if( *j>=a && *j<=b) ok = false;
      FORE(j,ge[x1])  if( *j>=a-1 && *j<=b+1) ok = false;
      FORE(j,ge[x2])  if( *j>=a-1 && *j<=b+1) ok = false;
      if(ok) loc += rob(a-1,b+1,zost-1);
  }
  dp[a][b] = loc;
  return loc;
}


int main(){
  read2(n,k);
  FOR(i,0,k){
    make(a);
    char C1,C2,C3; 
    C1 = getchar();
    C2 = getchar();
    C3 = getchar();
    make(b);
    a--; b--;
    if(C2=='='){
      eq[a].pb(b);
      eq[b].pb(a);
    }
    else if(C2=='>' && C3==' '){
      ge[a].pb(b);
      le[b].pb(a);
    }
    else if(C2=='<' && C3==' '){
      ge[b].pb(a);
      le[a].pb(b);
    }
    else if(C2=='>'){
      geq[a].pb(b);
      leq[b].pb(a);
    }
    else{
      leq[a].pb(b);
      geq[b].pb(a);
    }
  }
  lint ans = 0;
  FOR(s,0,2*n-1){
    FOR(i,0,100) FOR(j,0,100) dp[i][j] = -1;
    bool ok = true;
    if(le[s].size()!=0) ok = false;
    if(le[s+1].size()!=0) ok = false;
    FORE(j,eq[s]) if(s!=*j && s+1!=*j) ok = false;
    FORE(j,leq[s]) if(s!=*j && s+1!=*j) ok = false;
    FORE(j,eq[s+1]) if(s!=*j && s+1!=*j) ok = false;
    FORE(j,leq[s+1]) if(s!=*j && s+1!=*j) ok = false;
    if(!ok) continue;
    ans += rob(s,s+1,n-1);
  }
  printf("%I64d\n",ans);
}