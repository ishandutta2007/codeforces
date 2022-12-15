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

char s[55][55];
char zb[55][55];
vector<PII> figs;
vector<PII> ans;

char dupa[105][150];

bool inside(PII p, int dx,int dy, int n){
  if(p.st+dx<n && p.st+dx>=0 && p.nd+dy<n && p.nd+dy>=0) return true;
  return false;
}

int main(){
  make(n);
  FOR(i,0,n){
    scanf("%s",s[i]);
  }
  FOR(i,0,n) FOR(j,0,n) if(s[i][j]=='o') figs.pb(mp(i,j));
  bool ok = true;
  FOR(i,0,n) FOR(j,0,n) zb[i][j]='.';
  FOR(dx,-n+1,n) FOR(dy,-n+1,n){
    if(dx==0 && dy==0) continue;
    bool moge = true;
    FOR(j,0,figs.size()){
      if(inside(figs[j],dx,dy,n) && s[dx+figs[j].st][dy+figs[j].nd]=='.'){
        moge = false;
        break;
      }
    }
    if(moge){
      ans.pb(mp(dx,dy));
      FOR(j,0,figs.size()){
        if(inside(figs[j],dx,dy,n)){
          zb[figs[j].st+dx][figs[j].nd+dy]='x';
        }
      }
    }
  }
  FOR(i,0,n) FOR(j,0,n) if(zb[i][j]!='x' && s[i][j]=='x') ok = false;
  if(!ok) printf("NO\n");
  else{
    printf("YES\n");
    FOR(j,0,2*n-1) FOR(k,0,2*n-1) dupa[j][k]='.';
    dupa[n-1][n-1]='o';
    FOR(i,0,ans.size()){
      dupa[ans[i].st+(n-1)][ans[i].nd+(n-1)] = 'x';
    } 
    FOR(i,0,2*n-1){
      FOR(j,0,2*n-1){
        printf("%c",dupa[i][j]);
      }
      printf("\n");
    }
  }  

}