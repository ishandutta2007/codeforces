#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int
#define VI vector<lint>

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

const int max_n = 1e5+5;

int n, N;
lint dp[max_n];
VI rt;
lint INF = 1e9*1LL*1e9;

void init() {
	for(N=1; N<n; N<<=1);
	rt = VI(N<<1);
	FOR(i,0,N) rt[i+N] = INF;
	FORD(i,N-1,1) rt[i] = min(rt[2*i], rt[2*i+1]);
}

lint rob(int v, int x, int y, int l, int r) {
	if (l > r) return INF;
	if (l==x && r==y) {
		return rt[v];
	}
	int mid = (x+y)/2;
	return min(rob(2*v,x,mid,l,min(r,mid)), rob(2*v+1,mid+1,y,max(l,mid+1),r));
}

void change(int v, lint x) {
	rt[v+N] = x;
	for(int j = (v+N)>>1; j; j>>=1) {
		rt[j] = min(rt[2*j], rt[2*j+1]);
	}
}

int main() {
	read(n);
	makev(v, n-1);
	FOR(i,0,n-1) v[i]--;
	init();
	dp[n-1] = 0;
	change(n-1, n-1);
	FORD(i,n-2,0) {
		dp[i] = rob(1,0,N-1,i+1,v[i]) - i+(n-1-v[i]);
		change(i, dp[i]+i);
	}
	lint sum = 0;
	FOR(i,0,n) sum += dp[i];
	printf("%I64d\n", sum);
}