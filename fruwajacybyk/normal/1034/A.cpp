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

const int max_n = 100005;

int gcd(int a, int b) {
	return a == 0 ? b : gcd(b%a, a);
}

int minp[15000005];


int main() {
	make(n);
	makev(v,n);
	int d = v[0];
	FOR(i,1,n) d = gcd(d, v[i]);
	FOR(i,0,n) v[i] = v[i]/d;
	FOR(i,0,15000000+1) minp[i] = i;
	for (int i = 2; i <= 15000000;i++) {
		if (minp[i] == i) {
			for (lint j = i * 1LL * i; j<= 1.5*1e7; j+=i) {
				minp[j] = i;
			}
		}
	}
	map<int, int> dupa;
	FOR(i,0,n) {
		int x = v[i];
		while (x!=1) {
			int p = minp[x];
			dupa[p]++;
			while (x%p == 0) x = x/p;
		}
	}
	int best = 0;
	FORE(i, dupa) {
		best = max(best, i->nd);
	}
	if (best == 0) {
		printf("-1\n");
	} else {
		printf("%d\n", n - best);
	}
}