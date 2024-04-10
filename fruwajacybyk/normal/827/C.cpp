#include <bits/stdc++.h>
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define all(v) (v).begin(),(v).end()
 
#define PII pair<int,int>
#define st first
#define nd second
#define pb push_back
#define lint long long int
#define VI vector<int>

using namespace std;

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
} 

template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}


#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
 
#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue
 
#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}
#define jeb fflush(stdout)

const int max_n = 1e5+5;

int n;
char s[max_n];
int fen[max_n][5][10][4];

void add(int pref, int mod, int a, int let, int ile) {
	while (pref <= n) {
		fen[pref][mod-6][a][let] += ile;
		pref += (pref & (-pref));
	}
}

int ask(int pref, int mod, int a, int let) {
	int ans = 0;
	while (pref !=0 ) {
		ans += fen[pref][mod-6][a][let];
		pref ^= (pref &(-pref));
	}
	return ans;
}

char t[20];

map<char, int> mapa;

int main () {
	scanf("%s", s);
	n = strlen(s);
	mapa['A'] = 0;
	mapa['C'] = 1;
	mapa['T'] = 2;
	mapa['G'] = 3;
	FOR(i,0,n) {
		FOR(j,6,11) add(i+1, j, (i+1)%j, mapa[s[i]], 1);		
	}
	make(q);
	while (q--) {
		make(type);
		if (type == 1) {
			int x; char C;
			scanf("%d %c\n",&x, &C);
			FOR(j,6,11) add(x, j, x%j, mapa[s[x-1]], -1);
			FOR(j,6,11) add(x, j, x%j, mapa[C], 1);
			s[x-1] = C;
		} else {
			make2(l, r);
			scanf("%s", t);
			int z = strlen(t);
			while (z < 6) {
				FOR(j,z,2*z) t[j] = t[j-z];
				z = 2*z;
			}
			int ans = 0;
			FOR(j,0,z) {
				ans += ask(r,z,(j+l)%z,mapa[t[j]]) - ask(l-1,z,(j+l)%z,mapa[t[j]]);
			}
			printf("%d\n", ans);
		}
	}
}