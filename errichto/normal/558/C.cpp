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
const int nax = 128 * 1024;
const ll INF = (ll) inf * inf;

ll ile[nax];
ll res[nax];
ll wypisz = INF;

void rec(int i, ll RES, ll ILE) {
	mini(wypisz, RES + res[i]);
	if(i >= nax / 2) return;
	int ja = ile[i] - ile[2*i] - ile[2*i+1];
	rec(2*i, RES + res[2*i+1] + ja + 2*ile[2*i+1] + ILE, ILE+ile[2*i+1]+ja);
	if(ILE+ile[2*i]+ja == 0)
		rec(2*i+1, RES + res[2*i] + ja + 2*ile[2*i] + ILE, ILE+ile[2*i]+ja);
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n;
	scanf("%d", &n);
	while(n--) {
		int a;
		scanf("%d", &a);
		ile[a]++;
	}
	FORD(i, nax/2 - 1, 1) {
		res[i] = res[2*i] + res[2*i+1] + ile[2*i]+ile[2*i+1];
		ile[i] += ile[2*i] + ile[2*i+1];
	}
	rec(1, 0, 0);
	assert(wypisz != INF);
	printf("%lld\n", wypisz);
	return 0;
}