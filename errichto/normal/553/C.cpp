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

bool vis[nax];
int t[nax];
vector<pii> w[nax];

void dfs(int a, int co) {
	vis[a] = true;
	if(t[a] != -1 && t[a] != co) {
		puts("0");
		exit(0);
	}
	if(t[a] != -1) return;
	t[a] = co;
	for(auto kr : w[a]) {
		if(kr.nd == 1) dfs(kr.st, co);
		else dfs(kr.st, co^1);
	}
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n, m;
	scanf("%d%d", &n, &m);
	RI(i, n) t[i] = -1;
	while(m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		w[a].pb(mp(b,c));
		w[b].pb(mp(a,c));
	}
	int ile = 0;
	RI(a, n) if(!vis[a]) {
		++ile;
		dfs(a, 0);
	}
	int res = 1;
	REP(_, ile - 1) res = res * 2 % mod;
	printf("%d\n", res);
	
	return 0;
}