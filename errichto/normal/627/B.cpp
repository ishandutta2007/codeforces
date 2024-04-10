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
const int pot = 256 * 1024;

void upd(int * tr, int r, int day, int diff) {
	day += pot;
	tr[day] = min(r, tr[day]+diff);
	for(int x = day / 2; x >= 1; x /= 2)
		tr[x] = tr[2*x] + tr[2*x+1];
}

ll s(int * tr, int low, int high) {
	// printf("%d-%d\n", low, high);
	if(low > high) return 0;
	low += pot;
	high += pot;
	ll ans = tr[low];
	if(low != high) ans += tr[high];
	while(low < high - 1) {
		if(low % 2 == 0) ans += tr[low+1];
		if(high % 2 == 1) ans += tr[high-1];
		low /= 2;
		high /= 2;
	}
	return ans;
}

int tr1[2*pot], tr2[2*pot];
int r1, r2;

void upd(int day, int diff) {
	upd(tr1, r1, day, diff);
	upd(tr2, r2, day, diff);
}
/*ll get(int low, int high) {
	return s(tr1, low, high) + s(tr2, low, high);
}*/

int main() {
	int n, gap, q;
	scanf("%d%d%d%d%d", &n, &gap, &r1, &r2, &q);
	while(q--) {
		int type;
		scanf("%d", &type);
		if(type == 1) {
			int day, diff;
			scanf("%d%d", &day, &diff);
			upd(day, diff);
		}
		else {
			assert(type == 2);
			int day;
			scanf("%d", &day);
			printf("%lld\n", s(tr2, 1, day - 1) + s(tr1, day+gap, n));
		}
	}
	return 0;
}