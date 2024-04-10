#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
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
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1005;
const ll INF = (ll) inf * inf;

int t[nax][nax];
ll s[nax];
int H, W;

ll K(ll a) { return a * a; }

ll f(int i) {
	i = 2 * i + 1;
	ll r = 0;
	RI(x, W) r += s[x] * K(i - 2 * x);
	return r;
}
ll f2(int i) {
	i = 2 * i + 1;
	ll r = 0;
	RI(x, H) r += s[x] * K(i - 2 * x);
	return r;
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	scanf("%d%d", &H, &W);
	RI(y, H) RI(x, W) scanf("%d", &t[x][y]);
	
	RI(y, H) RI(x, W) s[x] += t[x][y];
	
	ll licznik = 0, mianownik = 0;
	
	RI(x, W) {
		licznik += x * s[x];
		mianownik += s[x];
	}
	int i = 0;
	if(mianownik > 0LL) i = (int) (licznik / mianownik);
	if(i > 0) --i;
	pair<ll,int> p = {INF, 0};
	FOR(k, i, i + 4) if(k < W)
		p = min(p, {f(k),k});
		//mini(p, {f(k), k});
	
	//printf("%lld %d\n", p.st, p.nd);
	RI(y, H) s[y] = 0;
	RI(y,H) RI(x,W) s[y] += t[x][y];
	licznik = 0;
	mianownik = 0;
	RI(y, H) {
		licznik += y * s[y];
		mianownik += s[y];
	}
	i = 0;
	if(mianownik > 0LL) i = (int) (licznik / mianownik);
	if(i > 0) --i;
	pair<ll,int> p2 = {INF, 0};
	FOR(k,i,i+4)if(k < H)
		p2 = min(p2, {f2(k),k});
	
	printf("%lld\n", (p.st + p2.st) * 4LL);
	printf("%d %d\n", p2.nd, p.nd);
	return 0;
}