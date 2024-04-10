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
const int pot = 1024 * 1024;

int tr_max[2*pot], tr_min[2*pot];

int fi(int low, int n) {
	low += pot;
	int already_min = tr_min[low];
	int already_max = tr_max[low];
	if(already_min <= already_max) return min(already_min, already_max);
	while(low % 2 == 1 || min(already_min,tr_min[low+1]) > max(already_max, tr_max[low+1])) {
		if(low % 2 == 0) {
			mini(already_min, tr_min[low+1]);
			maxi(already_max, tr_max[low+1]);
		}
		low /= 2;
	}
	++low;
	while(low < pot) {
		if(min(already_min, tr_min[low*2]) > max(already_max, tr_max[low*2])) {
			mini(already_min, tr_min[low*2]);
			maxi(already_max, tr_max[low*2]);
			low = 2 * low + 1;
		}
		else low = 2 * low;
	}
	int ans = min(already_min, already_max);
	if(low < pot + n) maxi(ans, min(min(already_min,tr_min[low]), max(already_max, tr_max[low])));
	return ans;
}

int ans[nax];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	REP(i, n) {
		int x;
		scanf("%d", &x);
		tr_max[pot+i] = x * 100;
	}
	REP(i, n) {
		int x;
		scanf("%d", &x);
		tr_min[pot+i] = x;
	}
	tr_min[pot+n] = -inf;
	tr_max[pot+n] = inf;
	FORD(i,pot-1,1) tr_max[i] = max(tr_max[2*i], tr_max[2*i+1]);
	FORD(i,pot-1,1) tr_min[i] = min(tr_min[2*i], tr_min[2*i+1]);
	
	REP(i, n) ans[i] = fi(i, n);
	sort(ans, ans + n);
	ld rem = 1;
	int ludzie = n;
	ld answer = 0;
	REP(i, n) {
		if(k > ludzie) break;
		ld with = (ld) k / ludzie;
		--ludzie;
		answer += with * ans[i] * rem;
		rem -= with * rem;
	}
	printf("%.10lf\n", (double) answer);
	return 0;
}