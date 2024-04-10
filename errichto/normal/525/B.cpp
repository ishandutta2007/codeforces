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

char sl[nax];
bool odwroc[nax];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	scanf("%s", sl);
	int n = strlen(sl);
	int z;
	scanf("%d", &z);
	while(z--) { int a; scanf("%d", &a); odwroc[a-1] = !odwroc[a-1]; }
	bool norm = true;
	REP(i, n / 2) {
		if(odwroc[i]) norm = !norm;
		if(!norm) swap(sl[i], sl[n-1-i]);
	}
	printf("%s\n", sl);
	
	return 0;
}