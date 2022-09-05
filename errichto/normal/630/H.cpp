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
	//int x1, y1, x2, y2;
	//scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	int n;
	scanf("%d", &n);
	ll ans = 1;
	FOR(i,n-4,n) ans *= i;
	ans /= 120;
	FOR(i,n-4,n) ans *= i;
	printf("%lld\n", ans);
	//printf("%lld\n", 1 + (ll) n * (n + 1) / 2 * 6);
	return 0;
}