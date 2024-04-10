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

char sl[nax];
ll pref_rotate[nax];
int n, c_swipe, total;

bool ok(int start, int end) {
	assert(start <= end);
	// if(start > 0 && end < n) return false;
	ll cost = pref_rotate[end];
	if(start) cost -= pref_rotate[start - 1];
	if(start == 0) cost += (end - start) * (ll) c_swipe;
	else if(end >= n) {
		int d1 = n - start, d2 = end - n;
		cost += (ll) c_swipe * (d1 + d2 + min(d1, d2));
	}
	else {
		cost += (ll) c_swipe * (end - start);
	}
	return cost <= total;
}

int main() {
	int c_rotate;
	scanf("%d%d%d%d", &n, &c_swipe, &c_rotate, &total);
	scanf("%s", sl);
	REP(i, 2 * n) {
		if(i) pref_rotate[i] = pref_rotate[i-1];
		if(sl[i % n] == 'w') pref_rotate[i] += c_rotate;
		pref_rotate[i]++;
	}
	int ans = 0;
	REP(start, n) {
		// najwieksza dobra dlugosc, moze 0, moze n
		int low = 0, high = n;
		while(low < high) {
			int dist = (low + high + 1) / 2;
			assert(dist > 0);
			int end = start + dist - 1;
			if(ok(start, end)) low = dist;
			else high = dist - 1;
		}
		int end = start + low - 1;
		// printf("> %d %d\n", start, start + low - 1);
		if(start == 0 || end >= n) maxi(ans, low);
	}
	printf("%d\n", ans);
	return 0;
}