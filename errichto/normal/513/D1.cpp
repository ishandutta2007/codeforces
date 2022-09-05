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

int maxprawy[nax], minprawy[nax], maxlewy[nax], minlewy[nax], maxojciec[nax];
vi ojcowie[nax];
bool ok = true;
vi glob;
bool ma[nax];

void f(int low, int high) {
	if(!ok) {
		return;
	}
	if(low > high) {
		return;
	}
	if(low == high) {
		if(ma[low]) ok = false;
		glob.pb(low);
		return;
	}
	int root = low;
	++low;
	int lewy = low, prawy = high; // co teraz wezme
	int cel_lewy = max(low - 1, maxlewy[root]), cel_prawy = min(high + 1, minprawy[root]);
	if(cel_prawy <= cel_lewy) {
		ok = false;
		return;
	}
	while(lewy <= high && prawy >= low && lewy <= cel_lewy && prawy >= cel_prawy) {
		// bierzemy lewego
		maxi(cel_lewy, max(maxlewy[lewy], maxprawy[lewy]));
		if(maxojciec[lewy] > lewy) ok = false;
		
		auto it = upper_bound(ojcowie[prawy].begin(), ojcowie[prawy].end(), root);
		if(it != ojcowie[prawy].end())
			mini(cel_prawy, *it);
		
		lewy++;
		prawy--;
	}
	if(lewy > cel_lewy) {
		f(low, lewy - 1);
		glob.pb(root);
		f(lewy, high);
		return;
	}
	if(prawy < cel_prawy) {
		f(low, prawy);
		glob.pb(root);
		f(prawy + 1, high);
		return;
	}
	ok = false;
	return;
}

vector< vi > cc;
int gdzie[nax];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n, c;
	scanf("%d%d", &n, &c);
	REP(i, n + 2) maxprawy[i] = maxlewy[i] = maxojciec[i] = -1;
	REP(i, n + 2) minlewy[i] = minprawy[i] = inf;
	REP(_, c) {
		int a, b;
		char sl[15];
		scanf("%d%d%s", &a, &b, sl);
		vi w;
		w.pb(a); w.pb(b); w.pb((int)(sl[0] == 'R'));
		cc.pb(w);
		//if(n == 35 && c == 48 && _ > 25) printf("%d %d %s\n", a, b, sl);
		if(a >= b) ok = false;
		if(sl[0] == 'R') {
			maxi(maxprawy[a], b);
			mini(minprawy[a], b);
		}
		else {
			maxi(maxlewy[a], b);
			mini(minlewy[a], b);
		}
		max(maxojciec[b], a);
		ojcowie[b].pb(a);
		ma[a] = true;
	}
	RI(i, n) sort(ojcowie[i].begin(), ojcowie[i].end());
	f(1, n);
	if(ok) REP(i, n) gdzie[glob[i]] = i + 1;
	if(ok) for(auto & w : cc) {
		int a = w[0], b = w[1];
		if(w[2] == 1 && gdzie[b] <= gdzie[a]) ok = false;
		if(w[2] == 0 && gdzie[b] >= gdzie[a]) ok = false;
	}
	if(!ok) printf("IMPOSSIBLE");
	else for(auto & a : glob) printf("%d ", a);
	puts("");
	
	return 0;
}