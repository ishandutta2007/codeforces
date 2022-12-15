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

const int max_n = 1e5+5;
const int max_m = 1e6+1e5;
int n, m;
int mod = 1e9+7;

char s[22][max_n];
int cost[max_m];
int ile[max_m];

void walsh_transform(int* v, int start, int meta) {
	if (meta-start==1) return;
	int mid = (meta+start)/2;
	walsh_transform(v, start, mid);
	walsh_transform(v, mid, meta);
	FOR(i,start,mid) {
		int j = mid+i-start;
		int a = v[i];
		int b = v[j];
		v[i] = a + b;
		if (v[i] >= mod) v[i]-=mod;
		v[j] = a-b;
		if(v[j]<0) v[j] += mod;
	}
}

void inv_walsh_transform(int* v, int start, int meta) {
	if (meta-start==1) return;
	int mid = (meta+start)/2;
	inv_walsh_transform(v, start, mid);
	inv_walsh_transform(v, mid, meta);
	FOR(i,start,mid) {
		int j = mid+i-start;
		int a = v[i];
		int b = v[j];
		v[i] = a - b;
		if (v[i] < 0) v[i]+=mod;
		v[j] = a + b;
		if(v[j] >=mod) v[j]-=mod;
		if (v[i] & 1) {
			v[i] = (v[i]+mod)/2;
		} else v[i] = v[i]/2;
		if (v[j] & 1) {
			v[j] = (v[j]+mod)/2;
		} else v[j] = v[j]/2;
	}
}


int main() {
	read2(n, m);
	FOR(i,0,n) {
		scanf("%s", s[i]);
	}
	FOR(i,0,1<<n) {
		cost[i] = min( __builtin_popcount(i), __builtin_popcount((1<<n)-1-i));						
	}
	FOR(j,0,m) {
		int u = 0;
		FOR(i,0,n) if(s[i][j]=='1') u |= (1<<i);
		ile[u]++;
	}
	walsh_transform(cost,0,1<<n);
	walsh_transform(ile ,0,1<<n);
	FOR(i,0,1<<n) {
		cost[i] = (cost[i] * 1LL * ile[i]) % mod;
	}
	inv_walsh_transform(cost, 0, 1<<n);
	int best = n*m;
	FOR(i,0,1<<n) best = min(best, cost[i]);
	printf("%d\n", best);
}