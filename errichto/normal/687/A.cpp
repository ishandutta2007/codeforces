#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

bool vis[nax];
vi w[nax];
int g[nax];

void dfs(int a) {
	vis[a] = true;
	for(int b : w[a]) if(!vis[b]) {
		g[b] = g[a] ^ 1;
		dfs(b);
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	REP(_, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].pb(b);
		w[b].pb(a);
	}
	RI(i, n) if(!vis[i]) dfs(i);
	RI(a, n) for(int b : w[a]) if(g[a] == g[b]) {
		puts("-1");
		return 0;
	}
	vi one, two;
	RI(a, n) {
		if(g[a]) one.pb(a);
		else two.pb(a);
	}
	REP(_, 2) {
		printf("%d\n", sz(one));
		for(int x : one) printf("%d ", x);
		puts("");
		swap(one, two);
	}
	return 0;
}