#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
//#define rf(x) (x)=0;while(*p<48)im=*p=='-';while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);if(im)(x)=-(x);
#define pb push_back
#define eb emplace_back
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define sorv(V) sort(allv(V))
#define revv(V) reverse(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define clv(V) (V).clear()
#define upmin(a,b) (a)=min((a),(b))
#define upmax(a,b) (a)=max((a),(b))
#define rb(x) ((x)&(-(x)))
#define cb(x) (x)=(!(x))
#define INF (0x3f3f3f3f)
#define INFLL (0x3f3f3f3f3f3f3f3fll)
#define INFST (0x7f7f7f7f)
#define INFLLST (0x7f7f7f7f7f7f7f7fll)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
typedef complex<ld> base;
const ld EPS = (ld)1e-9;
const ld PI = acos(0) * 2;
bool isZero(const ld& x) { return abs(x) <= EPS; }
int sign(const ld& x) { return isZero(x) ? 0 : (0 < x ? 1 : -1); }
ll gcd(ll a, ll b) { for(;b;a%=b,swap(a,b)){} return abs(a); }
pll operator + (const pll& a, const pll& b) { return pll(a.first+b.first, a.second+b.second); }
pll operator - (const pll& a, const pll& b) { return pll(a.first-b.first, a.second-b.second); }
pll operator * (const pll& a, const ll& b) { return pll(a.first*b, a.second*b); }
ll operator * (const pll& a, const pll& b) { return a.first*b.second - b.first*a.second; }
ll ccw(const pll& a, const pll& b, const pll& c) { return a*b + b*c + c*a; }
void fg(vector<int> G[], int a, int b) { G[a].pb(b); G[b].pb(a); }
void fg(vector<pii> G[], int a, int b, int c) { G[a].pb({b, c}); G[b].pb({a, c}); }

const int MAXN = 100005;
const int MAXM = 100005;
const int MAXK = 100005;

struct EVT {
	EVT(int type, int x, int y, int z)
		: type(type), x(x), y(y), z(z) {}
	int type, x, y, z;

	bool operator < (const EVT &t) const {
		if(z != t.z) return z > t.z;
		return type < t.type;
	}
};

struct NOD {
	NOD(int sx, int sy, int sz, int ex, int ey, int ez)
		: sx(sx), sy(sy), sz(sz), ex(ex), ey(ey), ez(ez) {}
	int sx, sy, sz;
	int ex, ey, ez;
};

vector<NOD> BV;

int AX[MAXN], AY[MAXN], AZ[MAXN];
int BX[MAXM], BY[MAXM], BZ[MAXM];
int CX[MAXK], CY[MAXK], CZ[MAXK];

int Ans[MAXK];

int bfmnx, bfmxx, bfmny, bfmxy, bfmnz, bfmxz;
int amxx, amxy, amxz, amnx, amny, amnz;

int MX, MY, MZ;
int N, M, K;

