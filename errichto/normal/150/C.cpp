#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
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
const int inf = 1e9;
const int nax = 1e6 + 5;
const int pot = 256 * 1024;

int x[nax], p[nax];
ld z[nax];
struct P {
	ld lewy, prawy, caly, wyn;
	P() { lewy = prawy = caly = wyn = 0; }
	P(ld a) { lewy = prawy = caly = wyn = a; }
	P merguj(P & b) {
		P nowy = P();
		nowy.lewy = max(lewy, caly + b.lewy);
		nowy.prawy = max(b.prawy, prawy + b.caly);
		nowy.caly = caly + b.caly;
		nowy.wyn = max({wyn, b.wyn, prawy + b.lewy});
		return nowy;
	}
};
P tr[2 * pot];

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	int n, m, c;
	scanf("%d%d%d", &n, &m, &c);
	RI(i, n) scanf("%d", &x[i]);
	RI(i, n - 1) scanf("%d", &p[i]);
	RI(i, n - 1) tr[pot + i] = P((x[i+1] - x[i]) / 2.L - p[i] * c / 100.L);
	FORD(i, pot - 1, 1) tr[i] = tr[2*i].merguj(tr[2*i+1]);
	ld R = 0;
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		a += pot; b += pot;
		P ja = tr[a];
		b--;
		P prawy = tr[b];
		while(a < b - 1) {
			if(a % 2 == 0) ja = ja.merguj(tr[a+1]);
			if(b % 2 == 1) prawy = tr[b-1].merguj(prawy);
			a /= 2;
			b /= 2;
		}
		if(a != b)
		ja = ja.merguj(prawy);
		maxi(ja.wyn, 0.L);
		R += ja.wyn;
	}
	printf("%.9lf\n", (double) R);
	return 0;
}
	
	
	/*
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		w.pb(mp(a, 1));
		w.pb(mp(b, -1));
	}
	sort(w.begin(), w.end());
	w.pb(mp(inf, 0));
	int wsk = 0;
	int L = 0;
	ld RES = 0, r = 0;
	RI(i, n - 1) {
		int d = x[i+1] - x[i];
		while(w[wsk].st == i) {
			L += w[wsk].nd;
			++wsk;
		}
		ld z = (ld) L * (d / 2.L - (ld) p[i] * c / 100.L);
		zz[i] = z;
		r += z;
		maxi(r, 0.L);
		printf("%d, %.3d  %.3lf     %.3lf\n", L, d, (double) z, (double) r);
		maxi(RES, r);
	}
	printf("%.9lf\n", (double) RES);
	
	RES = 0;
	RI(a, n - 1) FOR(b, a, n - 1) {
		ld iles = 0;
		FOR(i, a, b) iles += zz[i];
		maxi(RES, iles);
	}
	printf("%.9lf\n", (double) RES);
	
	return 0;
}
*/