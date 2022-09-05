#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<assert.h>
#include<set>
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
typedef unsigned long long ull;
const int inf = 1e9 + 5;
const ll INF = (ll) inf * inf;
const int nax = 1e6 + 5;
const ll md = 1e9 + 7;

const ull C = 29;
ull h[nax];
ull pot[nax];
int n;
char sl[nax];
set<int> zera;

bool rowne(int b, int d) { 
	assert(b + d <= n);
	assert(b > 0);
	ull h1 = h[d-1] * pot[b];
	ull h2 = h[b+d-1] - h[b-1] + md;
	return h1 % md == h2 % md;
}

int daj(int a) { return *(zera.upper_bound(a)); }

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int k;
	scanf("%d%d", &n, &k);
	RI(i, n) zera.insert(i);
	zera.insert(inf);
	scanf("%s", sl);
	pot[0] = 1;
	RI(i, nax - 1) pot[i] = (pot[i-1] * C) % md;
	REP(i, n) h[i] = ((i ? h[i-1] : 0) + (sl[i]-'a')*pot[i]) % md;
	
	FORD(d, n / k, 1) {
		bool ok = true;
		RI(i, k - 1) if(!rowne(i * d, d)) {
			ok = false;
			break;
		}
		if(!ok) continue;
		int tu = k * d;
		zera.erase(tu);
		//printf("> %d\n", tu);
		//for(auto a : zera) printf("%d ", a); puts("");
		//tu = *(zera.upper_bound(tu));
		tu = daj(tu);
		//printf("%d\n", tu);
		while(true) {
			if(tu > n) break;
			if(tu > (k+1) * d) break;
			if(sl[tu-1] != sl[tu-k*d-1]) break;
			zera.erase(tu);
			tu = daj(tu);
		}
	}
	RI(i, n) printf(zera.find(i) == zera.end() ? "1" : "0");
	puts("");
			
	
	return 0;
}