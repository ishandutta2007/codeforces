#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,n)
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
const ll INF = (ll) inf * inf;
const int nax = 3e6 + 5;

ll pref[nax], t[nax];

ll s(int a, int b) { return pref[b] - pref[a-1]; }

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	ll a, b;
	int q;
	scanf("%lld%lld%d", &a, &b, &q);
	RI(i, nax - 1) t[i] = a + b * (i - 1);
	RI(i, nax - 1) pref[i] = pref[i-1] + t[i];
	while(q--) {
		int pocz, times, m;
		scanf("%d%d%d", &pocz, &times, &m);
		int low = pocz, high = nax - 1;
		if(t[pocz] > times) {
			puts("-1");
			continue;
		}
		while(low < high) {
			int med = (low + high + 1) / 2;
			if(max(t[med], (s(pocz, med) + m - 1) / m) <= times)
				low = med;
			else
				high = med - 1;
		}
		printf("%d\n", low);
	}
	
	return 0;
}