void process(vector<EVT> &EV) {
	sorv(EV);
	set<pii> CH;

	CH.insert(pii(0, INF));
	CH.insert(pii(INF, 0));
	for(auto &ev : EV) {
		int x = ev.x, y = ev.y;
		if(ev.type < 0) {
			{
				auto it = CH.lower_bound(pii(x, -INF));
				if(y <= it->second) continue;
			}

			vector<pii> V; bool flag = false;
			for(auto it = CH.lower_bound(pii(x, INF)); CH.begin() != it;) {
				if(!flag) { V.eb(*it); flag = true; }
				it--;
				V.eb(*it);
				if(y < it->second) break;
			}

			for(int i = 1; i+1 < int(V.size()); i++)
				CH.erase(V[i]);

			CH.insert(pii(x, y));
		} else {
			auto it = CH.lower_bound(pii(x, -INF));
			if(y <= it->second) {
				Ans[ev.type] = 2;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	cin >> MX >> MY >> MZ >> N >> M >> K;
	amxx = amxy = amxz = -1;
	amnx = amny = amnz = INF;
	for(int i = 1; i <= N; i++) {
		cin >> AX[i] >> AY[i] >> AZ[i];
		upmax(amxx, AX[i]); upmin(amnx, AX[i]);
		upmax(amxy, AY[i]); upmin(amny, AY[i]);
		upmax(amxz, AZ[i]); upmin(amnz, AZ[i]);
	}
	bfmxx = bfmxy = bfmxz = INF;
	for(int i = 1; i <= M; i++) {
		cin >> BX[i] >> BY[i] >> BZ[i];
		int tx = BX[i] < amnx ? 0 : (BX[i] <= amxx ? 1 : 2);
		int ty = BY[i] < amny ? 0 : (BY[i] <= amxy ? 1 : 2);
		int tz = BZ[i] < amnz ? 0 : (BZ[i] <= amxz ? 1 : 2);

		if(1 == tx && 1 == ty && 1 == tz) {
			puts("INCORRECT");
			return 0;
		}

		if(!tx && 1 == ty && 1 == tz) {
			upmax(bfmnx, BX[i]);
		} else if(2 == tx && 1 == ty && 1 == tz) {
			upmin(bfmxx, BX[i]);
		} else if(!ty && 1 == tx && 1 == tz) {
			upmax(bfmny, BY[i]);
		} else if(2 == ty && 1 == tx && 1 == tz) {
			upmin(bfmxy, BY[i]);
		} else if(!tz && 1 == tx && 1 == ty) {
			upmax(bfmnz, BZ[i]);
		} else if(2 == tz && 1 == tx && 1 == ty) {
			upmin(bfmxz, BZ[i]);
		} else if(!tx && !ty && !tz) {
			BV.eb(1, 1, 1, BX[i], BY[i], BZ[i]);
		} else if(2 == tx && !ty && !tz) {
			BV.eb(BX[i], 1, 1, MX, BY[i], BZ[i]);
		} else if(!tx && 2 == ty && !tz) {
			BV.eb(1, BY[i], 1, BX[i], MY, BZ[i]);
		} else if(!tx && !ty && 2 == tz) {
			BV.eb(1, 1, BZ[i], BX[i], BY[i], MZ);
		} else if(2 == tx && 2 == ty && !tz) {
			BV.eb(BX[i], BY[i], 1, MX, MY, BZ[i]);
		} else if(2 == tx && !ty && 2 == tz) {
			BV.eb(BX[i], 1, BZ[i], MX, BY[i], MZ);
		} else if(!tx && 2 == ty && 2 == tz) {
			BV.eb(1, BY[i], BZ[i], BX[i], MY, MZ);
		} else if(2 == tx && 2 == ty && 2 == tz) {
			BV.eb(BX[i], BY[i], BZ[i], MX, MY, MZ);
		} else if(1 == tx && !ty && !tz) {
			BV.eb(1, 1, 1, MX, BY[i], BZ[i]);
		} else if(1 == tx && 2 == ty && !tz) {
			BV.eb(1, BY[i], 1, MX, MY, BZ[i]);
		} else if(1 == tx && !ty && 2 == tz) {
			BV.eb(1, 1, BZ[i], MX, BY[i], MZ);
		} else if(1 == tx && 2 == ty && 2 == tz) {
			BV.eb(1, BY[i], BZ[i], MX, MY, MZ);
		} else if(!tx && 1 == ty && !tz) {
			BV.eb(1, 1, 1, BX[i], MY, BZ[i]);
		} else if(2 == tx && 1 == ty && !tz) {
			BV.eb(BX[i], 1, 1, MX, MY, BZ[i]);
		} else if(!tx && 1 == ty && 2 == tz) {
			BV.eb(1, 1, BZ[i], BX[i], MY, MZ);
		} else if(2 == tx && 1 == ty && 2 == tz) {
			BV.eb(BX[i], 1, BZ[i], MX, MY, MZ);
		} else if(!tx && !ty && 1 == tz) {
			BV.eb(1, 1, 1, BX[i], BY[i], MZ);
		} else if(2 == tx && !ty && 1 == tz) {
			BV.eb(BX[i], 1, 1, MX, BY[i], MZ);
		} else if(!tx && 2 == ty && 1 == tz) {
			BV.eb(1, BY[i], 1, BX[i], MY, MZ);
		} else if(2 == tx && 2 == ty && 1 == tz) {
			BV.eb(BX[i], BY[i], 1, MX, MY, MZ);
		}
	}
	for(int i = 1; i <= K; i++) {
		cin >> CX[i] >> CY[i] >> CZ[i];
		if(CX[i] < amnx || amxx < CX[i]) continue;
		if(CY[i] < amny || amxy < CY[i]) continue;
		if(CZ[i] < amnz || amxz < CZ[i]) continue;
		Ans[i] = 1;
	}
	for(int i = 1; i <= K; i++) if(!Ans[i]) {
		if(CX[i] <= bfmnx) Ans[i] = 2;
		else if(bfmxx <= CX[i]) Ans[i] = 2;
		else if(CY[i] <= bfmny) Ans[i] = 2;
		else if(bfmxy <= CY[i]) Ans[i] = 2;
		else if(CZ[i] <= bfmnz) Ans[i] = 2;
		else if(bfmxz <= CZ[i]) Ans[i] = 2;
	}

	{
		vector<EVT> EV;
		for(int i = 1; i <= K; i++) if(!Ans[i])
			EV.eb(i, CX[i], CY[i], CZ[i]);
		for(auto &v : BV) {
			if(1 != v.sx || 1 != v.sy || 1 != v.sz) continue;
			EV.eb(-1, v.ex, v.ey, v.ez);
		}
		process(EV);
	}
	{
		vector<EVT> EV;
		for(int i = 1; i <= K; i++) if(!Ans[i])
			EV.eb(i, MX+1-CX[i], CY[i], CZ[i]);
		for(auto &v : BV) {
			if(MX != v.ex || 1 != v.sy || 1 != v.sz) continue;
			EV.eb(-1, MX+1-v.sx, v.ey, v.ez);
		}
		process(EV);
	}
	{
		vector<EVT> EV;
		for(int i = 1; i <= K; i++) if(!Ans[i])
			EV.eb(i, CX[i], MY+1-CY[i], CZ[i]);
		for(auto &v : BV) {
			if(1 != v.sx || MY != v.ey || 1 != v.sz) continue;
			EV.eb(-1, v.ex, MY+1-v.sy, v.ez);
		}
		process(EV);
	}
	{
		vector<EVT> EV;
		for(int i = 1; i <= K; i++) if(!Ans[i])
			EV.eb(i, CX[i], CY[i], MZ+1-CZ[i]);
		for(auto &v : BV) {
			if(1 != v.sx || 1 != v.sy || MZ != v.ez) continue;
			EV.eb(-1, v.ex, v.ey, MZ+1-v.sz);
		}
		process(EV);
	}
	{
		vector<EVT> EV;
		for(int i = 1; i <= K; i++) if(!Ans[i])
			EV.eb(i, MX+1-CX[i], MY+1-CY[i], CZ[i]);
		for(auto &v : BV) {
			if(MX != v.ex || MY != v.ey || 1 != v.sz) continue;
			EV.eb(-1, MX+1-v.sx, MY+1-v.sy, v.ez);
		}
		process(EV);
	}
	{
		vector<EVT> EV;
		for(int i = 1; i <= K; i++) if(!Ans[i])
			EV.eb(i, MX+1-CX[i], CY[i], MZ+1-CZ[i]);
		for(auto &v : BV) {
			if(MX != v.ex || 1 != v.sy || MZ != v.ez) continue;
			EV.eb(-1, MX+1-v.sx, v.ey, MZ+1-v.sz);
		}
		process(EV);
	}
	{
		vector<EVT> EV;
		for(int i = 1; i <= K; i++) if(!Ans[i])
			EV.eb(i, CX[i], MY+1-CY[i], MZ+1-CZ[i]);
		for(auto &v : BV) {
			if(1 != v.sx || MY != v.ey || MZ != v.ez) continue;
			EV.eb(-1, v.ex, MY+1-v.sy, MZ+1-v.sz);
		}
		process(EV);
	}
	{
		vector<EVT> EV;
		for(int i = 1; i <= K; i++) if(!Ans[i])
			EV.eb(i, MX+1-CX[i], MY+1-CY[i], MZ+1-CZ[i]);
		for(auto &v : BV) {
			if(MX != v.ex || MY != v.ey || MZ != v.ez) continue;
			EV.eb(-1, MX+1-v.sx, MY+1-v.sy, MZ+1-v.sz);
		}
		process(EV);
	}

	puts("CORRECT");
	for(int i = 1; i <= K; i++) {
		if(!Ans[i]) puts("UNKNOWN");
		else if(1 == Ans[i]) puts("OPEN");
		else puts("CLOSED");
	}
	return 0;
}