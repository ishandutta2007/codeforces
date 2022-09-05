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

const ld eps = 1e-10;

struct P {
	ld x, y;
	P(ld x = 0, ld y = 0) : x(x), y(y) {}
	void wypisz() { if(debug) printf("(%.3Lf, %.3Lf), ", x, y); }
	bool operator < (const P & b) const { return x + eps < b.x || (abs(x - b.x) < eps && y < b.y); }
};

struct L {
	int a, b, c;
	L(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}
	void wczytaj() { scanf("%d%d%d", &a, &b, &c); }
	bool operator < (const L & inny) const {
		if(inny.b == 0) return false;
		if(b == 0) return true;
		return a * inny.b < b * inny.a;
	}
	void wypisz() { printf("(%d,%d,%d)\n", a,b,c); }
	P przetnij(const L & inny) {
		ld det = a * inny.b - inny.a * b;
		return P((inny.b * c - b * inny.c) / det, (a * inny.c - inny.a * c) / det);
	}
};

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n;
	scanf("%d", &n);
	vector<L> w(n);
	REP(i, n) w[i].wczytaj();
	REP(i, n) if(w[i].b < 0) {
		w[i].a *= -1;
		w[i].b *= -1;
		w[i].c *= -1;
	}
	sort(w.begin(), w.end());
	ld RES = 0;
	
	REP(i, n) {
		ld sum_x = 0, sum_y = 0;
		FOR(j, i + 1, i + n - 1) {
			P p = w[i].przetnij(w[j%n]);
			RES += p.x * sum_y - p.y * sum_x;
			sum_x += p.x;
			sum_y += p.y;
		}
	}
	
	ld ile = (ld) n * (n-1) * (n-2) / 6.L;
	RES /= ile * 2.L;
	
	printf("%.9lf\n", (double) RES);
		
	return 0;
}