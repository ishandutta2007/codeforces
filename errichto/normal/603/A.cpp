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
const int nax = 1e5 + 5;

char sl[nax];

int t[3][2], t2[3][2];

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", sl);
	REP(iii, n) {
		int z = (sl[iii] == '1');
		REP(i,3)REP(j,2) t2[i][j] = t[i][j];
		REP(j, 2) maxi(t2[1][j], t2[0][j]);
		REP(j, 2) maxi(t2[2][j], t2[1][j]);
		
		REP(i,3)REP(j,2) t[i][j] = t2[i][j];
		//REP(i, 3) printf("%d %d\n", t[i][0], t[i][1]);
		//puts("");
		
		REP(i, 3) REP(j, 2) {
			bool ok = (z != j);
			if(i == 1) ok = !ok;
			if(ok) maxi(t2[i][j], t[i][1^j] + 1);
		}
		
		REP(i,3)REP(j,2) t[i][j] = t2[i][j];
		//REP(i, 3) printf("%d %d\n", t[i][0], t[i][1]);
		//puts("\n");
	}
	int ans = 0;
	REP(i,3)REP(j,2) maxi(ans,t[i][j]);
	printf("%d\n", ans);
	return 0;
}