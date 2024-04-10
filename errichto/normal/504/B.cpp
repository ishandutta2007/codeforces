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
const int pot = 512 * 1024;

int n;
int tr[2 * pot + 5];

vi f() {
	vi w;
	REP(i, n) {
		int a;
		scanf("%d", &a);
		for(int x = a + pot; x > 0; x /= 2)
			tr[x]++;
		int licz = 0;
		for(int x = a + pot; x > 0; x /= 2)
			if(x % 2 == 1)
				licz += tr[x-1];
		w.pb(a - licz);
	}
	REP(i, 2 * pot + 5) tr[i] = 0;
	if(debug) for(auto a : w) printf("%d ", a);
	if(debug) puts("");
	return w;
}

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	scanf("%d", &n);
	vi a = f();
	vi b = f();
	RI(i, n) {
		int s = a[n-i] + b[n-i];
		if(i < n) a[n-i-1] += s / i;
		a[n-i] = s % i;
	}
	if(debug) {
		puts("zsumowane:");
		for(auto x : a) printf("%d ", x);
		puts("\n\n");
	}
	
	REP(i, n) tr[i + pot] = 1;
	FORD(i, pot - 1, 1) tr[i] = tr[2*i] + tr[2*i+1];
	
	for(auto x : a) {
		// ma byc x mniejszych
		int low = x, high = n-1;
		while(low < high) {
			if(debug) printf("\n\ndupka = %d %d\n", low, high);
			int med = (low + high) / 2;
			int licz = 0;
			for(int i = pot + med; i > 0; i /= 2)
				if(i % 2 == 1)
					licz += tr[i-1];
			if(licz > x || (licz == x && tr[pot + med] == 1)) high = med;
			else low = med + 1;
			if(debug) printf("dup2 = %d %d\n\n", low, high);
		}
		assert(tr[pot + low] == 1);
		for(int i = pot + low; i > 0; i /= 2)	tr[i]--;
		printf("%d ", low);
	}
	
	return 0;
}