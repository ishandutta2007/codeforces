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
#define PI acos(-1)

ld uspokuj(ld a) { return max(-1.L, min(1.L, a)); }

ld get_ld() {
	double a;
	scanf("%lf", &a);
	return a;
}

struct P {
	int x, y;
	P(int _x, int _y) { x = _x; y = _y; }
	P() { x = y = 0; }
	void wczytaj() { scanf("%d%d", &x, &y); }
	int operator *(P b) const { return x * b.y - y * b.x; }
	P operator -(P b) const { return P(x - b.x, y - b.y); }
	bool operator <(P b) const { return *this * b < 0; }
	int dot(P b) { return x * b.x + y * b.y; }
	ld norm() {
		return sqrt((ld) x * x + y * y); }
	ld angleTo(P b) { // clockwise
		ld nn = norm() * b.norm();
		ld alpha = acos(uspokuj(dot(b) / nn));
		ld a = asin(uspokuj((*this * b) / nn));
		if(a > 0) alpha = 2 * PI - alpha;
		return alpha;
	}
};

int main(int argc, char *argv[])
{	
	debug = argc > 1;
	
	P a, b;
	a.wczytaj();
	ld r, R;
	r = get_ld();
	b.wczytaj();
	R = get_ld();
	if(r > R) swap(r, R);
	P p = a-b;
	ld d = p.norm();
	ld res = 0;
	if(r + R < d) res = (d - (R+r)) / 2;
	else if(r + d < R) res = (R - (d+r)) / 2;
	else res = 0;
	printf("%.8lf\n", (double) res);
	return 0;
}