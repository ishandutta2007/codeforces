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
const int mod = 1e9 + 7;

int in[10][10], pot[10];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n, k;
	scanf("%d%d", &n, &k);
	pot[0] = 1;
	RI(i, k) pot[i] = pot[i-1] * 10;
	REP(i, n) {
		char sl[15];
		scanf("%s", sl);
		REP(j, k) in[i][j] = sl[j] - '0';
	}
	vi p(k);
	REP(i, k) p[i] = i;
	int r = inf;
	do {
		int mi = inf, ma = 0;
		REP(i, n) {
			int a = 0;
			REP(j, k) a += pot[j] * in[i][p[j]];
			mini(mi, a);
			maxi(ma, a);
		}
		mini(r, ma - mi);
	} while(next_permutation(p.begin(), p.end()));
	printf("%d\n", r);
	
	return 0;
}