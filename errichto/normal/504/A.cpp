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
const int nax = 1e6 + 5;

int st[nax], suma[nax];
struct cmp {
	bool operator()(int a, int b) {
		if(st[a] == st[b]) return a < b;
		return st[a] < st[b];
	}
};
set<int, cmp> s;

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	int n;
	scanf("%d", &n);
	int pomik = 0;
	REP(i, n) {
		scanf("%d%d", &st[i], &suma[i]);
		pomik += st[i];
	}
	REP(i, n) s.insert(i);
	printf("%d\n", pomik / 2);
	while(!s.empty()) {
		auto it = s.begin();
		int a = *it;
		s.erase(it);
		if(st[a]) {
			printf("%d %d\n", a, suma[a]);
			int b = suma[a];
			s.erase(b);
			st[b]--;
			
			suma[b] ^= a;
			s.insert(b);
		}
		if(debug) {
			printf("debug ");
			for(auto a : s) printf("(%d, %d, %d),  ", a, st[a], suma[a]);
		}
	}
	return 0;
}