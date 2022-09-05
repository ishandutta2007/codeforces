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

int dp[26][26];
char sl[2][nax];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n;
	scanf("%d", &n);
	REP(i, 2) scanf("%s", sl[i]);
	int tera = 0;
	REP(i, n) if(sl[0][i] != sl[1][i]) ++tera;
	REP(i, n) dp[sl[0][i]-'a'][sl[1][i]-'a'] = i + 1;
	REP(a, 26) REP(b, a) if(dp[a][b] && dp[b][a]) {
		printf("%d\n", tera - 2);
		printf("%d %d\n", dp[a][b], dp[b][a]);
		return 0;
	}
	REP(a, 26) REP(b, 26) if(a != b) REP(c, 26) if(b != c) {
		if(dp[a][b] && dp[b][c]) {
			printf("%d\n", tera - 1);
			printf("%d %d\n", dp[a][b], dp[b][c]);
			return 0;
		}
	}
	printf("%d\n", tera);
	puts("-1 -1");
	
	return 0;
}