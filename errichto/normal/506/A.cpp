#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<assert.h>
using namespace std;
#define FOR(i,a,n) for(int i = (a); i <= (n); ++i)
#define FORD(i,a,n) for(int i = (a); i >= (n); --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,(n))
#define pb push_back
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 30000;

int gem[nax + 5];
int m[nax + 5][800];
int RES;

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	int n, d0;
	scanf("%d%d", &n, &d0);
	while(n--) {
		int a;
		scanf("%d", &a);
		gem[a]++;
	}
	REP(i, nax + 5) REP(j, 800) m[i][j] = -inf;
	m[d0][400] = gem[d0];
	FOR(i, d0, nax) REP(roz, 800) {
		maxi(RES, m[i][roz]);
		int d = d0 + roz - 400;
		FOR(j, d-1, d+1) if(j > 0 && i + j <= nax)
			maxi(m[i+j][j + 400 - d0], m[i][roz] + gem[i+j]);
	}
	printf("%d\n", RES);
	return 0;
}