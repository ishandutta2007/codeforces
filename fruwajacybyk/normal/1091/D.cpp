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

const int mod = 998244353;

int inv[1000006];


int main () {
	make(n);
	if (n <= 2) {
		printf("%d\n",n);
		return 0;
	}
	inv[1] = 1;
	FOR(i,2,n) {
		int q = mod/i;
		inv[i] = (inv[mod%i] * 1LL * (mod - q))%mod;
	}
	int ans = 1;
	FOR(i,2,n+1) ans = (ans*1LL*i)%mod;
	int loc = ans;
	loc = (loc * 1LL * inv[2]) % mod;
	loc = (loc * 1LL * (n-2))% mod;
	ans = (ans + loc)% mod;
	FOR(k,3,n) {
		loc = (loc * 1LL * inv[k])%mod;
		loc = (loc * 1LL * (k-1)) % mod;
		loc = (loc * 1LL * inv[k-2])%mod;
		loc = (loc * 1LL * (n-k))%mod;
		loc = (loc * 1LL * inv[(n-k+1)])%mod;
		ans = (ans + loc)% mod;
	}
	printf("%d\n", ans);
}