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
const int mod = 1e9 + 7;

int f(char z) {
	if('0' <= z && z <= '9') return z - '0';
	if('A' <= z && z <= 'Z') return z - 'A' + 10;
	if('a' <= z && z <= 'z') return z - 'a' + 36;
	if(z == '-') return 62;
	if(z == '_') return 63;
	assert(false);
}

char sl[nax];

int main() {
	scanf("%s", sl);
	int n = strlen(sl);
	ll ans = 1;
	REP(i, n) {
		int b = 6 - __builtin_popcount(f(sl[i]));
		REP(_, b) {
			ans *= 3;
			while(ans >= mod) ans -= mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}