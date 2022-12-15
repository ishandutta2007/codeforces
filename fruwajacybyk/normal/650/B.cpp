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

const int max_n = 500005;

char s[max_n];

const int INF = 1e9+1;
int c1, c2;
int T,n;

int cost(int k) {
	return ((s[k]=='w') ? c2 : 0) + 1;
}

int best = 0;

void rob() {
	lint ct = cost(0);
	int act = 1;
	while (ct + c1 + cost(act) <= T) {
		ct += c1 + cost(act);
		act++;

	}
	best = max(best, act);
	ct += (c1)*1LL*(act-1);
	int al = n-1;
	FORD(i,act-1,0) {
		while (ct + c1 + cost(al) <= T) {
			ct += c1 + cost(al);
			al--;
		}
		best = max(best, i+1 + (n-1)-al);
		ct -= (2*c1 + cost(i));
	}
}

int main() {
	read(n);
	read2(c1, c2);
	read(T);
	scanf("%s", s);
	
	lint wszystkie = cost(0);
	FOR(i,1,n) wszystkie = wszystkie + cost(i) + c1;
	if (wszystkie <= T) {
		printf("%d\n", n);
		return 0;
	}
	if ( cost(0) > T) {
		printf("0\n");
		return 0;
	}
	rob();
	for(int i = 1; i < n-i; i++) {
		swap(s[i], s[n-i]);
	}
	rob();
	printf("%d\n", best);



}