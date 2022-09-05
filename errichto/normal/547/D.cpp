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

vector<pii> w[nax];
bool vis[nax];
bool odp[nax];
int st[nax];

void dfs(int a, bool ustaw) {
	while(!w[a].empty()) {
		int b = w[a].back().st;
		int kr = w[a].back().nd;
		if(vis[kr]) {
			w[a].pop_back();
			continue;
		}
		vis[kr] = true;
		st[a]--;
		st[b]--;
		odp[kr] = ustaw;
		dfs(b, !ustaw);
		return;
	}
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n;
	scanf("%d", &n);
	REP(i, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		a = 2 * a;
		b = 2 * b + 1;
		w[a].pb(mp(b,i));
		w[b].pb(mp(a,i));
		st[a]++;
		st[b]++;
	}
	REP(i, nax) if(st[i]%2) dfs(i, true);
	REP(i, nax) dfs(i, true);
	REP(i, n) printf(odp[i] ? "r" : "b");
	puts("");
	
	return 0;
}