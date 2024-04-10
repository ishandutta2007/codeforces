#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
#define FOR(i,a,n) for(int i = (a); i <= (n); ++i)
#define FORD(i,a,n) for(int i = (a); i >= (n); --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,(n))
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#ifdef LOK
#define debug printf
#else
#define debug if(0)printf
#endif
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<pii > vii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

vii w[nax];
bool vis[nax];
int sub[nax], d[nax], ojc[nax];
ld prob[nax];
int n;

void dfs(int a) {
	vis[a] = true;
	sub[a] = 1;
	for(auto p : w[a]) {
		if(!vis[p.st]) {
			ojc[p.st] = a;
			dfs(p.st);
			sub[a] += sub[p.st];
		}
	}
	for(auto p : w[a])
		if(p.st != ojc[a])
			prob[p.nd] = 2.L * sub[p.st] * (n - sub[p.st]) / n / (n-1);
}

int main() {
	scanf("%d", &n);
	RI(i,  n - 1) {
		int a, b;
		scanf("%d%d%d", &a, &b, &d[i]);
		w[a].pb(mp(b, i));
		w[b].pb(mp(a, i));
	}
	dfs(1);
	ld res = 0;
	RI(a, n) for(auto p : w[a]) if(p.st != ojc[a])
		res += prob[p.nd] * d[p.nd];
	int q;
	scanf("%d", &q);
	while(q--) {
		int i, na;
		scanf("%d%d", &i, &na);
		res -= prob[i] * (d[i] - na);
		printf("%.10lf\n", double(res * 3.0L));
		d[i] = na;
	}
	return 0;
}