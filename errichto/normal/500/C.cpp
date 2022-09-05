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
const int nax = 1e6 + 5;

bool vis[nax];
int w[nax];
int kol[nax];
vi cyk;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	RI(i, n) scanf("%d", &w[i]);
	RI(i, m) scanf("%d", &kol[i]);
	RI(i, m) if(!vis[kol[i]]) {
		vis[kol[i]] = true;
		cyk.pb(kol[i]);
	}
	int res = 0;
	RI(i, m) {
		int gdzie = 0;
		while(cyk[gdzie] != kol[i]) {
			res += w[cyk[gdzie]];
			gdzie++;
		}
		FORD(j, gdzie, 1) cyk[j] = cyk[j-1];
		cyk[0] = kol[i];
	}
	printf("%d\n", res);
	
	return 0;
}