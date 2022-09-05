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
typedef int ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

ll K(ll a) { return a * a; }

struct P {
	ll x, y;
	P() {}
	P(ll _x, ll _y) : x(_x), y(_y){}
	ll operator * (const P & b) { return x*b.y-y*b.x; }
	ld norm1() { return sqrtl(K(x)+K(y)); }
	P operator - (const P & b) { return P(x-b.x, y-b.y); }
	void wczytaj() { scanf("%d%d", &x, &y); }
};

ll pole3(P A, P B, P C) {
	B = B - A;
	C = C - A;
	return abs(B * C);
}

vector<P> hull(vector<P> & w) {
	vector<P> razem;
	REP(_, 2) {
		vector<P> h;
		for(auto & C : w) {
			while(sz(h) >= 2) {
				P & A = h[sz(h)-2];
				P & B = h[sz(h)-1];
				if((B-A)*(C-A)<0) break;
				h.pop_back();
			}
			h.pb(C);
		}
		REP(i, sz(h)-1) razem.pb(h[i]);
		reverse(w.begin(), w.end());
	}
	return razem;
}

ll odl(const P & a, const P & b) { return K(a.x-b.x) + K(a.y-b.y); }
ll res;
void rozwaz(const P & a, const P & b) { maxi(res, odl(a,b)); }
ll najdalsze(vector<P> w) {
	if(w.empty()) return 0;
	res = 0;
	w = hull(w);
	int n = sz(w);
	int wsk = 1;
	REP(i, n) {
	    if(wsk == i) wsk = (wsk + 1) % n;
	    while(odl(w[i], w[wsk]) < odl(w[i], w[(wsk+1)%n]))
	    
		//while(pole3(w[i], w[(i+1)%n], w[wsk]) < pole3(w[i], w[(i+1)%n], w[(wsk+1)%n]))
			wsk = (wsk + 1) % n;
		rozwaz(w[i], w[wsk]);
		rozwaz(w[(i+1)%n], w[wsk]);
	}
	return res;
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n;
	scanf("%d", &n);
	vector<P> w(n);
	REP(i, n) w[i].wczytaj();
	sort(w.begin(), w.end(), [](const P & a, const P & b)
		{ return a.x < b.x || (a.x == b.x && a.y < b.y); });
	ll low = 1, high = 1e9;
	while(low < high) {
		ll med = (low + high + 1) / 2;
		bool ok = false;
		for(P A : w) {
			vector<P> dobre;
			for(P & B : w) if(odl(A,B) >= med)
				dobre.pb(B);
			if(najdalsze(dobre) >= med) {
				ok = true;
				break;
			}
		}
		if(ok) low = med;
		else high = med - 1;
	}
	printf("%.9lf\n", double(sqrtl((ld)low) / 2.L));
		
	
	return 0;
}