#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<assert.h>
using namespace std;
#define FOR(i,a,n) for(int i = (a); i <= (n); ++i)
#define FORD(i,a,n) for(int i = (a); i >= (n); --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,(n))
#define pb push_back
#define st first
#define nd second
#define mp make_pair
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9;
const int nax = 1e6 + 5;
const ll mod = 1e9 + 7;

int ojc[nax];
bool vis[nax];

int f(int a) {
	return ojc[a] == a ? a : ojc[a] = f(ojc[a]);
}
void u(int a, int b) {
	ojc[f(a)] = f(b);
}

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	RI(i, n) ojc[i] = i;
	RI(i, n - k + 1) {
		int a = i, b = i + k - 1;
		FOR(low, a, b) {
			int high = b - (low - a);
			if(low < high) u(low, high);
		}
	}
	RI(i, n) f(i);
	int d = 0;
	RI(i, n) {
		if(!vis[ojc[i]]) ++d;
		vis[ojc[i]] = true;
	}
	ll r = 1;
	REP(_, d) r = (r * m) % mod;
	printf("%d\n", (int) r);
	
	return 0;
}