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



int main() {
	int n;
	scanf("%d", &n);
	ll ans = 0;
	// border
	ans = 4 * 3;
	REP(_, n - 3) ans *= 4;
	ans *= 2;
	ll memo = ans;
	ans = n - 3;
	ans *= 4 * 3 * 3;
	REP(_, n - 4) ans *= 4;
	printf("%lld\n", ans + memo);
	return 0;
}