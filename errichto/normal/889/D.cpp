#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
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

typedef long long ll;
struct P {
	ll x, y;
	void read() {
		scanf("%lld%lld", &x, &y);
	}
	P operator - (const P & he) const {
		return P{x - he.x, y - he.y};
	}
	P operator + (const P & he) const {
		return P{x + he.x, y + he.y};
	}
	P operator * (ll mul) const {
		return P{x * mul, y * mul};
	}
	P operator / (ll mul) const {
		assert(x % mul == 0 && y % mul == 0);
		return P{x / mul, y / mul};
	}
	ll operator *(const P & he) const {
		return x * he.y - y * he.x;
	}
	bool operator == (const P & he) const {
		return x == he.x && y == he.y;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	vector<P> points(n);
	P mid = {0, 0};
	for(P & p : points) {
		p.read();
		p = p * 2;
		mid = mid + p;
		p = p * n;
	}
	debug() << imie(mid.x) imie(mid.y);
	vector<bool> vis(n);
	for(int i = 0; i < (int) points.size(); ++i)
		if(!vis[i]) {
			if(points[i] == mid) {
				vis[i] = true;
				continue;
			}
			for(int j = i + 1; j < (int) points.size(); ++j)
				if(!vis[j] && (points[i] - mid) == (mid - points[j])) {
					vis[i] = vis[j] = true;
					break;
				}
		}
	vector<P> nowe;
	for(int i = 0; i < n; ++i)
		if(!vis[i])
			nowe.push_back(points[i]);
	points = nowe;
	n = points.size();
	debug() << imie(n);
	if(n <= 1) {
		puts("-1");
		return 0;
	}
	int answer = 0;
	vector<P> already;
	for(int i = 0; i < n; ++i) {
		P he = (points[0] + points[i]) / 2;
		debug() << imie(i) imie(he.x) imie(he.y);
		assert(!(he == mid));
		bool ok = true;
		for(const P & p : already) if((p - mid) * (he - mid) == 0) {
			ok = false;
			break;
		}
		if(!ok) continue;
		vector<ll> values;
		for(const P & p : points)
			values.push_back((p - mid) * (he - mid));
		sort(values.begin(), values.end());
		ll should = values[0] + values.back();
		for(int j = 0; j < n; ++j)
			if(values[j] + values[n-1-j] != should) {
				ok = false;
				break;
			}
		if(ok) {
			++answer;
			already.push_back(he);
		}
	}
	printf("%d\n", answer);
}