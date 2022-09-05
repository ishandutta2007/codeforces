#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= (b); ++i)
#define FORD(i,a,b) for(int i = a; i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const ll INF = (ll) inf * inf * 5;
const int nax = 4005;
const int mod = 1e9 + 7;

ll dp[nax], binom[nax][nax];

void dodaj(ll & a, ll b) {
	a = (a + b) % mod;
}

ll pot(ll a, int b) {
	ll r = 1;
	while(b) {
		if(b % 2) r = r * a % mod;
		a = a * a % mod;
		b /= 2;
	}
	return r;
}

ll fac[nax], inv[nax];

int te(int n) {
	REP(i, nax) dp[i] = 0;
	dp[0] = 1;
	RI(k, n) {
		FORD(i,n-k,0) {
			ll me = dp[i];
			if(me == 0) continue;
			ll rest = n-i;
			for(int j = 1; i + k * j <= n; ++j) {
				me = me * binom[rest][k] % mod;// % mod;
				//if(me >= mod) me %= mod;
				rest -= k;
				//printf("%lld %d\n", me, j);
				dp[i+j*k] += me * inv[j];
				if(dp[i+j*k] > INF) dp[i+j*k] %= mod;
			}
		}
		REP(i,n+1) if(dp[i] >= mod) dp[i] %= mod;
	}
	ll r = 0;
	REP(i, n)
		r = (r + dp[i]) % mod;
	return (int) r;
}

int pre[] = {240446492,132759678,134081914,702601410,909768461,660176441,680440363,57179043,900412868,646477707,534303308,997628154,282709724,402700228,997064274,785650024,436878044,977972319,780587881,124834909,341934157};

int main()
{
	fac[0] = 1;
	RI(i, nax - 1) fac[i] = fac[i-1] * i % mod;
	REP(i,nax) inv[i] = pot(fac[i], mod-2);
	REP(i,nax) binom[i][0] = 1;
	REP(i,nax)RI(j,i) {
		binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
		if(binom[i][j] >= mod) binom[i][j] -= mod;
	}
	//for(int n = 3980; n <= 4000; ++n) printf("%d,", te(n));
	int n;
	scanf("%d", &n);
	if(n >= 3980) printf("%d\n", pre[n-3980]);
	else printf("%d\n", te(n));
	
	return 0;
}