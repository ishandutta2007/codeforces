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
#define nd second
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 105;

char sl[nax][nax];
int d[nax];
#define NIE "Impossible"
bool jeb[nax][nax];
vi res;
int st[nax];
bool vis[nax];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n;
	scanf("%d", &n);
	REP(i, n) {
		scanf("%s", sl[i]);
		d[i] = strlen(sl[i]);
	}
	REP(i, n-1) {
		int j = 0;
		while(j < min(d[i], d[i+1]) && sl[i][j] == sl[i+1][j]) ++j;
		if(j == d[i+1] && j != d[i]) {
			puts(NIE);
			return 0;
		}
		if(j == d[i]) continue;
		jeb[sl[i][j] - 'a'][sl[i+1][j] - 'a'] = true;
	}
	REP(i, 26) REP(j, 26) if(jeb[i][j]) st[j]++;
	// REP(i, 26) printf("%d ", st[i]);
	REP(_, 26) {
		REP(i, 26) if(st[i] == 0 && !vis[i]) {
			res.pb(i);
			REP(j, 26) if(jeb[i][j]) st[j]--;
			vis[i] = true;
			i = 30;
		}
	}
	if((int) res.size() != 26) {
		puts(NIE);
		return 0;
	}
	for(auto a : res) printf("%c", 'a' + a);
	puts("");
	return 0;
}