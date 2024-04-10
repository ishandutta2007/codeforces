#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,(n))
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
const int nax = 1e6 + 5;

struct P {
	ll x, y;
	int i;
	P(ll a, ll b, int c) { x = a; y = b; i = c; }
	ll operator * (const P & b) const { return (ll)x*b.y - (ll)y*b.x; }
	P operator - (const P & b) const { return P(x-b.x, y-b.y,-1); }
	bool operator == (const P & b) const { return x==b.x && y==b.y; }
};

const int zly = 0;
void zluj(int & a) { a = zly; }

vector<P> hull(vector<P> w) {
	sort(w.begin(), w.end(), [](const P & a, const P & b) {
		return a.x < b.x || (a.x == b.x && a.y < b.y);
	});
	vector<P> razem;
	REP(_, 2) {
		vector<P> h;
		for(auto & C : w) {
			if(!h.empty() && h.back() == C) {
				if(h.back().i != C.i) zluj(h.back().i);
				continue;
			}
			while(sz(h) >= 2) {
				P A = h[sz(h)-2];
				P B = h[sz(h)-1];
				if((B-A)*(C-A)<=0) break;
				h.pop_back();
			}
			h.pb(C);
		}
		REP(i, sz(h)-1) razem.pb(h[i]);
		reverse(w.begin(), w.end());
	}
	return razem;
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n[2];
	REP(i, 2) scanf("%d", &n[i]);
	int rr, rrr;
	scanf("%d%d", &rr, &rrr);
	vector<P> w;
	ll maxx = 0, maxy = 0;
	REP(r, 2) REP(i, n[r]) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		maxi(maxx,x);
		maxi(maxy,y);
		w.pb(P(x,y,r));
	}
	w.pb(P(0LL,0LL,2));
	w.pb(P(maxx,0LL,2));
	w.pb(P(0LL,maxy,2));
	w = hull(w);
	for(P p : w) if(p.i == zly) {
		puts("Max");
		return 0;
	}
	puts("Min");
	return 0;
}