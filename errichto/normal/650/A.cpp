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

int x[nax], y[nax];
map<int,int> mx, my;
map<pii, int> lol;

ll f(int a) { return (ll) a * (a-1) / 2; }

int main() {
	int n;
	scanf("%d", &n);
	REP(i, n) {
		scanf("%d%d", &x[i], &y[i]);
		mx[x[i]]++;
		my[y[i]]++;
		lol[mp(x[i], y[i])]++;
	}
	ll ans = 0;
	for(pii p : mx) ans += f(p.nd);
	for(pii p : my) ans += f(p.nd);
	for(auto p : lol) ans -= f(p.nd);
	printf("%lld\n", ans);
	return 0;
}