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
#define _st first
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
const int mod = 1e9 + 7;

int st[nax];

ll nt(ll a) { return a * (a - 1) / 2; }

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n, m;
	scanf("%d%d", &n, &m);
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		st[a]++;
		st[b]++;
	}
	ll r = 0;
	RI(i, n) r += nt(st[i]) * 2 + nt(n - 1 - st[i]) * 2 - (ll) st[i] * (n - 1 - st[i]);
	printf("%lld\n", r / 6);
	
	return 0;
}