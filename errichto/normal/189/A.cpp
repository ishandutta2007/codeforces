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
const int nax = 4005;

int dp[nax];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n, t[3];
	scanf("%d", &n);
	REP(i, 3) scanf("%d", &t[i]);
	RI(i, n) dp[i] = -1;
	REP(me, n)  if(dp[me] != -1)
		REP(i, 3)
			if(me + t[i] <= n)
				maxi(dp[me+t[i]], dp[me] + 1);
	printf("%d\n", dp[n]);
	
	return 0;
}