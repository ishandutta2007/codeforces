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

bool spec[nax];
vi w[nax];
long long ans;
int sub[nax];
int k;

void dfs(int a, int par) {
	sub[a] = spec[a];
	for(int b : w[a]) if(b != par) {
		dfs(b, a);
		ans += min(sub[b], 2 * k - sub[b]);
		sub[a] += sub[b];
	}
}

int main() {
	int n;
	scanf("%d%d", &n, &k);
	RI(i, 2 * k) {
		int a;
		scanf("%d", &a);
		spec[a] = true;
	}
	REP(_, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].pb(b);
		w[b].pb(a);
	}
	dfs(1, -1);
	printf("%lld\n", ans);
	return 0;
}