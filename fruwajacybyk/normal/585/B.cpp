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

int n;
char s[3][205];
int daleko[3][205];

int dx[]={-1,0,1};

void dfs(int i, int j) {
  if(j==n-1) {
    daleko[i][j] = 2;
    return;
  }
  if( daleko[i][j] != -1) return;

  if((3*j+1<n && s[i][3*j+1]=='.') || (3*j+1>=n)) {
    FOR(u,0,3) {
      int ni = i+dx[u];
      if(ni>=0 && ni<=2) {
        bool ok = true;
        FOR(k,1,4) {
          if(3*j+k < n && s[ni][3*j+k]!='.') ok = false;
        }
        if(ok) {
          dfs(ni, j+1);
          daleko[i][j] = max(daleko[i][j], daleko[ni][j+1]);
        }
      }
    }
  }
  daleko[i][j] = max(daleko[i][j], 1);
}


int main(){
  make(z); while(z--) {
    read(n);
    make(k);
    FOR(i,0,3) scanf("%s",s[i]);
   
    FOR(i,0,n) FOR(j,0,3) daleko[j][i] = -1;
    FOR(j,0,3) {
      if(s[j][0]=='s') {
        dfs(j,0);
      if(daleko[j][0]==2) printf("YES\n");
      else printf("NO\n");
      }
    } 
  }

    
}