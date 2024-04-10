#ifdef DEBUG
	#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <cassert>

using namespace std;

class DSU {
private:
	int n;
	vector<int> p;
	vector<int> sz;
	vector<int64_t> tsz;
public:
	inline int sizeAt(int v) {
		return sz[parent(v)];
	}
	
	inline int64_t &totalSizeAt(int v) {
		return tsz[parent(v)];
	}
	
	inline int parent(int v) {
		return (p[v] < 0) ? v : (p[v] = parent(p[v]));
	}
	
	inline bool unite(int a, int b) {
		a = parent(a); b = parent(b);
		if (a == b) {
			return false;
		}
		if (sz[a] < sz[b]) {
			swap(a, b);
		}
		p[b] = a;
		sz[a] += sz[b];
		tsz[a] += tsz[b];
		return true;
	}
	
	DSU(int n)
		: n(n), p(n, -1), sz(n, 1), tsz(n) {
	}
};

struct Segment {
	int x1, y1, x2, y2, len;
};

const int TYPE_OPEN = -1;
const int TYPE_CROSS = 0;
const int TYPE_CLOSE = +1;

struct Event {
	int time, type, a, b, idx;
};

inline bool operator<(const Event &a, const Event &b) {
	return make_pair(a.time, a.type) < make_pair(b.time, b.type);
}

struct UnitedLines {
	int l, r, idx;
};

inline bool operator<(const UnitedLines &a, const UnitedLines &b) {
	return a.r < b.r;
}

class Fenwick {
private:
	int n;
	vector<int> a;
public:
	inline void modify(int v, int delta) {
		for (; v < n; v |= v+1) {
			a[v] += delta;
		}
	}
	
	inline int sum(int v) {
		int res = 0;
		for (; v >= 0; v &= v+1, v--) {
			res += a[v];
		}
		return res;
	}
	
	Fenwick(int n)
		: n(n), a(n) {
	}
};

int main() {
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	
	int n; cin >> n;
	vector<Segment> horz, vert;
	map<int, int> kx, ky;
	
	for (int i = 0; i < n; i++) {
		Segment s; cin >> s.x1 >> s.y1 >> s.x2 >> s.y2;
		kx[s.x1] = kx[s.x2] = ky[s.y1] = ky[s.y2] = 42;
		s.len = abs(s.x1-s.x2) + abs(s.y1-s.y2);
		(s.x1 == s.x2 ? horz : vert).push_back(s);
	}
	
	int kxc = 0, kyc = 0;
	for (auto &it: kx) {
		it.second = kxc++;
	}
	for (auto &it: ky) {
		it.second = kyc++;
	}
	
	auto kompressSegment = [&](Segment &s) {
		s.x1 = kx[s.x1]; s.x2 = kx[s.x2];
		s.y1 = ky[s.y1]; s.y2 = ky[s.y2];
	};
	
	vector<Event> evt;
	int sid = 0;
	DSU d(n);
	for (Segment &s: horz) {
		kompressSegment(s);
		evt.push_back({s.y1, TYPE_OPEN, s.x1, -1, sid});
		evt.push_back({s.y2, TYPE_CLOSE, s.x1, -1, sid});
		d.totalSizeAt(sid) = s.len;
		sid++;
	}
	for (Segment &s: vert) {
		kompressSegment(s);
		evt.push_back({s.y1, TYPE_CROSS, s.x1, s.x2, sid});
		d.totalSizeAt(sid) = s.len;
		sid++;
	}
	sort(evt.begin(), evt.end());
	
	set<int> aset;
	Fenwick afen(2*n);
	set<UnitedLines> ln;
	
	for (Event e: evt) {
		if (e.type == TYPE_OPEN) {
			auto pLine = ln.lower_bound({0, e.a, 0});
			if (pLine != ln.end() && pLine->l <= e.a) {
				auto lLine = *pLine, rLine = *pLine;
				lLine.r = *prev(aset.lower_bound(e.a));
				rLine.l = *aset.upper_bound(e.a);
				ln.erase(pLine);
				ln.insert(lLine);
				ln.insert(rLine);
			}
			ln.insert(UnitedLines {e.a, e.a, e.idx});
			aset.insert(e.a);
			afen.modify(e.a, +1);
		} else if (e.type == TYPE_CROSS) {
			int l = e.a, r = e.b;
			int uniteTried = afen.sum(r) - afen.sum(l-1);
			int uniteWas = 0;
			if (uniteTried == 0) {
				continue;
			}
			int lb = INT_MAX, rb = INT_MIN;
			auto iter = ln.lower_bound({0, l, 0});
			while (iter != ln.end() && iter->l <= r) {
				lb = min(lb, iter->l);
				rb = max(rb, iter->r);
				uniteWas += d.unite(e.idx, iter->idx);
				auto wasIter = iter;
				iter++;
				ln.erase(wasIter);
			}
			if (lb != INT_MAX) {
				ln.insert({lb, rb, e.idx});
			}
			d.totalSizeAt(e.idx) += uniteWas - uniteTried;
		} else if (e.type == TYPE_CLOSE) {
			UnitedLines pLine = *ln.lower_bound({0, e.a, 0});
			ln.erase(pLine);
			if (pLine.l != pLine.r) {
				if (pLine.l == e.a) {
					pLine.l = *aset.upper_bound(e.a);
				}
				if (pLine.r == e.a) {
					pLine.r = *prev(aset.lower_bound(e.a));
				}
				ln.insert(pLine);
			}
			aset.erase(e.a);
			afen.modify(e.a, -1);
		} else {
			assert(false);
		}
	}
	
	int64_t ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, d.totalSizeAt(i));
	}
	cout << ans << endl;
	return 0;
}