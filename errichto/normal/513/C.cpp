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
const int nax = 1e5 + 5;

int low[nax], high[nax], razem[nax];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	ld res = 0;
	int n;
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &low[i], &high[i]);
	REP(i, n) razem[i] = high[i] - low[i] + 1;
	REP(b, n) REP(a, n) if(a != b) {
		// a wygrywa, b drugi
		FOR(k, low[b], high[b]) {
			ld r = 1.L / razem[b];
			if(a < b) r *= (ld) min(razem[a], max(0, high[a] - k + 1)) / (ld) razem[a];
			else r *= (ld) min(razem[a], max(0, high[a] - k)) / (ld) razem[a];
			REP(i, n) if(a != i && b != i) {
				if(i < b) r *= (ld) min(razem[i], max(0, k - low[i])) / (ld) razem[i];
				else r *= (ld) min(razem[i], max(0, k - low[i] + 1)) / (ld) razem[i];
			}
			res += r * k;
		}
	}
	printf("%.12lf\n", (double) res);
	
	return 0;
}