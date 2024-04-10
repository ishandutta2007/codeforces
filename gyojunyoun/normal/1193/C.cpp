#include <bits/stdc++.h>
#define eb emplace_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
using namespace std;
typedef long double ld;
typedef pair<ld, ld> pdd;
const ld EPS = 1e-6;
int mod(int a, int m) { return (a%m+m) % m; }
bool isZero(ld x) { return abs(x) < EPS; }
int sgn(ld x) { return isZero(x) ? 0 : x < 0 ? -1 : 1; }
ld pw(ld x) { return x*x; }
ld normpw(pdd v) { return pw(v.first) + pw(v.second); }
ld norm(pdd v) { return sqrt(normpw(v)); }
bool operator == (pdd a, pdd b) { return isZero(a.first-b.first) && isZero(a.second-b.second); }
bool operator != (pdd a, pdd b) { return !isZero(a.first-b.first) || !isZero(a.second-b.second); }
pdd operator + (pdd a, pdd b) { return {a.first+b.first, a.second+b.second}; }
pdd operator - (pdd a, pdd b) { return {a.first-b.first, a.second-b.second}; }
pdd operator * (pdd a, ld b) { return {a.first*b, a.second*b}; }
pdd operator * (ld a, pdd b) { return {b.first*a, b.second*a}; }
ld operator / (pdd a, pdd b) { return a.first*b.first + a.second*b.second; }
ld operator * (pdd a, pdd b) { return a.first*b.second - b.first*a.second; }
ld ccw(pdd a, pdd b, pdd c) { return a*b + b*c + c*a; }

bool isBet(ld a, ld b, ld c) {
	return (a <= b && b <= c) || (a >= b && b >= c);
}
bool isBet(pdd a, pdd b, pdd c) {
	return isBet(a.first, b.first, c.first) && isBet(a.second, b.second, c.second);
}
bool isCross(pdd a, pdd b, pdd c, pdd d) {
	return sgn(ccw(a, b, c)) * sgn(ccw(a, b, d)) < 0
		&& sgn(ccw(c, d, a)) * sgn(ccw(c, d, b)) < 0;
}
ld getAngle(pdd a, pdd b, pdd c) {
	pdd u = a-b, v = c-b;
	return atan2(-(u*v), u/v);
}
pdd getSec(pdd x1, pdd d1, pdd x2, pdd d2) {
	return ((x1-x2)*d1 / (d2*d1)) * d2 + x2;
}
pdd proj(pdd d, pdd v) {
	return d/v / normpw(d) * d;
}
pdd perp(pdd x, pdd d, pdd p) {
	return x + proj(d, p-x);
}

struct POLY {
	vector<pdd> V;
	int idx;
	int size() const { return sz(V); }
	pdd& operator [] (const int i) { return V[mod(i, sz(V))]; }
	void emplace_back(ld x, ld y) { V.eb(x, y); }
	void emplace_back(pdd v) { V.eb(v); }
	ld getArea() const {
		ld ret = 0;
		for(int i = 0, n = sz(V); i < n; i++)
			ret += V[i] * V[(i+1)%n];
		return abs(ret) / 2;
	}
	void prt() const {
		printf("%d", sz(V));
		for(auto &v : V) printf(" %.20lf %.20lf", double(v.first), double(v.second));
		puts("");
	}
};

bool isCross(POLY &poly, pdd a, pdd b) {
	int n = sz(poly);
	for(int i = 0; i < n; i++) {
		if(isCross(a, b, poly[i], poly[(i+1)%n])) return true;
		if(a != poly[i] && b != poly[i] && !sgn(ccw(a, b, poly[i]))
			&& isBet(a, poly[i], b)) return true;
	}
	return false;
}

struct INFO {
	vector<POLY> PV;
	vector<pair<int, vector<POLY>>> EV;
	int cnt;

	void prt() {
		for(auto &ev : EV) {
			auto &V = ev.second;
			int n = sz(V)-1;
			if(!ev.first) {
				puts("scissors");
				printf("%d %d\n", V[0].idx, n);
				for(int i = 1; i <= n; i++) V[i].prt();
			} else {
				puts("tape");
				printf("%d", n);
				for(int i = 0; i < n; i++) printf(" %d", V[i].idx);
				puts("");
				for(int i = 0; i < n; i++) V[i].prt();
				V.back().prt();
			}
		}
	}
};

