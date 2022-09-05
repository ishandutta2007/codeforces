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
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

int t[nax];



int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	REP(i, n) scanf("%d", &t[i]);
	sort(t, t + n);
	ll s = 0;
	REP(i, n) s += t[i];
	//ll poor = s / n;
	ll maybe = 0;
	/*REP(i, n) maybe += max(0LL, poor - t[i]);
	if(maybe <= k) {
		if(s % n == 0) puts("0");
		else puts("1");
		return 0;
	}*/
	int low = 1, high = 1000 * 1000 * 1000;
	// poor
	while(low < high) {
		int mid = ((ll) low + high + 1) / 2;
		maybe = 0;
		REP(i, n) maybe += max(0, mid - t[i]);
		if(maybe > k || mid > s/n) high = mid - 1;
		else low = mid;
	}
	ll poor = low;
	low = 1; high = 1000 * 1000 * 1000;
	// rich
	while(low < high) {
		int mid = ((ll) low + high) / 2;
		maybe = 0;
		REP(i, n) maybe += max(0, t[i] - mid);
		if(maybe > k || mid < (s+(n-1))/n) low = mid + 1;
		else high = mid;
	}
	//printf("%lld %lld\n", poor, low);
	printf("%lld\n", low - poor);
	return 0;
}