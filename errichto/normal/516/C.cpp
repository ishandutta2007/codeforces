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
const int nax = 1e5 + 5;
const int pot = 128 * 1024;

struct P {
	ll pref, suf, wyn, caly;
	P() { pref = suf = wyn = caly = 0; }
	void wypisz() {
		if(debug) printf("%lld %lld %lld %lld\n", pref, suf, wyn, caly);
	}
};
P merguj(P & a, P & b) {
	if(a.caly == 0) return b;
	if(b.caly == 0) return a;
	P c;
	c.pref = max(a.pref, a.caly + b.pref);
	c.suf = max(b.suf, b.caly + a.suf);
	c.wyn = max({a.wyn, b.wyn, a.suf + b.pref});
	c.caly = a.caly + b.caly;
	return c;
}

ll d[nax], h[nax];
P tr[2 * pot];

P f(int a, int b) {
	if(a > b) return tr[0]; // zerowe
	a += pot;
	b += pot;
	if(a == b) return tr[a];
	P lewy = tr[a], prawy = tr[b];
	while(a < b - 1) {
		if(a % 2 == 0) lewy = merguj(lewy, tr[a + 1]);
		if(b % 2 == 1) prawy = merguj(tr[b-1], prawy);
		a /= 2;
		b /= 2;
	}
	return merguj(lewy, prawy);
}

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	int n, z;
	scanf("%d%d", &n, &z);
	RI(i, n) scanf("%lld", &d[i]);
	RI(i, n) {
		scanf("%lld", &h[i]);
		h[i] *= 2;
	}
	
	RI(i, n) {
		tr[pot + i].pref = h[i];
		tr[pot + i].suf = d[i] + h[i];
		tr[pot + i].wyn = 0;
		tr[pot + i].caly = d[i];
	}
	FORD(i, pot - 1, 1) tr[i] = merguj(tr[2*i], tr[2*i+1]);
	
	while(z--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(a <= b) {
			P p1 = f(b + 1, n);
			P p2 = f(1, a - 1);
			p1 = merguj(p1, p2);
			printf("%lld\n", p1.wyn);
		}
		else {
			P p = f(b + 1, a - 1);
			printf("%lld\n", p.wyn);
		}
	}
	
	return 0;
}