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
#define mp make_pair
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

int r[30];
int f(char a) { return a - 'a' + 1; }
bool ok[30][30];
char sl[nax];

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	scanf("%s", sl);
	int n = strlen(sl);
	int zle;
	scanf("%d", &zle);
	REP(i, 30) REP(j, 30) ok[i][j] = true;
	REP(_, zle) {
		char cyk[5];
		scanf("%s", cyk);
		ok[f(cyk[0])][f(cyk[1])] = ok[f(cyk[1])][f(cyk[0])] = false; 
	}
	RI(i, 26) r[i] = inf;
	r[0] = 0;
	REP(i, n) {
		int a = f(sl[i]);
		int jeb = i;
		RI(j, 26) if(ok[a][j]) mini(jeb, r[j]);
		r[a] = jeb;
		RI(j, 26) if(j != a) r[j]++;
	}
	int rr = n;
	RI(j, 26) mini(rr, r[j]);
	printf("%d\n", rr);
	return 0;
}