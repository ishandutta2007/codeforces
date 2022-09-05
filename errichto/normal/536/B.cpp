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
const int inf = 1e9 + 5;
const ll INF = (ll) inf * inf;
const int nax = 1e6 + 5;
const ll md = 1e9 + 7;

const ll C = 29;
ll h[nax];
ll pot[nax];
char sl[nax];
int n;
int x[nax];
int c[nax];

bool rowne(int a, int b, int d) { 
	ll h1 = h[a+d-1] - h[a-1] + md;
	ll h2 = h[b+d-1] - h[b-1] + md;
	return h1 * pot[n-a] % md == h2 * pot[n-b] % md;
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int q;
	scanf("%d%d", &n, &q);
	scanf("%s", sl);
	pot[0] = 1;
	RI(i, nax - 1) pot[i] = (pot[i-1] * C) % md;
	REP(i, n) h[i] = ((i ? h[i-1] : 0) + (sl[i]-'a')*pot[i]) % md;
	
	RI(i, q) scanf("%d", &x[i]);
	int d = strlen(sl);
	FOR(i, 2, q) {
		int a = x[i-1];
		int b = x[i];
		if(a + d > b && !rowne(0, b-a, a+d-b)) {
			puts("0");
			return 0;
		}
	}
	RI(i, q) {
		c[x[i]]++;
		c[x[i] + d]--;
	}
	int counter = 0;
	ll res = 1;
	RI(i, n) {
		counter += c[i];
		if(counter == 0) res = res * 26 % md;
	}
	printf("%lld\n", res);
	
	return 0;
}