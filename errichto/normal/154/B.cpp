#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<unordered_set>
#include<assert.h>
using namespace std;
#define FOR(i,a,n) for(int i = (a); i <= (n); ++i)
#define FORD(i,a,n) for(int i = (a); i >= (n); --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,(n))
#define pb push_back
#define st first
#define nd second
#define mp make_pair
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e5 + 5;

bool isPrime[nax];
vi w[nax];
bool zap[nax];
unordered_set<int> s[nax];

void sieve() {
	for(int i = 2; i < nax; ++i) isPrime[i] = true;
	for(int i = 2; i < nax; ++i) if(isPrime[i]) {
		w[i].pb(i);
		for(int j = 2 * i; j < nax; j += i) {
			isPrime[j] = false;
			w[j].pb(i);
		}
	}
}

int check(int a) {
	for(auto p : w[a]) if(!s[p].empty())
		return *s[p].begin();
	return 0;
}

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	sieve();
	
	int n, m;
	scanf("%d%d", &n, &m);
	while(m--) {
		char sl[5];
		scanf("%s", sl);
		bool PLUS = (sl[0] == '+');
		int a;
		scanf("%d", &a);
		if(PLUS && zap[a]) puts("Already on");
		else if((!PLUS) && !zap[a]) puts("Already off");
		else if(!PLUS) {
			zap[a] = false;
			for(auto p : w[a]) s[p].erase(a);
			puts("Success");
		}
		else {
			assert(PLUS);
			int pom = check(a);
			if(pom > 0) printf("Conflict with %d\n", pom);
			else {
				zap[a] = true;
				puts("Success");
				for(auto p : w[a]) s[p].insert(a);
			}
		}
	}
	return 0;
}