#include <bits/stdc++.h>
#include <unistd.h>

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

#define debug(x) {cout <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cout <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
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
#define jeb() fflush(stdout);

using namespace std;

const int max_n = 1e5 + 5;

int n;
VI g[max_n];
int s[max_n];
int ans[max_n];

bool ok = true;

void dfs(int v, int val) {
	if (s[v] == -1) {
		if (g[v].empty()) {
			ans[v] = 0;
			return;
		}
		int mini = s[g[v][0]];
		FORE(i, g[v]) {
			int w = *i;
			mini = min(mini, s[w]);
		}
		if (mini < val) {
			ok = false;
			return;
		}
		ans[v] = mini - val;
		FORE(i, g[v]) {
			int w = *i;
			dfs(w, mini);
		}
	} else {
		if (val > s[v]) {
			ok = false;
			return;
		} else {
			ans[v] = s[v] - val;
			FORE(i, g[v]) {
				int w = *i;
				dfs(w, s[v]);
			}
		}
	}
}


int main () {
	read(n);
	FOR(i,0,n-1) {
		make(a); a--;
		g[a].pb(i+1);
	}
	FOR(i,0,n) {
		make(a); s[i] = a;
	}
	dfs(0,0);
	lint sum = 0;
	if (!ok) {
		printf("-1\n");
	} else {
		FOR(i,0,n) sum += ans[i];
		printf("%lld\n", sum);
	}
}