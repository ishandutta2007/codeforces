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
#define M_PI acos(-1)

ld uspokuj(ld a) { return max(-1.L, min(1.L, a)); }

struct P {
	int x, y;
	P(int _x, int _y) { x = _x; y = _y; }
	P() { x = y = 0; }
	void wczytaj() { scanf("%d%d", &x, &y); }
	int operator *(P b) const { return x * b.y - y * b.x; }
	bool operator <(P b) const { return *this * b < 0; }
	int dot(P b) { return x * b.x + y * b.y; }
	ld norm() { return sqrt((ld) x * x + y * y); }
	ld angleTo(P b) {
		ld nn = norm() * b.norm();
		ld alpha = acos(uspokuj(dot(b) / nn));
		ld a = asin(uspokuj((*this * b) / nn));
		if(a > 0) alpha = 2 * M_PI - alpha;
		return alpha;
	}
};

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	ld res = 360;
	
	int n;
	scanf("%d", &n);
	vector<P> lewo;
	vector<P> prawo;
	REP(i, n) {
		P a;
		a.wczytaj();
		if(a.x > 0 || (a.x == 0 && a.y > 0)) prawo.pb(a);
		else lewo.pb(a);
	}
	sort(prawo.begin(), prawo.end());
	sort(lewo.begin(), lewo.end());
	for(auto a : lewo) prawo.pb(a);
	prawo.pb(prawo[0]);
	REP(i, (int) prawo.size() - 1) {
		ld alpha = prawo[i].angleTo(prawo[i+1]) * 180.L / M_PI;
		if(alpha < 1e-12 && i == (int) prawo.size() - 2)
			alpha = 360;
		mini(res, 360 - alpha);
	}
	printf("%.10lf\n", (double) res);
	return 0;
}