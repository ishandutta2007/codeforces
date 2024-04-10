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


int bit[500005];

void add(int a, int ile) {
	while (a < 500002) {
		bit[a] += ile;
		a += (a & (-a));
	}
}

int ask(int a) {
	int ans = 0;
	while (a > 0) {
		ans += bit[a];
		a -= (a & (-a));
	}
	return ans;
}

int main () {
	make(n);
	makev(v, n);
	sort(all(v));
	int par = 0;	
	FOR(i,0,500002) bit[i] = 0;
	FOR(i,0,n) {
		add(v[i]+1, 1);
		par = (par + v[i]) % 2;
	}
	lint ub = n;
	lint lb = 0;

	lint pref = 0;
	lint mini = 0;
	FOR(i,0,n) mini += min(v[i], 1);
	
	ub = min(ub, mini + pref);

	FOR(k,2,n+2) {
		pref += v[n+1-k];
		mini -= min(v[n+1-k], k-1);
		
		add(v[n+1-k]+1, -1);
		mini += n+1-k-ask(k);

		lint loc = k*1LL*(k-1) - pref + mini;
		ub = min(ub, loc);
	}
	
	pref = v[n-1];
	mini = 0;
	FOR(i,0,n-1) mini += min(v[i],1);
	FOR(i,0,n-1) add(v[i] + 1, 1);

	lb = max(lb, pref-mini);

	FOR(k,2,n+1) {
		pref += v[n-k];
		mini -= min(v[n-k], k-1);
		
		add(v[n-k] + 1, -1);
		mini += (n-k-ask(k));

		lint loc = pref -k*1LL*(k-1) - mini;
		lb = max(lb, loc);
	}
	if (lb % 2 != par % 2) lb++;
	if (ub % 2 != par % 2) ub--;
	if (lb > ub) {
		printf("-1\n");
	} else {
		for (lint x = lb; x <= ub; x+=2) {
			printf("%lld ", x);
		}
		printf("\n");
	}

}