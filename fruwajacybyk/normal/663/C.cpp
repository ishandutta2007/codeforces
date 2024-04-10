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

#define REP(i,n) FOR(i,0,(n))
 
using namespace std;

const int max_n = 1e6+5;

int n, m;
vector<PII> g[max_n];
int was[max_n];
int sz, gd;
bool ok;
int kolor;

void dfs(int v, int klik, VI& dupa0, VI& dupa1) {
	if (!ok) return;
	sz++; if(klik==0) gd++;
	FORE(i,g[v]) {
		int w = i->st;
		int cc = i->nd;
		if (was[w] == -1) {
			int ja = (kolor == cc) ? 0 : 1;
			ja = (ja + klik)%2;
			was[w] = ja;
			if (ja==0) dupa0.pb(w);
			else dupa1.pb(w);
			dfs(w, ja, dupa0, dupa1);
		} else {
			int kol = (cc+klik+was[w])%2;
			if (kol!=kolor) {
				ok = false;
				return;
			}
		}
	}
}

int rob() {
	FOR(i,0,n) was[i] = -1;
	ok = true;
	int ans = 0;

	FOR(i,0,n) {
		if (was[i] == -1) {
			sz = 0;
			gd = 0;
			VI dupa0, dupa1;
			dupa0.pb(i);
			was[i] = 0;
			dfs(i, 0, dupa0, dupa1);
			ans += min(gd,sz-gd);
			if (gd < sz - gd) {
					FORE(j,dupa0) was[*j] = 1 - was[*j];
					FORE(j,dupa1) was[*j] = 1 - was[*j];
			}
		}
	}
	if (!ok) return -1;
	return ans;
}

int main() {
	read2(n, m);
	FOR(i,0,m) {
		make2(a, b);
		char C = '-';
		while (C!='B' && C!='R') C = getchar();
		int kl = 0;
		if (C=='R') kl=1;
		a--; b--;
		g[a].pb(mp(b,kl));
		g[b].pb(mp(a,kl));
	}
	 int ans1, ans2;
	kolor = 0;
	ans1 = rob();
	kolor = 1;
	ans2 = rob();
	if (ans1 == -1 && ans2==-1) {
		printf("-1\n");
		return 0;
	}
	if (ans1 == -1) ans1 = 1e9;
	if (ans2 == -1) ans2 = 1e9;
	printf("%d\n", min(ans1,ans2));
	kolor = (ans1 < ans2) ? 0 : 1;
	rob();
	FOR(i,0,n) {
		if (was[i]==1) printf("%d ",i+1);
	}
	printf("\n");
}