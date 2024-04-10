#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e5 + 5;
const int pot = 128 * 1024;

int t[nax], roz[nax];
pii tr[2 * pot];

ll f(int a, int b) {
	if(a == b) return 0;
	
	int low = pot + a, high = pot + b - 1;
	//printf("%d %d\n", tr[low].nd, tr[high].nd);
	pii x = max(tr[low], tr[high]);
	while(low < high - 1) {
		if(low % 2 == 0) maxi(x, tr[low + 1]);
		if(high % 2 == 1) maxi(x, tr[high - 1]);
		low /= 2;
		high /= 2;
	}
	
	int i = x.nd;
	ll val = x.st;
	
	int n = b - a + 1;
	int lewy = i - a + 1;
	int prawy = n - lewy;
	
	//printf("%lld %d %d\n", val, lewy, prawy);
	return f(a, i) + f(i + 1, b) + val * lewy * prawy;
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	RI(i, n) scanf("%d", &t[i]);
	RI(i, n - 1) roz[i] = abs(t[i+1] - t[i]);
	RI(i, n - 1) tr[pot + i] = mp(roz[i], i);
	FORD(i, pot - 1, 1) tr[i] = max(tr[2*i], tr[2*i+1]);
	while(q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%lld\n", f(a, b));
		//return  0;
	}
	return 0;
}