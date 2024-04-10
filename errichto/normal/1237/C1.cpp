#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
using ll = long long;

struct P {
	int x, y, z;
	int id;
	bool operator <(const P& he) const {
		return vector<int>{x, y, z} < vector<int>{
				he.x, he.y, he.z};
	}
	bool same(const P& he) const {
		return make_pair(x, y) == make_pair(he.x, he.y);
	}
	bool same2(const P& he) const {
		return x == he.x;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	vector<P> points(n);
	for(int i = 0; i < n; ++i) {
		P& p = points[i];
		p.id = i + 1;
		scanf("%d%d%d", &p.x, &p.y, &p.z);
	}
	sort(points.begin(), points.end());
	vector<P> remaining;
	for(P p : points) {
		if(!remaining.empty() && remaining.back().same(p)) {
			printf("%d %d\n", p.id, remaining.back().id);
			remaining.pop_back();
		}
		else {
			remaining.push_back(p);
		}
	}
	points = remaining;
	remaining.clear();
	for(P p : points) {
		if(!remaining.empty() && remaining.back().same2(p)) {
			printf("%d %d\n", p.id, remaining.back().id);
			remaining.pop_back();
		}
		else {
			remaining.push_back(p);
		}
	}
	for(int i = 0; i < (int) remaining.size(); i += 2) {
		P a = remaining[i];
		P b = remaining[i+1];
		printf("%d %d\n", a.id, b.id);
	}
}