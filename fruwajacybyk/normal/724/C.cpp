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

const int max_n = 1e5 + 5;
const int mod = 1e9 + 7;

int gcd(int a, int b) {
	return a == 0 ? b : gcd(b%a, a);
}


lint INF = 1e9 * 1LL * 1e9;

int D;
int n, m, k;
int n1, m1;
int l1, l2;

lint solve(int x, int y) {
	int diff = max(x-y, y-x);
	if (diff%D != 0) return INF;
	diff = (x-y)/D;

	lint u1 = diff * 1LL * l1;
	lint u2 = diff * 1LL * l2;
//	debug2(u1, u2);
	lint odp = u1 * 2LL * m + y;
//	debug(odp);
	lint xxx = n1 * 1LL * m1 * 1LL* D;
	if (odp > 0) odp = odp%xxx;
	if (odp < 0) {
		lint psi = - ( odp/xxx );
		odp += psi * xxx;
		odp += xxx;
		odp %= xxx;
	}
	if (odp == 0) odp = xxx;
	//debug3(x, y, odp);
	return odp;
}

int main() {
	read2(n, m);
	read(k);
	D = gcd(2*n, 2*m);
	n1 = (2*n)/D;
	m1 = (2*m)/D;
	FOR(j,0,n1) {
		if ( (j*1LL*m1)%n1 == 1) {
			l1 = j;
			l2 = ((j*1LL*m1)-1)/n1;
			break;
		}
	}
	//debug(D);
	//debug2(l1, l2);
	FOR(i,0,k) {
		make2(a, b);
		lint u1 = solve(a, b);
		lint u2 = solve(2*n-a, b);
		lint u3 = solve(2*n-a,2*m-b);
		lint u4 = solve(a, 2*m-b);
		lint z = min(min(u1,u2), min(u3,u4));
		if (z==INF) {
			printf("-1\n");
		} else printf("%lld\n", z);
	}
}