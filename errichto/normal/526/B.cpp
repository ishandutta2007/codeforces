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
const int nax = 1e6 + 5;

ll t[nax];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n;
	scanf("%d", &n);
	int M = (1 << (n + 1));
	FOR(i, 2, M - 1) scanf("%lld", &t[i]);
	ll res = 0;
	FORD(i, M - 1, 2) if(i%2) {
		ll ja = t[i], on = t[i-1];
		res += max(ja,on) - min(ja,on);
		t[i/2] += max(ja,on);
	}
	printf("%lld\n", res);
	return 0;
}