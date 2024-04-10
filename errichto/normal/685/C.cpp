#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e5 + 5;

int n;
ll t[nax][3];
ll best[4];

ll f(ll z, bool write) {
	REP(i, n) {
		REP(mask, 4) {
			ll here = abs(z - t[i][2]);
			REP(j, 2) {
				if(mask & (1 << j))
					here += t[i][j];
				else
					here -= t[i][j];
			}
			if(i == 0) best[mask] = here;
			else maxi(best[mask], here);
		}
	}
	if(write) {
		ll x = best[0] + best[2];
		ll y = best[0] - best[2];
		x -= best[1] + best[3];
		y += best[1] - best[3];
		x *= -1;
		y *= -1;
		x /= 4;
		y /= 4;
		pair<ll, pair<ll,ll>> best;
		FOR(i,-1,1)FOR(j,-1,1) {
			ll ans = 0;
			x += i;
			y += j;
			ll tmp[3] = {x, y, z};
			REP(k, n) {
				ll here = 0;
				REP(nic, 3)
					here += abs(tmp[nic] - t[k][nic]);
				maxi(ans, here);
			}
			if(i == -1 && j == -1)
				best = mp(ans, mp(x,y));
			else
				mini(best, mp(ans, mp(x,y)));
			x -= i;
			y -= j;
		}
		printf("%lld %lld ", best.second.first, best.second.second);
	}
	return max(best[0] + best[3], best[1] + best[2]);
}

void te() {
	scanf("%d", &n);
	REP(i, n) REP(j, 3) scanf("%lld", &t[i][j]);
	ll M = 1000 * 1000 * 1000;
	M *= M;
	ll low = -M;
	ll high = M;
	while(low + 4 < high) {
		ll one = (2 * low + high) / 3;
		ll two = (low + 2 * high) / 3;
		if(f(one, false) < f(two, false)) high = two;
		else low = one;
	}
	pair<ll,ll> best;
	for(ll i = low; i <= high; ++i) {
		ll maybe = f(i, false);
		//printf("%lld: %lld\n", i, maybe);
		if(i == low) best = mp(maybe, i);
		else mini(best, mp(maybe, i));
	}
	f(best.second, true);
	printf("%lld\n", best.second);
	//	printf("%lld - %lld   ", i, f(i));
	//puts("");
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) te();
	return 0;
}