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

char sl[105];
int pot[105];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	pot[0] = 1;
	RI(i, 100) {
		pot[i] = pot[i-1] * 2;
		if(pot[i] >= mod) pot[i] -= mod;
	}
	scanf("%s", sl);
	int n = strlen(sl);
	int r = 0;
	REP(i, n) if(sl[i] == '1') {
		r += pot[n-1-i];
		if(r >= mod) r -= mod;
	}
	r = (ll) r * pot[n-1] % mod;
	printf("%d\n", r);
	
	return 0;
}