#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
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
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

vi w[nax];
set<int> pozostale;
vector<vi > res;
int st[nax];

void zacznij(int pierwszy) {
	vi kol;
	kol.pb(pierwszy);
	REP(i, (int) kol.size()) {
		pozostale.erase(kol[i]);
		for(auto b : w[kol[i]]) ++st[b];
		if(i == (int) kol.size() - 1) {
			int memo_size = (int) kol.size();
			for(auto b : pozostale)
				if(st[b] != memo_size)
					kol.pb(b);
		}
	}
	res.pb(kol);
	for(auto a : kol) for(auto b : w[a]) st[b] = 0;
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n, m;
	scanf("%d%d", &n, &m);
	RI(i, n) pozostale.insert(i);
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].pb(b);
		w[b].pb(a);
	}
	
	RI(a, n) if(pozostale.find(a) != pozostale.end()) zacznij(a);
	
	printf("%d\n", (int) res.size());
	for(auto & w : res) {
		printf("%d ", (int) w.size());
		for(auto a : w) printf("%d ", a);
		puts("");
	}
	
	return 0;
}