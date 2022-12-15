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

const int max_n = 1e5+5;

#define max_n 300005

int ile[10];
int mod = 1e9+7;
int mo;
map<int, VI> dp;

int powmod(int a, int b) {
	if (a==0) return 0;
	if (b==0) return 1;
	int sq = powmod(a,b/2);
	sq = (sq * sq) % mo;
	if (b%2==0) return sq;
	return (sq * a) % mo;
}

VI rob(int b) {
	if (dp.find(b) != dp.end()) return dp[b];
	VI v1 = rob(b/2);
	VI v2 = rob((b+1)/2);
	VI ans(mo,0);
	int sh = powmod(10, (b+1)/2);
	FOR(i,0,v1.size()) FOR(j,0,v2.size()) {
		ans[(i * sh + j)%mo] += (v1[i] * 1LL * v2[j]) % mod;
		ans[(i * sh + j)%mo] %= mod;
	}
	dp[b] = ans;
	return ans;
}

int main() {	
	make2(n, b);
	make2(k, x);
	mo = x;
	FOR(i,0,10) ile[i] = 0;
	FOR(i,0,n) {
		make(a); ile[a % mo]++;
	}
	VI aa;
	FOR(i,0,10) aa.pb(ile[i]);
	dp[1] = aa;
	VI ans = rob(b);
	printf("%d\n", ans[k]);
}