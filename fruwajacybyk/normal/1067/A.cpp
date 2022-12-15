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

const int mod = 998244353;
lint dp[205][2][2];
VI v;
int n;

void dbg(int k) {
			int my = k%2;
			
			FOR(j,0,201) {
				cout << dp[j][0][my] << " ";
			}
			cout << endl << endl;;
			FOR(j,0,201) {
				cout << dp[j][1][my] << " ";
			}
			cout << endl << endl;

}

int main() {
	read(n);
	readv(v, n);
	FOR(i,0,201) FOR(j,0,2) FOR(k,0,2) dp[i][j][k] = 0;
	if (v[0] != -1) {
		dp[v[0]][0][0] = 1;
	} else {
		FOR(i,1,201)  dp[i][0][0] = 1;
	}
	FOR(i,1,n) {
		int my = i%2;
		int oni = 1-my;
		FOR(j,0,201) dp[j][0][my] = dp[j][1][my] = 0;
		if (v[i] == -1) {
			FOR(j,1,201) {
				dp[j][0][my] = (dp[j-1][0][my] + dp[j-1][0][oni] + dp[j-1][1][oni])%mod;
			}
			dp[200][1][my] = (dp[200][0][oni] + dp[200][1][oni]) % mod;
			FORD(j,199,1) {
				dp[j][1][my] = (dp[j+1][1][my] + dp[j][1][oni] + dp[j][0][oni])%mod;
				dp[j][1][my] = (dp[j][1][my] + mod - dp[j+1][0][oni]) %mod;
			}
		} else {
			FOR(j,0,201) FOR(k,0,2) dp[j][k][my] = 0;
			FOR(j,0,v[i]) {
				dp[v[i]][0][my] += dp[j][0][oni];
				dp[v[i]][0][my] += dp[j][1][oni];
				while (dp[v[i]][0][my] >= mod) dp[v[i]][0][my] -= mod;
			}
			dp[v[i]][1][my] += dp[v[i]][0][oni];
			FOR(j,v[i],201) {
				dp[v[i]][1][my] += dp[j][1][oni];
				if (dp[v[i]][1][my] >= mod) dp[v[i]][1][my] -= mod;
			}
		}
	}
	int ans = 0;
	FOR(j,1,201) {
		ans += dp[j][1][(n-1)%2];
		if (ans >= mod) ans -= mod;
	}
	printf("%d\n", ans);
}