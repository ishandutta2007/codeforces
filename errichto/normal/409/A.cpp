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
const int nax = 1e6 + 5;

const char sci = '8', pap = '[', rock = '(';
char sl[2][nax];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	REP(i, 2) scanf("%s", sl[i]);
	int a = 0;
	for(int j = 0; j < (int) strlen(sl[0]); j += 2) if(sl[0][j] != sl[1][j]) {
		if(sl[0][j] == rock && sl[1][j] == sci) ++a;
		else if(sl[0][j] == sci && sl[1][j] == pap) ++a;
		else if(sl[0][j] == pap && sl[1][j] == rock) ++a;
		else --a;
	}
	if(a > 0) puts("TEAM 1 WINS");
	else if(a < 0) puts("TEAM 2 WINS");
	else puts("TIE");
	
	return 0;
}