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

struct P {
	ld x, y;
	ld zasieg;
	P(ld x = 0, ld y = 0) : x(x), y(y) {}
	P operator + (const P & b) const { return P(x+b.x, y+b.y); }
	P operator - (const P & b) const { return P(x-b.x, y-b.y); }
	P & operator += (const P & b) { return *this = *this + b; }
	P & operator -= (const P & b) { return *this = *this - b; }
	ll operator * (const P & b) const { return x*b.y - y*b.x; }
	ll dotProduct(const P & b) const { return x*b.x + y*b.y; }
	void wczytaj() { scanf("%Lf%Lf", &x, &y); }
	bool prawy() const { return x > 0 || (!x && y > 0); }
	bool lewy() const { return x < 0 || (!x && y < 0); }
	// bool operator < (const P & b) const { return *this * b < 0; }
	bool operator == (const P & b) const { return x == b.x && y == b.y; }
	ld norm() { return sqrt(x * x + y * y); }
	ld angle() { return atan2(y, x); } // w radianach
	P rotate(ld angle) {
		ld s = sin(angle), c = cos(angle);
		return P(x * c - y * s, x * s + y * c);
	}
	void wypisz() { printf("(%Lf, %Lf  ...  %Lf),\n", x, y, angle()); }
};

const ld PI = 2 * acos(0);

ld na_stopnie(ld a) { return a * 180 / PI; }
ld na_radiany(ld a) { return a * PI / 180; }

ld dp[1 << 20];
P p[20];

int main(int argc, char *argv[]) {
	debug = argc > 1;
	
	int n, orig, ri;
	scanf("%d%d%d", &n, &orig, &ri);
	ld cel = ri - orig;
	REP(i, n) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		p[i] = P(a - orig, b);
		p[i].zasieg = na_radiany(c);
	}
	REP(m, 1 << 20) {
		ld tera = dp[m];
		REP(i, n) if(!(m & (1 << i))) {
			ld kat = P(tera - p[i].x, p[i].y).angle();
			kat -= p[i].zasieg;
			ld potem = tera;
			if(kat < 1e-10) potem = cel;
			else {
				assert(abs(kat - PI) > 1e-9);
				potem = min(cel, p[i].x + p[i].y / tan(kat));
			}
			maxi(dp[m | (1 << i)], potem);
		}
	}
	ld r = 0;
	REP(m, 1 << 20) maxi(r, dp[m]);
	printf("%.9lf\n", (double) r);
	
	return 0;
}