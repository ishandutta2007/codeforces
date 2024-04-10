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


using namespace std;


map<pair<lint,lint>, lint> mapka;

void inc(lint x, lint y, lint w) {
	if (x==y) return;
	if (x>y) {
		inc(y, x, w);
		return;
	}
	lint pw = 2;
	while(1) {
		if (x > (y/pw)) {
			mapka[mp(x/2, x)]+= w;
			inc(x/2, y, w);
			return;
		}
		if (x < (y/pw)) {
			pw += pw;
			continue;
		}
		if (x==(y/pw)) {
			lint pw2 = pw/2;
			if ( (2*x+1) == y/pw2) {
				mapka[mp(x,2*x+1)] += w;
				inc(2*x+1,y,w);
				return;
			} else {
				mapka[mp(x,2*x)] += w;
				inc(2*x, y, w);
				return;
			}
		} 
	}
}

lint ans(lint x, lint y) {
	if (x==y) return 0;
	if (y < x) return ans(y, x);
	lint pw = 2;
	while(1) {
		if (x > (y/pw)) {
			return mapka[mp(x/2,x)]+ans(x/2, y);
		}
		if (x < (y/pw)) {
			pw += pw;
			continue;
		}
		if (x==(y/pw)) {
			lint pw2 = pw/2;
			if ( (2*x+1) == y/pw2) {
				return mapka[mp(x,2*x+1)] + ans(2*x+1,y);
			} else {
				return mapka[mp(x,2*x)]+ ans(2*x, y);
			}
		} 
	}
}

int main() {
	make(q);
	while (q--) {
		make(type);
		if (type == 1) {
			lint u, v;
			int w;
			scanf("%I64d %I64d %d\n",&u,&v,&w);
			inc(u,v,w);
		} else {
			lint u, v;
			scanf("%I64d %I64d",&u,&v);
			printf("%I64d\n", ans(u,v));
		}
	}
}