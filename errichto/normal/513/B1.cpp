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

int t[nax];

void __brut(int n, int ktory) {
	REP(i, n) t[i] = i;
	int r = 0;
	do {
		int a = 0;
		REP(i, n) FOR(j, i, n - 1) {
			int z = inf;
			FOR(k, i, j) mini(z, t[k]);
			a += z;
		}
		maxi(r, a);
	} while(next_permutation(t, t + n));
	do {
		int a = 0;
		REP(i, n) FOR(j, i, n - 1) {
			int z = inf;
			FOR(k, i, j) mini(z, t[k]);
			a += z;
		}
		if(r == a) {
			REP(i, n) printf("%d ", t[i] + 1); puts("");
		}
	} while(next_permutation(t, t + n));
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n;
	ll ktory;
	scanf("%d%lld", &n, &ktory);
	ktory--;
	vi w;
	REP(_, n - 1) {
		w.pb(ktory % 2);
		ktory /= 2;
	}
	reverse(w.begin(), w.end());
	w.pb(0);
	int a = 1, b = n;
	REP(i, n) {
		if(w[i] == 1) {
			t[b] = i + 1;
			b--;
		}
		else {
			t[a] = i + 1;
			a++;
		}
	}
	RI(i, n) printf("%d ", t[i]);
	puts("");
	/*int licz = 0;
	RI(i, n) if(t[i] == 0) {
		if(licz == (int) w.size()) {
			t[i] = n;
			assert(n % 2 == 1);
			continue;
		}
		if(w[licz]) {
			t[i] = 2 * i;
			t[n+1-i] = 2 * i - 1;
		}
		else {
			t[i] = 2 * i - 1;
			t[n+1-i] = 2 * i;
		}
		licz++;
	}
	RI(i, n) printf("%d ", t[i]); puts("");*/
	
	return 0;
}