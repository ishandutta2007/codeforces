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

int par[nax];
vi w[nax];
int sub[nax];
int ans[nax];

void dfs(int a) {
	sub[a] = 1;
	pii big = mp(0,0);
	for(int b : w[a]) {
		dfs(b);
		sub[a] += sub[b];
		maxi(big, mp(sub[b], b));
	}
	if(2 * big.first <= sub[a])
		ans[a] = a;
	else {
		assert(big != mp(0,0));
		ans[a] = ans[big.second];
		while((sub[a] - sub[ans[a]]) * 2 > sub[a])
			ans[a] = par[ans[a]];
	}
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	FOR(i,2,n) {
		scanf("%d", &par[i]);
		w[par[i]].pb(i);
	}
	dfs(1);
	while(q--) {
		int a;
		scanf("%d", &a);
		printf("%d\n", ans[a]);
	}
	return 0;
}