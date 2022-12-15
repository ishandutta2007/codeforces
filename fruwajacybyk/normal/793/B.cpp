#include <bits/stdc++.h>
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()
 
#define PII pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define pb push_back
#define lint long long int
#define VI vector<int>
 
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
#define jeb fflush(stdout)

 
using namespace std;

int n, m;
char s[1005][1005];
int ile[1005][1005];
set<int> kiers[1005][1005];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

int sx, sy;
int tx, ty;

bool inside(int a, int b) {
	return (a>=0 && a<n && b>=0 && b<m);
}

void dfs(int a, int b, int kier) {
	FOR(j,0,4) {
		int na = a + dx[j];
		int nb = b + dy[j];
		if (!inside(na, nb)) continue;
		if (s[na][nb]=='*') continue;
		
		int hp = ile[a][b] + (kier == j ? 0 : 1);
		if (ile[na][nb] > hp) {
			ile[na][nb] = hp;
			kiers[na][nb].clear();
			kiers[na][nb].insert(j);
			dfs(na, nb, j);
		} else if (ile[na][nb] == hp) {
			if (kiers[na][nb].find(j) != kiers[na][nb].end()) continue;
			kiers[na][nb].insert(j);
			dfs(na, nb, j);
		}
	}
}

int main() {
	read2(n, m);
	FOR(i,0,n) {
		scanf("%s", s[i]);
	}
	FOR(i,0,n) FOR(j,0,m) ile[i][j] = 4;
	FOR(i,0,n) FOR(j,0,m) {
		if (s[i][j] == 'S') sx = i, sy = j;
		if (s[i][j] == 'T') tx = i, ty = j;
	}
	ile[sx][sy] = 0;
	FOR(j,0,4) {
		kiers[sx][sy].insert(j);
		dfs(sx,sy,j);
	}
	if (ile[tx][ty] <= 2) printf("YES\n");
	else printf("NO\n");
/*	
	FOR(i,0,n) {
		FOR(j,0,m) {
			printf("%d ", ile[i][j]);
		}
		printf("\n");
	}*/
}