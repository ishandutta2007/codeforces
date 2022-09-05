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
	int x, y;
	P(int x = 0, int y = 0) : x(x), y(y) {}
	P operator + (const P & b) const { return P(x+b.x, y+b.y); }
	P operator - (const P & b) const { return P(x-b.x, y-b.y); }
	P & operator += (const P & b) { return *this = *this + b; }
	P & operator -= (const P & b) { return *this = *this - b; }
	ll operator * (const P & b) const { return (ll)x*b.y - (ll)y*b.x; }
	ll dotProduct(const P & b) const { return (ll)x*b.x + (ll)y*b.y; }
	void wypisz() { printf("(%d, %d), ", x, y); }
	void wczytaj() { scanf("%d%d", &x, &y); }
	bool prawy() const { return x > 0 || (!x && y > 0); }
	bool lewy() const { return x < 0 || (!x && y < 0); }
	bool operator < (const P & b) const { return *this * b < 0; }
	bool operator == (const P & b) const { return x == b.x && y == b.y; }
	ld norm() { return sqrt((ll) x * x + (ll) y * y); }
};

bool cmp_lewoprawo(const P & a, const P & b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }

bool cmp_okrag(const P & a, const P & b) { return a.prawy() != b.prawy() ? a.prawy() : a * b < 0; }

vector<P> hull(vector<P> w) {
	// http://codeforces.com/gym/100173 - problem A
	// http://poj.org/problem?id=1294
	// http://www.spoj.com/problems/GARDENHU/
	sort(w.begin(), w.end(), cmp_lewoprawo);
	w.resize(unique(w.begin(), w.end()) - w.begin());
	vector<P> res;
	int L = 0;
	REP(_, 2) {
		for(auto & C : w) {
			while((int) res.size() >= L + 2) {
				P A = res[(int) res.size() - 2];
				P B = res.back();
				if((C-A) * (B-A) >= 0) break;
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

vector<P> wczytaj() {
	int n;
	scanf("%d", &n);
	vector<P> w;
	w.resize(n);
	REP(i, n) w[i].wczytaj();
	return hull(w);
}

#include<set>
set<pii > s;

void wypisz(vector<P> w) {
	for(auto p : w) p.wypisz(); puts("");
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	vector<P> a = wczytaj(), b = wczytaj();
	vector<P> razem = a;
	for(auto p : b) razem.pb(p);
	razem = hull(razem);
	bool ok = true;
	if(sz(razem) != sz(a)) ok = false;
	else REP(i, sz(razem)) if(razem[i].x != a[i].x || razem[i].y != a[i].y) ok = false;
	for(auto p : a) s.insert(mp(p.x, p.y));
	for(auto p : b) if(s.find(mp(p.x, p.y)) != s.end()) ok = false;
	puts(ok ? "YES" : "NO");
	
	return 0;
}