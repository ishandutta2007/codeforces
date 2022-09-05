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
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

struct P {
	int x, y;
	P(int x = 0, int y = 0) : x(x), y(y) {}
	P operator + (const P & b) const { return P(x+b.x, y+b.y); }
	P operator - (const P & b) const { return P(x-b.x, y-b.y); }
	P & operator += (const P & b) { return *this = *this + b; }
	P & operator -= (const P & b) { return *this = *this - b; }
	int operator * (const P & b) const { return x*b.y - y*b.x; }
	int dotProduct(const P & b) const { return x*b.x + y*b.y; }
	void wypisz() { printf("(%d, %d), ", x, y); }
	void wczytaj() { scanf("%d%d", &x, &y); }
	bool prawy() const { return mp(x,y) > mp(0,0); }
	bool lewy() const { return mp(x,y) < mp(0,0); }
	bool operator < (const P & b) const {
		return prawy() != b.prawy() ? prawy() : *this * b < 0;
	}
};

P p;

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n;
	scanf("%d", &n);
	P orig;
	orig.wczytaj();
	vector<P> w;
	REP(_, n) {
		P p;
		p.wczytaj();
		p -= orig;
		w.pb(p.prawy() ? p : P() - p);
	}
	sort(w.begin(), w.end());
	int r = 0;
	REP(i, (int) w.size()) {
		++r;
		while(i + 1 < (int) w.size() && w[i] * w[i+1] == 0) ++i;
	}
	printf("%d\n", r);
	return 0;
}