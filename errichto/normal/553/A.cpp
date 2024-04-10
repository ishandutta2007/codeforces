#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const ll INF = (ll) inf * inf;
const int nax = 1e3 + 5;
const int mod = 1e9 + 7;

int dp[nax][nax];
int ile[nax];
int nt[nax][nax];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	REP(i, nax) nt[i][0] = 1;
	REP(i, nax) RI(j, i) nt[i][j] = (nt[i-1][j-1] + nt[i-1][j]) % mod;
	
	int n;
	scanf("%d", &n);
	RI(i, n) scanf("%d", &ile[i]);
	int S = 0;
	RI(i, n) S += ile[i];
	dp[0][0] = 1;
	RI(i, n) RI(k, S) {
		dp[i][k] += (ll) nt[k-1][ile[i]-1] * dp[i-1][max(0, k-ile[i])] % mod;
		dp[i][k] %= mod;
	}
	printf("%d\n", dp[n][S] % mod);
	
	return 0;
}