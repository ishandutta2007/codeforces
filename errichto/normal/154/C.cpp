#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<assert.h>
#include<cstdlib>
using namespace std;
#define FOR(i,a,n) for(int i = (a); i <= (n); ++i)
#define FORD(i,a,n) for(int i = (a); i >= (n); --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,(n))
#define pb push_back
#define st first
#define nd second
#define mp make_pair
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9;
const int nax = 2e6 + 5;
const ll mod = (ll) inf * inf + 3;

struct P {
	ll a, b;
	P() {a = b = 0; }
	P(ll x, ll y) {a = x; b = y; }
	P operator + (P c) const { return P((a + c.a) % mod, (b + c.b) % mod); }
	P operator - (P c) const { return P((a - c.a + mod) % mod, (b - c.b + mod) % mod); }
	bool operator == (P c) const { return a == c.a && b == c.b; }
	bool operator < (P c) const { return a < c.a || (a == c.a && b < c.b); }
};

P h[nax];
P L[nax];
pii kr[nax];
int s[nax];

ll r() { return (rand() << 16) ^ rand(); }

#define rand dupa

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	int n, m;
	scanf("%d%d", &n, &m);
	srand(42);
	REP(i, m) {
		scanf("%d%d", &kr[i].st, &kr[i].nd);
		++s[kr[i].st];
		++s[kr[i].nd];
	}
	RI(i, n) {
		h[i].a = ((ll) r() * inf + r() + r() + i) % mod;
		h[i].b = ((ll) r() * r() + r()) % mod;
	}
	REP(i, m) {
		L[kr[i].st] = L[kr[i].st] + h[kr[i].nd];
		L[kr[i].nd] = L[kr[i].nd] + h[kr[i].st];
	}
	ll res = 0;
	REP(i, m) {
		L[kr[i].st] = L[kr[i].st] - h[kr[i].nd];
		L[kr[i].nd] = L[kr[i].nd] - h[kr[i].st];
		if(L[kr[i].st] == L[kr[i].nd]) ++res;
		else if(L[kr[i].st].a == L[kr[i].nd].a || L[kr[i].st].b == L[kr[i].nd].b) assert(false);
		L[kr[i].st] = L[kr[i].st] + h[kr[i].nd];
		L[kr[i].nd] = L[kr[i].nd] + h[kr[i].st];
	}
	vector<pair<P, int> > w;
	RI(i, n) w.pb(mp(L[i], i));
	sort(w.begin(), w.end());
	REP(i, (int) w.size()) {
		int j = i;
		while(j + 1 < (int) w.size() && w[j + 1].st == w[j].st)
			++j;
		if(j + 1 < (int) w.size() && (w[j + 1].st.a == w[j].st.a || w[j+1].st.b == w[j].st.b)) {
			printf("%lld %lld  vs.  %lld %lld\n", w[j].st.a, w[j].st.b, w[j+1].st.a, w[j+1].st.b);
			REP(d, 2) {
				int a = w[j+d].nd;
				printf("%d: ", a);
				REP(k, m) if(kr[k].st == a || kr[k].nd == a) {
					int b = kr[k].st + kr[k].nd - a;
					printf("(h[%d] = %lld, %lld), ", b, h[b].a, h[b].b);
				}
				puts("");
			}
		}
		int d = j - i + 1;
		res += (ll) d * (d - 1) / 2;
		i = j;
	}
	printf("%lld\n", res);
	return 0;
}