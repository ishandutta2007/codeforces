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
const int inf = 1e9 + 5;
const int nax = 1e3 + 5;

int p[nax];
char s[nax];
bool ok[nax][nax];
bool vis[nax];
vi w;
int n;

void dfs(int a) {
	vis[a] = true;
	w.pb(a);
	RI(i, n) if(ok[a][i] && ! vis[i]) dfs(i);
}

int main() {
	scanf("%d", &n);
	RI(i, n) scanf("%d", &p[i]);
	REP(i, n) {
		scanf("%s", s);
		REP(j, n) if(s[j] == '1') ok[i+1][j+1] = true;
	}
	RI(i, n) if(!vis[i]) {
		dfs(i);
		// for(auto a : w) debug("%d ", a); debug("\n");
		vi wart;
		for(auto a : w) wart.pb(p[a]);
		sort(wart.begin(), wart.end());
		sort(w.begin(), w.end());
		REP(j, (int) wart.size()) p[w[j]] = wart[j];
		w.clear();
	}
	RI(i, n) printf("%d ", p[i]);
	printf("\n");
	return 0;
}