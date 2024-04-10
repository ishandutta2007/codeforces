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

const int max_n = 200005;
int n;
VI v;
VI g[max_n];
int pos[max_n];
VI lans;
int was[max_n];

bool cmp(int a, int b) {
	return (pos[a] < pos[b]);
}

void bfs() {
	VI que;
	que.pb(0);
	int it = 0;
	was[0] = 1;
	while (it != que.size()) {
		int v = que[it];
		it++;
		lans.pb(v);
		sort(all(g[v]), cmp);
		FORE(i, g[v]) {
			if (was[*i]) continue;
			was[*i] = 1;
			que.pb(*i);
		}
	}
}

int main() {
	read(n);
	FOR(i,0,n-1) {
		make2(a, b);
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	readv(v, n);
	FOR(i,0,n) v[i]--;
	FOR(i,0,n) pos[v[i]] = i;
	bfs();
	FOR(i,0,n) {
		if (lans[i] != v[i]) {
			printf("No\n");
			return 0;
		}
	} 
	printf("Yes\n");
	return 0;
}