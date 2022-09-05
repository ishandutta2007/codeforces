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
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e5 + 5;

int ojc[nax];
bool ok[nax];

int find(int a) {
	return ojc[a] == a ? a : ojc[a] = find(ojc[a]);
}
void un(int a, int b) {
	ojc[find(a)] = find(b);
}

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	int n, m;
	scanf("%d%d", &n, &m);
	int sta = 0;
	REP(_, 2) {
		int ile;
		scanf("%d", &ile);
		REP(__, ile) {
			int a;
			scanf("%d", &a);
			ok[a + sta] = true;
		}
		sta = n;
	}
	REP(i, n + m) ojc[i] = i;
	REP(i, n * m)
		un(i % n, n + i % m);
	vi w[n + m];
	REP(i, n + m) w[find(i)].pb(i);
	REP(i, n + m) if(!w[i].empty()) {
		bool c = false;
		for(auto a : w[i]) if(ok[a]) c = true;
		if(!c) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}