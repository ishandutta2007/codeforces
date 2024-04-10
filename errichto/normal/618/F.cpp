#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

int t[2][nax];
int where[2*nax][2];
int p[2];

int main(int argc, char * argv[]) {
	int n;
	scanf("%d", &n);
	REP(i,2)RI(j,n) scanf("%d", &t[i][j]);
	REP(i,2*nax) where[i][0] = -1;
	where[nax][0] = 0;
	int s = 0;
	while(true) {
		if(s <= 0) {
			++p[0];
			s += t[0][p[0]];
		}
		else {
			++p[1];
			s -= t[1][p[1]];
		}
		// printf("%d %d:%d\n", s, p[0], p[1]);
		assert(max(p[0],p[1]) <= n);
		if(where[nax+s][0] != -1) {
			REP(k, 2) {
				printf("%d\n", p[k]-where[nax+s][k]);
				FOR(j,where[nax+s][k]+1, p[k]) printf("%d ", j);
				puts("");
			}
			return 0;
		}
		REP(k,2) where[nax+s][k] = p[k];
	}
	return 0;
}