void mergeInfo(INFO &startInfo, INFO &endInfo) {
	vector<int> IMP(sz(endInfo.PV), -1);
	IMP[endInfo.PV.back().idx] = startInfo.PV.back().idx;
	for(int evi = sz(endInfo.EV); evi--;) {
		auto PV = endInfo.EV[evi].second;
		if(!endInfo.EV[evi].first) {
			POLY finalPoly = PV[0];
			PV.erase(PV.begin());
			int fidx = startInfo.cnt++;
			IMP[finalPoly.idx] = fidx;
			finalPoly.idx = fidx;
			startInfo.PV.eb(finalPoly);
			for(auto &poly : PV) poly.idx = IMP[poly.idx];
			PV.eb(finalPoly);
			startInfo.EV.eb(1, PV);
		} else {
			POLY initPoly = PV.back();
			PV.pop_back();
			vector<POLY> _PV;
			for(auto &poly : PV) {
				int pidx = startInfo.cnt++;
				IMP[poly.idx] = pidx;
				POLY _poly = poly;
				_poly.idx = pidx;
				startInfo.PV.eb(_poly);
				_PV.eb(_poly);
			}
			POLY _initPoly = initPoly;
			_initPoly.idx = IMP[initPoly.idx];
			_PV.insert(_PV.begin(), _initPoly);
			startInfo.EV.eb(0, _PV);
			for(auto &poly : PV) {
				POLY _poly = poly;
				_poly.idx = IMP[poly.idx];
				POLY _oriPoly = endInfo.PV[poly.idx];
				int pidx = startInfo.cnt++;
				_oriPoly.idx = pidx;
				_poly.V = _oriPoly.V;
				startInfo.PV.eb(_oriPoly);
				startInfo.EV.eb(1, vector<POLY>({_poly, _oriPoly}));
				IMP[poly.idx] = pidx;
			}
		}
	}
}

void triangulation(INFO &info, POLY poly, vector<POLY> &V) {
	int n = sz(poly);
	if(3 == n) {
		V.eb(poly);
		return;
	}
	POLY _poly = poly;
	for(; 3 < n;) {
		int i = 0;
		for(; ccw(poly[i-1], poly[i], poly[i+1]) <= 0
			|| isCross(poly, poly[i-1], poly[i+1])
			|| (ccw(poly[i-1], poly[i+1], poly[i-2]) < 0 && ccw(poly[i-1], poly[i], poly[i-2]) > 0); i++);
		POLY tri; tri.idx = info.cnt++;
		tri.eb(poly[i-1]); tri.eb(poly[i]); tri.eb(poly[i+1]);
		V.eb(tri); info.PV.eb(tri);
		poly.V.erase(poly.V.begin() + i);
		n--;
	}
	poly.idx = info.cnt++;
	V.eb(poly);
	info.PV.eb(poly);

	vector<POLY> PV;
	PV.eb(_poly);
	for(auto &v : V) PV.eb(v);
	info.EV.eb(0, PV);
}

void triToRect(INFO &info, POLY tri, POLY &rect) {
	vector<ld> AV;
	for(int i = 0; i < 3; i++)
		AV.eb(getAngle(tri[i-1], tri[i], tri[i+1]));
	int i = int(max_element(allv(AV)) - AV.begin());
	pdd m1 = (tri[i] + tri[i+1]) * 0.5, m2 = (tri[i] + tri[i-1]) * 0.5;
	pdd p = perp(m1, m2-m1, tri[i]);

	POLY poly1, poly2, poly3;
	poly1.idx = info.cnt++;
	poly1.eb(tri[i]); poly1.eb(m1); poly1.eb(p);
	info.PV.eb(poly1);
	poly2.idx = info.cnt++;
	poly2.eb(tri[i]); poly2.eb(p); poly2.eb(m2);
	info.PV.eb(poly2);
	poly3.idx = info.cnt++;
	poly3.eb(tri[i+1]); poly3.eb(tri[i-1]); poly3.eb(m2); poly3.eb(m1);
	info.PV.eb(poly3);

	info.EV.eb(0, vector<POLY>({tri, poly1, poly2, poly3}));

	ld w = norm(tri[i-1] - tri[i+1]), h = norm(tri[i] - p);
	poly1[0] = {0, 0}; poly1[1] = {norm(p-m1), h}; poly1[2] = {0, h};
	poly2[0] = {w, 0}; poly2[1] = {w, h}; poly2[2] = {w-norm(p-m2), h};
	poly3[0] = {0, 0}; poly3[1] = {w, 0};
	poly3[2] = {w-norm(p-m2), h}; poly3[3] = {norm(p-m1), h};
	rect.idx = info.cnt++;
	rect.eb(0, 0); rect.eb(w, 0); rect.eb(w, h); rect.eb(0, h);
	info.PV.eb(rect);

	info.EV.eb(1, vector<POLY>({poly1, poly2, poly3, rect}));
}

