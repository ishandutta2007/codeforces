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

int n, rekord, d;
char sl[15];
vector<pii > w;
int o[nax];

int find(int a) {
	return a == o[a] ? a : o[a] = find(o[a]);
}
void uni(int a, int b) {
	o[find(a)] = find(b);
}

int f(char z) {
	return int(z - '0');
}

void wczytaj() {
	scanf("%d%d%d", &n, &rekord, &d);
	RI(i, n) {
		scanf("%s", sl);
		int hh = f(sl[0]) * 10 + f(sl[1]);
		int mm = f(sl[3]) * 10 + f(sl[4]);
		int ss = f(sl[6]) * 10 + f(sl[7]);
		//printf("%d %d %d\n", hh, mm, ss);
		int jeb = ss + 60 * mm + 3600 * hh;
		w.pb(mp(jeb, i));
	}
}

#include<set>
#include<map>
map<int,int> mapka;

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	wczytaj();
	
	multiset<pii > s;
	RI(i, n) o[i] = i;
	bool pyklo = false;
	
	REP(i, sz(w)) {
		pii p = w[i];
		int kiedy = p.st;
		int id = p.nd;
		//printf("%d %d\n", kiedy, id);
		while((!s.empty()) && (*s.begin()).st < kiedy) s.erase(s.begin());
		s.insert(mp(kiedy + d - 1, id));
		if(i == sz(w) - 1 || w[i+1].st != w[i].st) {
			if(sz(s) == rekord) pyklo = true;
			while(sz(s) > rekord) {
				auto it = s.end();
				--it;
				if(it == s.begin()) {
					puts("No solution");
					return 0;
				}
				int memo = (*it).nd;
				--it;
				int teraz = (*it).nd;
				uni(memo, teraz);
				s.erase(it);
			}
		}
	}
	if(sz(s) == rekord) pyklo = true;
	if(!pyklo) {
		puts("No solution");
		return 0;
	}
	
	RI(i, n) find(i);
	set<int> dupsko;
	RI(i, n) dupsko.insert(o[i]);
	int L = 0;
	for(auto a : dupsko) mapka[a] = ++L;
	printf("%d\n", L);
	RI(i, n) printf("%d\n", mapka[o[i]]);
	
	return 0;
}