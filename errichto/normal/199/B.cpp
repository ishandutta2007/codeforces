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
	ll x, y;
	P(ll x = 0, ll y = 0) : x(x), y(y) {}
	P operator + (const P & b) const { return P(x+b.x, y+b.y); }
	P operator - (const P & b) const { return P(x-b.x, y-b.y); }
	P & operator += (const P & b) { return *this = *this + b; }
	P & operator -= (const P & b) { return *this = *this - b; }
	ll operator * (const P & b) const { return x*b.y - y*b.x; }
	ll dotProduct(const P & b) const { return x*b.x + y*b.y; }
	void wypisz() { printf("(%lld, %lld), ", x, y); }
	void wczytaj() { scanf("%lld%lld", &x, &y); }
	bool prawy() const { return x > 0 || (!x && y > 0); }
	bool lewy() const { return x < 0 || (!x && y < 0); }
	bool operator < (const P & b) const { return *this * b < 0; }
	bool operator == (const P & b) const { return x == b.x && y == b.y; }
	ld norm() { return sqrt(x * x + y * y); }
};

bool cmp_lewoprawo(const P & a, const P & b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }

bool cmp_okrag(const P & a, const P & b) { return a.prawy() != b.prawy() ? a.prawy() : a * b < 0; }

vector<P> hull(vector<P> w) {
	// http://www.spoj.com/problems/GARDENHU/ - zwykle
	// http://codeforces.com/problemset/problem/166/B - razem z brzegami
	// http://www.spoj.com/problems/BSHEEP/ - wszystko
	sort(w.begin(), w.end(), cmp_lewoprawo);
	w.resize(unique(w.begin(), w.end()) - w.begin());
	vector<P> res;
	int L = 0;
	if(sz(res) == 1) return res;
	REP(_, 2) {
		for(auto & C : w) {
			while((int) res.size() >= L + 2) {
				P A = res[(int) res.size() - 2];
				P B = res.back();
				if((C-A) * (B-A) > 0) break;
				res.pop_back();
			}
			res.pb(C);
		}
		res.pop_back();
		reverse(w.begin(), w.end());
		L = (int) res.size();
	}
	return res;
}

const ld eps = 1e-10;

int f(ld r, ld R, ld d, ld inny) {
	if(d + eps >= R + inny) return 1;
	if(d + R <= inny + eps) return 1;
	if(d + inny <= r + eps) return 1;
	return 0;
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int x[2],y[2],r[2],R[2];
	REP(i, 2) scanf("%d%d%d%d", &x[i], &y[i], &r[i], &R[i]);
	ld d = (P(x[0], y[0]) - P(x[1], y[1])).norm();
	printf("%d\n", f(r[0], R[0], d, r[1]) + f(r[0], R[0], d, R[1]) + f(r[1], R[1], d, r[0]) + f(r[1], R[1], d, R[0]));
	return 0;
}