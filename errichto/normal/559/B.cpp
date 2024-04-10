#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,(n))
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
const int nax = 2e5 + 5;

char sl[2][nax];

void f(int low, int high, int r) {
	if(low == high) return;
	int d = high - low + 1;
	if(d % 2) return;
	int med = low + d / 2;
	f(low, med-1, r);
	f(med,high,r);
	REP(i, d / 2) if(sl[r][low+i] != sl[r][med+i]) {
		if(sl[r][low+i] > sl[r][med+i])
			REP(j, d/2) swap(sl[r][low+j], sl[r][med+j]);
		break;
	}
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	REP(i, 2) scanf("%s", sl[i]);
	f(0, strlen(sl[0]) - 1, 0);
	f(0, strlen(sl[1]) - 1, 1);
	int d = strlen(sl[0]);
	if(strlen(sl[0]) == strlen(sl[1])) REP(i, d) if(sl[0][i] != sl[1][i]) {
		puts("NO");
		return 0;
	}
	puts("YES");
	
	return 0;
}