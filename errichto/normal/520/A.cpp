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

vector<P> hull(vector<P> & w) {
	// http://www.spoj.com/problems/GARDENHU/ - zwykle
	// http://codeforces.com/problemset/problem/166/B - razem z brzegami
	// http://www.spoj.com/problems/BSHEEP/ - wszystko
	//sort(w.begin(), w.end(), cmp_lewoprawo);
	//w.resize(unique(w.begin(), w.end()) - w.begin());
	if(sz(w) < 2) return w;
	vector<P> res;
	int L = 0;
	REP(_, 1) {
		for(auto & C : w) {
			while((int) res.size() >= L + 2) {
				P A = res[(int) res.size() - 2];
				P B = res.back();
				if((C-A) * (B-A) > 0) break;
				res.pop_back();
			}
			res.pb(C);
		}
		// res.pop_back();
		//reverse(w.begin(), w.end());
		L = (int) res.size();
	}
	return res;
}
char sl[nax];
int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n;
	scanf("%d", &n);
	scanf("%s", sl);
	REP(i, 26) {
		bool pyklo = false;
		REP(j, n) if(sl[j] == 'a' + i || sl[j] == 'A' + i) pyklo = true;
		if(!pyklo) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
	
	int r = atoi(argv[1]);
	int x = r;
	vector<P> w;
	FOR(y, 0, r) {
		while((ll)y * y + (ll)x * x > (ll)r * r) --x;
		w.pb(P(y,x));
	}
	w = hull(w);
	printf("%d, ", sz(w));
	
	return 0;
}