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

int n,m;
char s[1005][1005];
int dist[1005][1005][3];

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

bool check(int x, int y) {
  return (x>=0 && y>=0 && x<n && y<m && s[x][y]!='#');
}

void bfs(int color) {
  vector<PII> que;
  FOR(i,0,n ) FOR(j,0,m) {
    if(s[i][j]==color+'0') {
      que.pb(mp(i,j));
      dist[i][j][color-1] = 0;
    }
  }
  int act = 0;
  while (act < que.size()) {
    int x = que[act].st, y = que[act].nd; act++;
    FOR(u,0,4) {
      int sx = x+dx[u], sy = y+dy[u];
      if(!check(sx,sy)) continue;
      if(dist[sx][sy][color-1]==-1) {
        dist[sx][sy][color-1] = dist[x][y][color-1]+1;
        que.pb(mp(sx,sy));
      }
    }
  }
}

int main(){
  read2(n,m);
  FOR(i,0,n) scanf("%s",s[i]);
  FOR(i,0,n) FOR(j,0,m) FOR(k,0,3) dist[i][j][k] = -1;
  FOR(i,1,4) bfs(i);
 /* FOR(k,0,3) {
  FOR(i,0,n) {FOR(j,0,m) {
    printf("%d ", dist[i][j][k]);
  } printf("\n"); }
    printf("\n");
  }
*/
  int pos1 = 1e9;
  FOR(i,0,n) FOR(j,0,m) {
    if(s[i][j]>='1' && s[i][j]<='3') continue;
    int loc = 0; bool ok = true;
    FOR(k,0,3) {
      if(dist[i][j][k]==-1) ok = false;
      loc += dist[i][j][k];
    }
    if(ok) pos1 = min(pos1,loc-2);
  }
  FOR(color,0,3) {
    int sum = 0;
    FOR(c2,0,3) {
      if(c2!=color) {
        int d1 = 1e8;
        FOR(i,0,n) FOR(j,0,m) {
          if(s[i][j]=='1'+color) {
            if(dist[i][j][c2]!=-1) d1 = min(d1,dist[i][j][c2]);
          }
        }
        sum +=d1;
  //      debug3(color, c2,d1);
      }
    }
    pos1 = min(pos1, sum-2);
  }
  if(pos1 > n*m) printf("-1\n");
  else printf("%d\n", pos1);
}