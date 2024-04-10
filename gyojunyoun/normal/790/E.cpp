#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)im=*p=='-';while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);if(im)(x)=-(x);
#define pb push_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define sorv(V) sort(allv(V))
#define revv(V) reverse(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define clv(V) (V).clear()
#define upmin(a,b) (a)=min((a),(b))
#define upmax(a,b) (a)=max((a),(b))
#define rb(x) ((x)&(-(x)))
#define INF (0x3f3f3f3f)
#define INFLL (0x3f3f3f3f3f3f3f3fll)
#define MAXN (200005)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ld EPS = (ld)0.5e-6;
bool isZero(const ld& n) { return -EPS < n && n < EPS; }
bool isSame(const ld& a, const ld& b) { return isZero(a-b); }
ld mypow(const ld& n) { return n*n; }
pdd operator + (const pdd& a, const pdd& b) { return (pdd){a.first+b.first, a.second+b.second}; }
pdd operator - (const pdd& a, const pdd& b) { return (pdd){a.first-b.first, a.second-b.second}; }
pdd operator * (const pdd& a, const ld& b) { return (pdd){a.first*b, a.second*b}; }
pdd operator / (const pdd& a, const ld& b) { return (pdd){a.first/b, a.second/b}; }
ld operator * (const pdd& a, const pdd& b) { return a.first*b.second - a.second*b.first; }
ll ccw(const pll& a, const pll& b, const pll& c) {
    return (a.first*b.second + b.first*c.second + c.first*a.second)
         - (a.second*b.first + b.second*c.first + c.second*a.first);
}
ld ccwpdd(const pdd& a, const pdd& b, const pdd& c) {
	return (a.first*b.second + b.first*c.second + c.first*a.second)
		 - (a.second*b.first + b.second*c.first + c.second*a.first);
}
ld getLen(const pdd& v) { return sqrt(mypow(v.first) + mypow(v.second)); }
ld getDist(const pdd& a, const pdd& b) { return getLen(a-b); }
pdd norm(const pdd& v) { return v / getLen(v); }
struct Line {
    Line(const pdd& _r, const pdd& _v) : r(_r), v(_v) {}
    pdd r, v;
    void uni() {
        if((isZero(v.first) && v.second < 0) || v.first < 0) {
            v.first *= (ld)-1; v.second *= (ld)-1;
        }
    }
    void printLineEq() const {
        printf("%Lf(x-(%Lf)) - %Lf(y-(%Lf)) = 0\n", v.second, r.first, v.first, r.second);
    }
};
Line makeLine(const pdd& A, const pdd& B) { Line ret(A, norm(B-A)); ret.uni(); return ret; } 
int intersect(const Line& A, const Line& B, pdd& ret) { // -1 : fk
    const ld down = A.v * B.v; if(isZero(down)) return -1;
    const ld a = (B.r * B.v - A.r * B.v) / down;
    ret = A.r + A.v * a; return 0;
}

vector<Line> Lines, ULines, DLines;
vector<pdd> UPoints, DPoints;
vector<ld> SLines;
vector<pii> VL;
pll P[MAXN*2], PO;

vector<pdd> VCH;
int T, N;

