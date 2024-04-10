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
const int nax = 512;

int dp[nax][nax];
int mod;

void dodaj(int & a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n, linie, lim;
	scanf("%d%d%d%d", &n, &linie, &lim, &mod);
	REP(i, nax) REP(j, nax) dp[i][j] = 0;
	dp[0][0] = 1 % mod;
	// linie, bugi
	RI(man, n) {
		int nowy;
		scanf("%d", &nowy);
		REP(i, linie)
			FOR(bugi, 0, lim)
				if(bugi + nowy <= lim)
				dodaj(dp[i+1][bugi+nowy], dp[i][bugi]);
			//for(int nowe_linie = 1; i + nowe_linie <= linie; ++nowe_linie)
			//	FOR(bugi, 0, lim - nowy * nowe_linie)
			//		dodaj(dp[i+nowe_linie][bugi+nowy*nowe_linie], dp[i][bugi]);
	}
	int res = 0;
	FOR(i, 0, lim) dodaj(res, dp[linie][i]);
	printf("%d\n", res);
	
	return 0;
}