void rectToRatioTwo(INFO &info, POLY &rect) {
	ld h, w; tie(w, h) = rect[2];
	for(;;) {
		if(h*2 < w) {
			POLY poly1, poly2;
			poly1.idx = info.cnt++;
			poly1.eb(0, 0); poly1.eb(w/2, 0); poly1.eb(w/2, h); poly1.eb(0, h);
			poly2.idx = info.cnt++;
			poly2.eb(w/2, 0); poly2.eb(w, 0); poly2.eb(w, h); poly2.eb(w/2, h);
			info.PV.eb(poly1); info.PV.eb(poly2);

			info.EV.eb(0, vector<POLY>({rect, poly1, poly2}));

			poly2[0] = {0, h}; poly2[1] = {w/2, h};
			poly2[2] = {w/2, h*2}; poly2[3] = {0, h*2};
			rect.idx = info.cnt++;
			rect[1] = {w/2, 0}; rect[2] = {w/2, h*2}; rect[3] = {0, h*2};
			info.PV.eb(rect);

			info.EV.eb(1, vector<POLY>({poly1, poly2, rect}));

			w /= 2; h *= 2;
		} else if(w*2 < h) {
			POLY poly1, poly2;
			poly1.idx = info.cnt++;
			poly1.eb(0, 0); poly1.eb(w, 0); poly1.eb(w, h/2); poly1.eb(0, h/2);
			poly2.idx = info.cnt++;
			poly2.eb(0, h/2); poly2.eb(w, h/2); poly2.eb(w, h); poly2.eb(0, h);
			info.PV.eb(poly1); info.PV.eb(poly2);

			info.EV.eb(0, vector<POLY>({rect, poly1, poly2}));

			poly2[0] = {w, 0}; poly2[1] = {w*2, 0};
			poly2[2] = {w*2, h/2}; poly2[3] = {w, h/2};
			rect.idx = info.cnt++;
			rect[1] = {w*2, 0}; rect[2] = {w*2, h/2}; rect[3] = {0, h/2};
			info.PV.eb(rect);

			info.EV.eb(1, vector<POLY>({poly1, poly2, rect}));

			w *= 2; h /= 2;
		} else break;
	}
}

void ratioTwoToSquare(INFO &info, POLY &rect) {
	ld h, w; tie(w, h) = rect[2];
	ld l = sqrt(w*h);
	if(isZero(w-h)) return;
	if(h <= w) {
		ld x = l-h, y = sqrt(w/h)*x;
		POLY poly1, poly2, poly3;
		poly1.idx = info.cnt++;
		poly1.eb(w-y, 0); poly1.eb(w, 0); poly1.eb(w-y, x);
		poly2.idx = info.cnt++;
		poly2.eb(w, 0); poly2.eb(w, h); poly2.eb(w-l, h);
		poly3.idx = info.cnt++;
		poly3.eb(0, 0); poly3.eb(w-y, 0);
		poly3.eb(w-y, x); poly3.eb(w-l, h); poly3.eb(0, h);
		info.PV.eb(poly1); info.PV.eb(poly2); info.PV.eb(poly3);

		info.EV.eb(0, vector<POLY>({rect, poly1, poly2, poly3}));

		poly1[0] = {0, l-x}; poly1[1] = {y, l-x}; poly1[2] = {0, l};
		poly2[0] = {l, x}; poly2[1] = {l, l}; poly2[2] = {0, l};
		rect.idx = info.cnt++;
		rect[1] = {l, 0}; rect[2] = {l, l}; rect[3] = {0, l};
		info.PV.eb(rect);

		info.EV.eb(1, vector<POLY>({poly1, poly2, poly3, rect}));
	} else {
		ld x = h-l, y = l-w;
		POLY poly1, poly2, poly3;
		poly1.idx = info.cnt++;
		poly1.eb(0, h-x); poly1.eb(y, h-x); poly1.eb(0, h);
		poly2.idx = info.cnt++;
		poly2.eb(w, x); poly2.eb(w, h); poly2.eb(0, h);
		poly3.idx = info.cnt++;
		poly3.eb(0, 0); poly3.eb(w, 0);
		poly3.eb(w, x); poly3.eb(y, h-x); poly3.eb(0, h-x);
		info.PV.eb(poly1); info.PV.eb(poly2); info.PV.eb(poly3);

		info.EV.eb(0, vector<POLY>({rect, poly1, poly2, poly3}));

		poly1[0] = {l-y, 0}; poly1[1] = {l, 0}; poly1[2] = {l-y, x};
		poly2[0] = {l, 0}; poly2[1] = {l, l}; poly2[2] = {l-w, l};
		rect.idx = info.cnt++;
		rect[1] = {l, 0}; rect[2] = {l, l}; rect[3] = {0, l};
		info.PV.eb(rect);

		info.EV.eb(1, vector<POLY>({poly1, poly2, poly3, rect}));
	}
}

