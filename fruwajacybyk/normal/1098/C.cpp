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

lint dp[123456];

lint mini_sum(int branch, int n) {
	dp[0] = 0;
	dp[1] = 1;
	int x = min((n + branch - 1) /branch, n);
	FOR(i,2,x+1) {
		int r = (i-1)%branch;
		dp[i] = r*dp[(i-1)/branch+1] + (branch-r)*dp[(i-1)/branch] + i;
	}
	int r = (n-1)%branch;
	return r*dp[(n-1)/branch+1] + (branch-r)*dp[(n-1)/branch] + n;
}

int bb;
int par[123456];

void dfs(int v, int n1, int n2, lint sek) {

	if (n2 < n1) return;
	int h = n2-n1+1;
	int lewo = (h+bb-1)/bb; int prawo = h;
	while (prawo - lewo > 1) {
		int mid = (prawo + lewo) / 2;
		int r = (h-mid)%(bb-1);
		lint loc = dp[mid] + r*dp[(h-mid)/(bb-1)+ 1] + (bb-1-r)*dp[(h-mid)/(bb-1)];
		if (loc > sek) {
			prawo = mid;
		} else {
			lewo = mid;
		}
	}
	int lans = prawo;
	int r = (h-prawo)%(bb-1);
	lint loc = dp[prawo] + r*dp[(h-prawo)/(bb-1) + 1] + (bb-1-r)*dp[(h-prawo)/(bb-1)];
	if (loc > sek) {
		lans = lewo;
	}
	
	r = (h-lans)%(bb-1);
	loc = r*dp[(h-lans)/(bb-1) + 1] + (bb-1-r)*dp[(h-lans)/(bb-1)];
	
	par[n1] = v;
	dfs(n1,n1+1,n1+lans-1,sek-loc-lans);
	int i1 = (h-lans)/(bb-1)+1;
	int i2 = (h-lans)/(bb-1);
	n1 += lans;
	lint dp1 = dp[(h-lans)/(bb-1)+1];
	lint dp2 = dp[(h-lans)/(bb-1)];
	FOR(i,0,r) {
		par[n1] = v;
		dfs(n1, n1+1, n1+i1-1, dp1-i1);
		n1 += i1;
	}
	if (i2 > 0) {
		FOR(i,0,bb-1-r) {
			par[n1] = v;
			dfs(n1, n1+1, n1+i2-1, dp2-i2);
			n1 += i2;
		}
	}
	

}


int main () {
	make(n);
	lint sum; scanf("%lld", &sum);
	if (2*sum > n*1LL*(n+1)) {
		printf("No\n");
		return 0;
	}
	if (sum < 2*n - 1) {
		printf("No\n");
		return 0;
	}
	if (2*sum == n*1LL*(n+1)) {
		printf("Yes\n");
		FOR(i,1,n) {
			printf("%d ", i);
		}
		printf("\n");
		return 0;
	}
	printf("Yes\n");
	int lewo = 1, prawo = n-1;
	while (prawo - lewo > 1) {
		int mid = (prawo + lewo) / 2;
		if (mini_sum(mid, n) > sum) {
			lewo = mid;
		} else {
			prawo = mid;
		}
	}
	int b = lewo;
	if (mini_sum(lewo, n) > sum) b = prawo;
	dp[0] = 0;
	dp[1] = 1;
	FOR(i,2,n+1) {
		int r = (i-1)%b;
		dp[i] = r*dp[(i-1)/b+1] + (b-r)*dp[(i-1)/b] + i;
	}
	bb = b;
	dfs(1,2,n,sum-n);
	FOR(i,2,n+1) {
		printf("%d ", par[i]);
	}
	printf("\n");
}