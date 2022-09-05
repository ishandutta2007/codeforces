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
	void wypisz() { printf("(%d, %d)\n", x, y); }
	void wczytaj() { scanf("%d%d", &x, &y); }
	bool prawy() const { return x > 0 || (!x && y > 0); }
	bool lewy() const { return x < 0 || (!x && y < 0); }
	bool operator < (const P & b) const { return *this * b < 0; }
	bool operator == (const P & b) const { return x == b.x && y == b.y; }
	ld norm() { return sqrt((ll) x * x + (ll) y * y); }
};

bool cmp_lewoprawo(const P & a, const P & b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }

bool cmp_okrag(const P & a, const P & b) { return a.prawy() != b.prawy() ? a.prawy() : a * b < 0; }

vector<P> hull(vector<P> & w) {
	// http://www.spoj.com/problems/GARDENHU/
	// http://codeforces.com/problemset/problem/166/B - razem z brzegami
	// http://www.spoj.com/problems/BSHEEP/ - wszystko brzegowe
	sort(w.begin(), w.end(), cmp_lewoprawo);
	w.resize(unique(w.begin(), w.end()) - w.begin());
	vector<P> res;
	int L = 0;
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

int n;
vector<P> w, rec;
vector<P> result; int liczba_res = -1;

void f(pii lin, pii kwa, int i) {
	if(sz(rec) == n) {
		int a = n * (kwa.st + kwa.nd) - lin.st * lin.st - lin.nd * lin.nd;
		if(a > liczba_res) {
			liczba_res = a;
			result = rec;
		}
		return;
	}
	if(i == sz(w)) return;
	f(lin, kwa, i + 1);
	lin.st += w[i].x;
	lin.nd += w[i].y;
	kwa.st += w[i].x * w[i].x;
	kwa.nd += w[i].y * w[i].y;
	rec.pb(w[i]);
	f(lin, kwa, i);
	rec.pop_back();
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int r;
	scanf("%d%d", &n, &r);
	FOR(x, -r, r) FOR(y, -r, r) if(x * x + y * y <= r * r) w.pb(P(x, y));
	w = hull(w);
	if(n % 2 == 0) {
		w.clear();
		w.pb(P(-r, 0));
		w.pb(P(r, 0));
	}
	f(mp(0,0), mp(0,0), 0);
	printf("%d\n", liczba_res);
	for(auto p : result) printf("%d %d\n", p.x, p.y);
	
	return 0;
}