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
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

int k;

int read_mask() {
	char s[25];
	scanf("%s", s);
	int mask = 0;
	for(int i = 0; i < k; ++i) {
		if(s[i] == '1') {
			mask ^= (1 << i);
		}
	}
	return mask;
}

pair<int,int> best[1<<20];

void relax(int mask) {
	for(int i = 0; i < k; ++i) {
		int m2 = mask ^ (1 << i);
		if(best[m2].first < best[mask].first - 1) {
			best[m2] = {best[mask].first - 1, best[mask].second};
			relax(m2);
		}
	}
}

struct P {
	vector<int> p;
	P() {
		p.resize(k);
		for(int i = 0; i < k; ++i) {
			p[i] = i;
		}
	}
	void apply(int a, int b) {
		swap(p[a], p[b]);
	}
	P inverse() {
		vector<int> p2(k);
		for(int i = 0; i < k; ++i) {
			p2[p[i]] = i;
		}
		P res;
		res.p = p2;
		return res;
	}
	int get_new(int mask) {
		int mask2 = 0;
		for(int i = 0; i < k; ++i) {
			if(mask & (1 << i)) {
				mask2 ^= (1 << p[i]);
			}
		}
		return mask2;
	}
};

int main() {
	int n, m;
	scanf("%d%d%d", &n, &m, &k);
	int S = read_mask();
	int T = read_mask();
	vector<pair<int,int>> ope(n);
	for(int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		ope[i] = {a - 1, b - 1};
	}
	for(int mask = 0; mask < (1 << k); ++mask) {
		best[mask] = {-1, -1};
	}
	best[T] = {k, n - 1};
	relax(T);
	auto apply = [&](int& mask, int i) {
		int a = ope[i].first;
		int b = ope[i].second;
		if(bool(mask & (1 << a)) != bool(mask & (1 << b))) {
			mask ^= (1 << a);
			mask ^= (1 << b);
		}
	};
	vector<P> pref(n);
	for(int i = 0; i < n; ++i) {
		if(i) {
			pref[i] = pref[i-1];
		}
		else {
			pref[i] = P();
		}
		pref[i].apply(ope[i].first, ope[i].second);
	}
	// vector<P> suf(n);
	// for(int i = n - 1; i >= 0; --i) {
		// if(i != n - 1) {
			// suf[i] = suf[i+1];
		// }
		// else {
			// suf[i] = P();
		// }
		// suf[i].apply(ope[i].first, ope[i].second);
	// }
	P suf = P();
	pair<int, pair<int,int>> answer;
	answer.first = -1;
	P whole = pref[n-1].inverse();
	bool done = false;
	for(int start = n - m; start >= 0; --start) {
		for(int mask = 0; mask < (1 << k); ++mask) {
			debug() << imie(mask) imie(best[mask]);
		}
		int mask = S;
		int new_mask = mask;
		if(start) {
			new_mask = pref[start-1].get_new(mask);
		}
		mask = new_mask;
		// for(int i = start - 1; i >= 0; --i) {
			// apply(mask, i);
		// }
		// assert(mask == new_mask);
		mask = whole.get_new(mask);
		// for(int i = 0; i < n; ++i) {
			// apply(mask, i);
		// }
		// assert(mask == new_mask2);
		
		int dist = best[mask].first;
		int R = best[mask].second;
		int L = start;
		if(start == 0) {
			debug() << imie(dist) imie(mask);
		}
		answer = max(answer, {dist, {L, R}});
		int suf_mask = T;
		if(start + m - 1 != n) {
			int j = start+m-1;
			if(!done) {
				for(int z = n - 1; z > j; --z) {
					suf.apply(ope[z].first, ope[z].second);
				}
				done = true;
			}
			suf.apply(ope[j].first, ope[j].second);
			suf_mask = suf.get_new(suf_mask);
			// suf_mask = suf[start+m-1].get_new(suf_mask);
		}
		
		// for(int i = start + m - 1; i < n; ++i) {
			// apply(suf_mask, i);
		// }
		best[suf_mask] = {k, start + m - 2};
		relax(suf_mask);
	}
	printf("%d\n", answer.first);
	int L = answer.second.first;
	int R = answer.second.second;
	printf("%d %d\n", L + 1, R + 1);
}