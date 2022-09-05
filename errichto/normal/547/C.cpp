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
const int nax = 500123;

int tab[nax];
vi w[nax];
bool isPrime[nax];
vi parze, nie;

void rec(int a, int i, int ilo, bool parz) {
	if(i == sz(w[a])) {
		if(ilo == 1) return;
		if(parz) parze.pb(ilo);
		else nie.pb(ilo);
		return;
	}
	rec(a,i+1,ilo,parz);
	rec(a,i+1,ilo*w[a][i],!parz);
}

bool vis[nax];
int spec[nax];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	FOR(i,2,nax-1)isPrime[i]=true;
	FOR(i,2,nax-1)if(isPrime[i]) {
		w[i].pb(i);
		for(int j = 2 * i; j < nax; j += i) {
			isPrime[j] = false;
			w[j].pb(i);
		}
	}
	
	int n, q;
	scanf("%d%d", &n, &q);
	RI(i, n) scanf("%d", &tab[i]);
	ll res = 0;
	ll ile = 0;
	while(q--) {
		int i;
		scanf("%d", &i);
		int A = tab[i];
		parze.clear();
		nie.clear();
		//printf("%d: ", A);
		//for(auto on : w[A]) printf("%d, ", on);
		//puts("\n----");
		rec(A,0,1,true);
		int d = 1;
		if(vis[i]) {
			ile--;
			vis[i] = false;
			for(int a : parze) spec[a]--;
			for(int a : nie) spec[a]--;
			for(int a : parze) res += d * spec[a];
			for(int a : nie) res -= d * spec[a];
		}
		else {
			ile++;
			vis[i] = true;
			for(int a : parze) res -= d * spec[a];
			for(int a : nie) res += d * spec[a];
			
			for(int a : parze) spec[a]++;
			for(int a : nie) spec[a]++;
		}
		printf("%lld\n", ile*(ile-1)/2-res);
	}
	
	return 0;
}