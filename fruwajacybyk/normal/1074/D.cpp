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
#define jeb() fflush(0);

using namespace std;

int last = 0;

map<int, int> fup;
map<int, int> xop;


int fufind(int x) {
	if (fup.find(x) == fup.end()) {
		fup[x] = x;
		xop[x] = 0;
		return x;
	}
	vector<int> w;
	while (fup[x] != x) {
		w.pb(x);
		x = fup[x];
	}
	if (w.empty()) return x;
	int loc = xop[w.back()];
	FORD(i,w.size()-2,0) {
		loc ^= xop[w[i]];
		xop[w[i]] = loc;
		fup[w[i]] = x;
	}
	return x;
}

void inform(int l, int r, int x) {
	if (fufind(l-1) == fufind(r)) return;
	int l1 = fufind(l-1);
	int r1 = fufind(r);
	fup[l1] = r1;
	xop[l1] = xop[l-1]^xop[r]^x;
}

void rob(int l, int r) {
		if (fufind(l-1) != fufind(r)) {
			printf("-1\n");
			last = 1;
			return;
		} else {
			int a = xop[l-1];
			int b = xop[r];
			printf("%d\n", a^b);
			last = a^b;
		}
}

int main() {
	make(q);
	while (q--) {
		make(t);
		if (t == 1) {
			make3(l1,r1,x1);
			int l = l1^last;
			int r = r1^last;
			int x = x1^last;
			if (l > r) swap(l, r);
			inform(l, r, x);
			
		} else {
			make2(l1,r1);
			l1 ^= last;
			r1 ^= last;
			if (l1 > r1) swap(l1, r1);
			rob(l1, r1);
		}
	}
}