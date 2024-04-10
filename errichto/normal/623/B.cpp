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

int t[nax], type[nax];
ll pref[nax];

void find_primes(int a, vi & w) {
	for(int i = 2; i * i <= a; ++i) if(a % i == 0) {
		w.pb(i);
		while(a % i == 0) a /= i;
	}
	if(a > 1) w.pb(a);
}

void uniquj(vi & w) {
	set<int> s;
	for(int a : w) s.insert(a);
	w.clear();
	for(int a : s) w.pb(a);
}

int main() {
	int n, c1, c2;
	scanf("%d%d%d", &n, &c1, &c2);
	RI(i, n) scanf("%d", &t[i]);
	// c1 - removing
	// c2 - by one
	vi primes;
	FOR(d,-1,1) {
		find_primes(t[1]+d, primes);
		find_primes(t[n]+d, primes);
	}
	uniquj(primes);
	ll answer = (ll) inf * inf;
	REP(_, 2) {
		for(int p : primes) {
			for(int i = 1; i <= n; ++i) {
				int r = t[i] % p;
				if(r == 0) type[i] = 0;
				else if(r == 1 || r == p - 1) type[i] = 1;
				else type[i] = 2;
			}
			int cnt = 0;
			for(int i = 1; i <= n; ++i) {
				pref[i] = pref[i-1] + c1;
				if(type[i] == 2) cnt = -1;
				if(cnt == -1) continue;
				if(type[i] == 1) ++cnt;
				mini(pref[i], (ll) cnt * c2);
			}
			
			cnt = 0;
			for(int i = n; i >= 1; --i) {
				if(type[i] == 2) break;
				if(type[i] == 1) ++cnt;
				mini(answer, pref[i-1] + (ll) cnt * c2);
			}
			//for(int i = 1; i <= n; ++i) printf("%lld ", pref[i]);
			//puts("");
		}
		reverse(t + 1, t + n + 1);
	}
	assert(answer != (ll) inf * inf);
	printf("%lld\n", answer);
	return 0;
}