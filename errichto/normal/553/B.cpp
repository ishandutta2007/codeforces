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
const int nax = 52;

ll f[nax];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	f[0] = f[1] = 1;
	FOR(i,2,nax-1) f[i] = f[i-1]+f[i-2];
	int n;
	ll cel;
	scanf("%d%lld", &n, &cel);
	RI(i, n) {
		if(f[n-i] >= cel) printf("%d ", i);
		else {
			cel -= f[n-i];
			printf("%d %d ", i+1, i);
			++i;
		}
	}
	
	return 0;
}

/*
ll mnoz(ll a, ll b) {
	if(a == 0  || b == 0) return 0;
	if(a > INF / b || b > INF / a) return INF;
	return a * b;
}
void zwieksz(ll & a, ll b) {
	a = min(a + b, INF);
}
ll nt[nax][nax];
ll dp[nax][nax];
ll fac[nax];
bool vis[nax];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	REP(i, nax) nt[i][0] = 1;
	REP(i, nax) RI(j, i) nt[i][j] = nt[i-1][j-1] + nt[i-1][j];
	fac[0] = 1;
	RI(i, nax - 1) fac[i] = mnoz(fac[i-1], i);
	
	REP(i, nax) dp[0][i] = 1;
	RI(n, nax - 1) RI(lim, n) FOR(a, lim, n) REP(k, a)
		zwieksz(dp[n][lim], mnoz(nt[a-1][k], dp[n-1-k][a+1-1-k]));
	//RI(n, nax - 1) RI(k, n) zwieksz(dp[n], mnoz(nt[n-1][k-1], dp[k-1]));
	//RI(n, 30) printf("%lld ", dp[n][1]); return 0;
	while(false) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%lld\n", dp[a][b]);
	}
	int n;
	scanf("%d", &n);
	ll cel;
	scanf("%lld", &cel);
	int pop = 0;
	RI(tura, n) {
		//printf("cel=%lld\n", cel);
		int a = 1;
		while(true) {
			while(vis[a]) ++a;
			if(a < pop) {
				int mniejsze = 0;
				RI(k, pop - 1) if(k != a && !vis[k]) ++mniejsze;
				ll pom = 0;
				FOR(k, 0, mniejsze)
					zwieksz(pom,
						mnoz(mnoz(nt[mniejsze][k], fac[k]), dp[n-tura-k][1+mniejsze-k])
					);
				//printf("%d>%lld\n", a, pom);
				if(pom >= cel) break;
				cel -= pom;
				++a;
			}
			else {
				while(a <= pop || vis[a]) ++a;
				int mniejsze = 0;
				RI(k, a - 1) if(!vis[k]) ++mniejsze;
				ll pom = 0;
				REP(k, a) {
					int one = n-1-k-(tura-1);
					int two = mniejsze-k+1;
					if(one >= 0 && two >= 0)
						zwieksz(pom, mnoz(mnoz(nt[mniejsze][k],fac[k]), dp[one][two]));
				}
				//printf("%lld\n", pom);
				if(pom >= cel) break;
				else {
					cel -= pom;
					++a;
				}
			}
		}
		maxi(pop, a);
		printf("%d\n", a);
		vis[a] = true;
	}
	
	return 0;
}*/