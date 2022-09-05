#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<assert.h>
#include<set>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e5 + 5;
const ll INF = (ll) inf * inf;

vector<pair<ll, int> > w;

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int h, q;
	scanf("%d%d", &h, &q);
	const pair<ll,ll> skraj = mp(1LL << (h-1), (1LL << h) - 1);
	while(q--) {
		int i, ans;
		ll L, R;
		scanf("%d%lld%lld%d", &i, &L, &R, &ans);
		REP(_, h-i) {
			L *= 2;
			R = 2 * R + 1;
		}
		if(ans) {
			if(L != skraj.st) {
				w.pb(mp(skraj.st, 0));
				w.pb(mp(L-1, 1));
			}
			if(R != skraj.nd) {
				w.pb(mp(R+1, 0));
				w.pb(mp(skraj.nd, 1));
			}
		}
		else {
			w.pb(mp(L, 0));
			w.pb(mp(R, 1));
		}
	}
	ll wypisz = -1;
	ll znalazlem = 0;
	sort(w.begin(), w.end());
	ll pop = skraj.st-1; // ostatni zly
	int cnt = 0;
	w.pb(mp(skraj.nd+1, 0));
	for(pair<ll,int> & e : w) {
		if(e.nd == 0) {
			if(cnt == 0 && pop + 1 < e.st) {
				znalazlem += e.st - (pop+1);
				wypisz = e.st-1;
			}
			cnt++;
		}
		else {
			cnt--;
			pop = e.st;
		}
	}
	if(znalazlem == 0) puts("Game cheated!");
	else if(znalazlem > 1) puts("Data not sufficient!");
	else {
		assert(wypisz != -1);
		printf("%lld\n", wypisz);
	}
	return 0;
}