void squareToFixedH(INFO &info, POLY &rect, ld t) {
	ld l = rect[1].first;
	ld h = t, w = l*l / t;
	int runcnt1 = 0, runcnt2 = 0;

	for(;;) {
		if(h*2 < w) {
			h *= 2; w /= 2;
			runcnt1++;
		} else if(w*2 < h) {
			w *= 2; h /= 2;
			runcnt2++;
		} else break;
	}

	if(h <= w) {
		ld x = l-h, y = sqrt(w/h)*x;
		POLY poly1, poly2, poly3;
		if(!isZero(l-h)) {
			poly1.idx = info.cnt++;
			poly1.eb(0, l-x); poly1.eb(y, l-x); poly1.eb(0, l);
			poly2.idx = info.cnt++;
			poly2.eb(l, x); poly2.eb(l, l); poly2.eb(0, l);
			poly3.idx = info.cnt++;
			poly3.eb(0, 0); poly3.eb(w-y, 0);
			poly3.eb(w-y, x); poly3.eb(w-l, h); poly3.eb(0, h);
			info.PV.eb(poly1); info.PV.eb(poly2); info.PV.eb(poly3);

			info.EV.eb(0, vector<POLY>({rect, poly1, poly2, poly3}));

			poly1[0] = {w-y, 0}; poly1[1] = {w, 0}; poly1[2] = {w-y, x};
			poly2[0] = {w, 0}; poly2[1] = {w, h}; poly2[2] = {w-l, h};
			rect.idx = info.cnt++;
			rect[1] = {w, 0}; rect[2] = {w, h}; rect[3] = {0, h};
			info.PV.eb(rect);

			info.EV.eb(1, vector<POLY>({poly1, poly2, poly3, rect}));
		}
	} else {
		ld x = h-l, y = l-w;
		POLY poly1, poly2, poly3;
		if(!isZero(l-h)) {
			poly1.idx = info.cnt++;
			poly1.eb(l-y, 0); poly1.eb(l, 0); poly1.eb(l-y, x);
			poly2.idx = info.cnt++;
			poly2.eb(l, 0); poly2.eb(l, l); poly2.eb(l-w, l);
			poly3.idx = info.cnt++;
			poly3.eb(0, 0); poly3.eb(w, 0);
			poly3.eb(w, x); poly3.eb(y, h-x); poly3.eb(0, h-x);
			info.PV.eb(poly1); info.PV.eb(poly2); info.PV.eb(poly3);

			info.EV.eb(0, vector<POLY>({rect, poly1, poly2, poly3}));

			poly1[0] = {0, h-x}; poly1[1] = {y, h-x}; poly1[2] = {0, h};
			poly2[0] = {w, x}; poly2[1] = {w, h}; poly2[2] = {0, h};
			rect.idx = info.cnt++;
			rect[1] = {w, 0}; rect[2] = {w, h}; rect[3] = {0, h};
			info.PV.eb(rect);

			info.EV.eb(1, vector<POLY>({poly1, poly2, poly3, rect}));
		}
	}

	{
		POLY poly1, poly2;
		poly1.V.resize(4); poly2.V.resize(4);
		for(; runcnt1--;) {
			poly1.idx = info.cnt++;
			poly1[0] = {0, 0}; poly1[1] = {w, 0};
			poly1[2] = {w, h/2}; poly1[3] = {0, h/2};
			poly2.idx = info.cnt++;
			poly2[0] = {0, h/2}; poly2[1] = {w, h/2};
			poly2[2] = {w, h}; poly2[3] = {0, h};
			info.PV.eb(poly1); info.PV.eb(poly2);
			
			info.EV.eb(0, vector<POLY>({rect, poly1, poly2}));

			poly2[0] = {w, 0}; poly2[1] = {w*2, 0};
			poly2[2] = {w*2, h/2}; poly2[3] = {w, h/2};
			rect.idx = info.cnt++;
			rect[1] = {w*2, 0}; rect[2] = {w*2, h/2}; rect[3] = {0, h/2};
			info.PV.eb(rect);

			info.EV.eb(1, vector<POLY>({poly1, poly2, rect}));

			h /= 2; w *= 2;
		}
		for(; runcnt2--;) {
			poly1.idx = info.cnt++;
			poly1[0] = {0, 0}; poly1[1] = {w/2, 0};
			poly1[2] = {w/2, h}; poly1[3] = {0, h};
			poly2.idx = info.cnt++;
			poly2[0] = {w/2, 0}; poly2[1] = {w, 0};
			poly2[2] = {w, h}; poly2[3] = {w/2, h};
			info.PV.eb(poly1); info.PV.eb(poly2);

			info.EV.eb(0, vector<POLY>({rect, poly1, poly2}));

			poly2[0] = {0, h}; poly2[1] = {w/2, h};
			poly2[2] = {w/2, h*2}; poly2[3] = {0, h*2};
			rect.idx = info.cnt++;
			rect[1] = {w/2, 0}; rect[2] = {w/2, h*2}; rect[3] = {0, h*2};
			info.PV.eb(rect);

			info.EV.eb(1, vector<POLY>({poly1, poly2, rect}));

			w /= 2; h *= 2;
		}
	}
}