void sortPoints() {
	auto S = [&](const pll& p) { return PO < p; };
	sort(P, P+N, [&](const pll& a, const pll& b) {
		return S(a) != S(b) ? S(a) > S(b) : 0 < ccw(PO, a, b);
	});
}
bool makeHuboLines() {
	bool isCo = false; clv(VL);
	for(int i = 0; i < N; i++) if(0 == ccw(P[i], PO, P[i+1])) { isCo = true; break; }
	for(int i = 0, j = 1; i < N; i++) {
		for(j = max(i+1, j); j+1 < N+i && ccw(P[i], PO, P[j]) < 0; j++);
		if(i == j%N) continue;
		if(0 == ccw(P[i], PO, P[j])) { isCo = true; break; }
		VL.pb({i, j%N});
	}
	for(int i = 0; i < N; i++) VL.pb({i, (i+1)%N});
	for(pii& v : VL) if(v.first > v.second) swap(v.first, v.second);
	sorv(VL); univ(VL);
	return isCo;
}
void makeRealLines(vector<pii>& VL, vector<Line>& Lines, vector<ld>& SLines) {
	clv(Lines); clv(SLines);
	for(pii v : VL) {
		if(isSame(P[v.first].first, P[v.second].first))
			SLines.pb(P[v.first].first);
		else Lines.pb(makeLine(P[v.first], P[v.second]));
    }
    Lines.pb(Line({(ld)0, (ld)+1000000}, {(ld)1, (ld)0}));
    Lines.pb(Line({(ld)0, (ld)-1000000}, {(ld)1, (ld)0}));
    SLines.pb((ld)1000000); SLines.pb((ld)-1000000);
}
void splitUDLines(vector<Line>& Lines, vector<Line>& ULines, vector<Line>& DLines, const ld& X, const ld& Y) {
	clv(ULines); clv(DLines);
	for(Line& l : Lines) {
		if(((pdd){X, Y} - l.r) * l.v <= 0) DLines.pb(l);
		else ULines.pb(l);
	}
	clv(Lines);
}
void makeRealPoints(vector<Line>& VL, vector<pdd>& VP) {
	clv(VP); if(VL.empty()) return;
	for(Line& l : VL)
		VP.pb({l.v.second/l.v.first, l.r.second - l.r.first*l.v.second/l.v.first});
	sort(allv(VP), [&](const pdd& a, const pdd& b) {
		return isSame(a.first, b.first) ? a.second < b.second : a.first < b.first;
	});
	vector<pdd> tmp(1, VP[0]);
	for(int i = 1; i < sz(VP); i++) {
		if(isSame(VP[i-1].first, VP[i].first) && isSame(VP[i-1].second, VP[i].second)) continue;
		tmp.pb(VP[i]);
	}
	swap(VP, tmp);
}
void makeCH(vector<pdd>& VP) {
	if(sz(VP) < 2) return;
	sort(VP.begin()+1, VP.end(), [&](const pdd& a, const pdd& b) {
		const ld dt = ccwpdd(VP[0], a, b);
		return (!isZero(dt)) ? 0 < dt : a < b;
	});
	vector<pdd> V;
	for(pdd& v : VP) {
		while(1 < sz(V) && ccwpdd(befv(V), V.back(), v) <= EPS) V.pop_back();
		V.pb(v);
	}
	swap(VP, V);
}
void getDownCH(vector<pdd>& VP) {
	if(sz(VP) < 2) return;
	const ld mx = (*max_element(allv(VP))).first;
	int idx = -1; for(int i = 0; i < sz(VP); i++)
		if(isSame(VP[i].first, mx)) { idx = i; break; }
	while(idx+1 < sz(VP)) VP.pop_back();
}
void getUpCH(vector<pdd>& VP) {
	if(sz(VP) < 2) return;
	const ld mx = (*max_element(allv(VP))).first;
	int idx = -1; for(int i = sz(VP)-1; ~i; i--)
		if(isSame(VP[i].first, mx)) { idx = i; break; }
	vector<pdd> V; for(int i = idx; i < sz(VP); i++) V.pb(VP[i]);
	if(!isSame(V.back().first, VP[0].first)) V.pb(VP[0]);
	swap(VP, V);
}
bool isIntersectCH(vector<pdd>& VU, vector<pdd>& VD) {
	if(1 == sz(VU) && 1 == sz(VD))
		return isSame(VU[0].first, VD[0].first) && VU[0].second < VD[0].second;
	const ld umn = VU[0].first;
	const ld umx = VU.back().first;
	const ld dmn = VD.back().first;
	const ld dmx = VD[0].first;
	if((umx-umn) + (dmx-dmn) <= max(umx, dmx) - min(umn, dmn)) return false;
	if(1 < sz(VD)) {
		for(int i = 0, j = sz(VD)-2; i < sz(VU); i++) {
			for(; j && VD[j].first < VU[i].first; j--);
			if(VD[j+1].first <= VU[i].first && VU[i].first <= VD[j].first
				&& ccwpdd(VD[j+1], VD[j], VU[i]) < EPS) return true;
		}
	}
	if(1 < sz(VU)) {
		for(int i = 0, j = sz(VU)-2; i < sz(VD); i++) {
			for(; j && VD[i].first < VU[j].first; j--);
			if(VU[j].first <= VD[i].first && VD[i].first <= VU[j+1].first
				&& -EPS < ccwpdd(VU[j], VU[j+1], VD[i])) return true;
		}
	}
	return false;
}
void getCHCommonTangent(vector<pdd>& VU, vector<pdd>& VD, vector<ld>& SLines) {
	auto f = [&](int i, int j) {
		const ld a = ccwpdd(VU[i], VD[j], i ? VU[i-1] : (pdd){VU[0].first, VU[0].second+10});
		const ld b = ccwpdd(VU[i], VD[j], i+1 < sz(VU) ? VU[i+1] : (pdd){VU.back().first, VU.back().second+10});
		const ld c = ccwpdd(VD[j], VU[i], j ? VD[j-1] : (pdd){VD[0].first, VD[0].second-10});
		const ld d = ccwpdd(VD[j], VU[i], j+1 < sz(VD) ? VD[j+1] : (pdd){VD.back().first, VD.back().second-10});
		if((a < -EPS && EPS < b) || (EPS < a && b < -EPS)) return false;
		if((c < -EPS && EPS < d) || (EPS < c && d < -EPS)) return false;
		return true;
	};
	auto g = [&](int i, int j) {
		if(isSame(VU[i].first, VD[j].first)) return;
		SLines.pb((VD[j].second-VU[i].second) / (VU[i].first-VD[j].first));
	};
	for(int i = 0, j = 0; i < sz(VU); i++) {
		for(; j+1 < sz(VD) && -EPS <= ccwpdd(VU[i], VD[j], VD[j+1]); j++);
		if(f(i, j)) { g(i, j); break; }
	}
	for(int i = sz(VU)-1, j = sz(VD)-1; ~i; i--) {
		for(; j && ccwpdd(VU[i], VD[j], VD[j-1]) <= EPS; j--);
		if(f(i, j)) { g(i, j); break; }
	}
}
void restoreLines(vector<Line>& VL, vector<pdd>& VP) {
	auto f = [&](const pdd& P) {
		Line ret({0, P.second}, norm({1, P.first})); ret.uni();
		return ret;
	};
	clv(VL); for(pdd& v : VP) VL.pb(f(v));
}
void makeSLinesSimple(vector<ld>& V, const ld& X) {
	ld l = -INFLL, r = INFLL;
	for(ld& v : V) {
		if(v <= X) upmax(l, v);
		if(X <= v) upmin(r, v);
	}
	clv(V); V.pb(l); V.pb(r);
}
void makeUDLinesSimple(vector<Line>& V, vector<ld>& S, const bool isR = false) {
	if(sz(V) < 2) return;
	if(sz(S) != 2) { puts("ERR! A"); exit(0); }
	if(isR) revv(V);
	int s = 0, e = sz(V)-1;
	for(pdd p; s+1 < sz(V); s++) {
		const int ret = intersect(V[s], V[s+1], p);
		if(-1 != ret && S[0] < p.first) break;
	}
	for(pdd p; e; e--) {
		const int ret = intersect(V[e], V[e-1], p);
		if(-1 != ret && p.first < S[1]) break;
	}
	vector<Line> tmp; for(int i = s; i <= e; i++) tmp.pb(V[i]);
	swap(V, tmp); if(isR) revv(V);
}
void getIntersectCH(vector<pdd>& CH, vector<Line>& VU, vector<Line>& VD, vector<ld>& VS, const ld& X) {
	if(VU.empty()) { puts("ERR! B"); exit(0); }
	if(VD.empty()) { puts("ERR! C"); exit(0); }
	auto f = [&](const Line& l, const ld& X) {
		if(isZero(l.v.first)) return;
		CH.pb({X, l.r.second + l.v.second * (X - l.r.first) / l.v.first});
	};
	auto g = [&](const Line& a, const Line& b) {
		pdd P; const int ret = intersect(a, b, P);
		if(-1 != ret) CH.pb(P);
	};
	auto h = [&]() {
		if(sz(CH) < 2) return;
		if(!isSame(befv(CH).first, CH.back().first)) return;
		if(!isSame(befv(CH).second, CH.back().second)) return;
		CH.pop_back();
	};
	revv(VU);
	{
		pdd P; int ret;
		ret = intersect(VU[0], VD.back(), P);
		if(-1 != ret && P.first <= X) upmax(VS[0], P.first);
		if(-1 != ret && X <= P.first) upmin(VS[1], P.first);
		ret = intersect(VU.back(), VD[0], P);
		if(-1 != ret && P.first <= X) upmax(VS[0], P.first);
		if(-1 != ret && X <= P.first) upmin(VS[1], P.first);
	}
	clv(CH); f(VU[0], VS[0]);
	for(int i = 1; i < sz(VU); i++) { g(VU[i-1], VU[i]); h(); }
	f(VU.back(), VS[1]); h(); f(VD[0], VS[1]); h();
	for(int i = 1; i < sz(VD); i++) { g(VD[i-1], VD[i]); h(); }
	f(VD.back(), VS[0]); h();
	if(1 < sz(CH) && isSame(CH[0].first, CH.back().first) && isSame(CH[0].second, CH.back().second))
		CH.pop_back();
}
ld getArea(vector<pdd>& CH) {
	ld ret = 0;
	for(int i = 0; i < sz(CH); i++) ret += CH[i] * CH[(i+1)%sz(CH)];
	if(ret < 0) ret = -ret;
	return ret / 2;
}
int main() {
	std::ios::sync_with_stdio(false);
	cout << fixed; cout.precision(20);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%lld%lld", &N, &PO.first, &PO.second); N--;
		for(int i = 0; i < N; i++) scanf("%lld%lld", &P[i].first, &P[i].second);
		const ld X = (1000000 == PO.first) ? ((ld)1000000-EPS/2)
					: ((-1000000 == PO.first) ? ((ld)-1000000+EPS/2) : (ld)PO.first);
		const ld Y = (1000000 == PO.second) ? ((ld)1000000-EPS/2)
					: ((-1000000 == PO.second) ? ((ld)-1000000+EPS/2) : (ld)PO.second);
		sortPoints(); for(int i = 0; i < N; i++) P[i+N] = P[i];
		if(makeHuboLines()) { cout << "0\n"; continue; }
		makeRealLines(VL, Lines, SLines);
		splitUDLines(Lines, ULines, DLines, X, Y);
		makeRealPoints(ULines, UPoints); makeRealPoints(DLines, DPoints);
		makeCH(UPoints); makeCH(DPoints); getDownCH(UPoints); getUpCH(DPoints);
		//if(isIntersectCH(UPoints, DPoints)) { puts("0"); continue; }
		if(isIntersectCH(UPoints, DPoints)) { cout << "0\n"; continue; }
		getCHCommonTangent(UPoints, DPoints, SLines);
		restoreLines(ULines, UPoints); restoreLines(DLines, DPoints);
		makeSLinesSimple(SLines, X);
		makeUDLinesSimple(ULines, SLines, true);
		makeUDLinesSimple(DLines, SLines, true);
		getIntersectCH(VCH, ULines, DLines, SLines, X);
		cout << getArea(VCH) << "\n";
	}
	return 0;
}