void mergeFixedH(INFO &info, vector<POLY> V, POLY &poly) {
	int n = sz(V);
	ld h = V[0][2].second, wsum = 0;
	for(int i = 0; i < n; i++) {
		auto &rect = V[i];
		ld w = rect[1].first;
		rect[0] = {wsum, 0}; rect[1] = {wsum+w, 0};
		rect[2] = {wsum+w, h}; rect[3] = {wsum, h};
		wsum += w;
	}
	poly.idx = info.cnt++;
	poly.eb(0, 0); poly.eb(wsum, 0); poly.eb(wsum, h); poly.eb(0, h);
	info.PV.eb(poly);

	V.eb(poly);
	info.EV.eb(1, V);
}

void polygonToFixedH(INFO &info, POLY poly, ld h) {
	vector<POLY> triV;
	triangulation(info, poly, triV);

	vector<POLY> rectV;
	for(auto &tri : triV) {
		POLY rect;
		triToRect(info, tri, rect);
		rectToRatioTwo(info, rect);
		ratioTwoToSquare(info, rect);
		squareToFixedH(info, rect, h);
		rectV.eb(rect);
	}
	
	POLY finalPoly;
	mergeFixedH(info, rectV, finalPoly);
}


POLY startPoly, endPoly;

void process() {
	INFO startInfo, endInfo;
	startInfo.cnt = 1;
	startInfo.PV.eb(startPoly);
	endInfo.cnt = 1;
	endInfo.PV.eb(endPoly);
	ld area = startPoly.getArea();
	ld hei = sqrt(area);

	polygonToFixedH(startInfo, startPoly, hei);
	polygonToFixedH(endInfo, endPoly, hei);

	mergeInfo(startInfo, endInfo);
	startInfo.prt();
}

void input() {
	int n;
	startPoly.idx = 0;
	cin >> n;
	for(ld x, y; n--;) {
		cin >> x >> y;
		startPoly.eb(x, y);
	}
	endPoly.idx = 0;
	cin >> n;
	for(ld x, y; n--;) {
		cin >> x >> y;
		endPoly.eb(x, y);
	}
}

int main() {
	input();
	process();
	return 0;
}