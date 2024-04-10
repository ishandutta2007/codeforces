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

vector<pair<int,int>> pairs;

void rec(int L, int R) {
	if(L == R) {
		return;
	}
	int len = R - L + 1;
	int half = len / 2;
	rec(L, L + half - 1);
	rec(L + half, L + half + half - 1);
	for(int i = 0; i < half; ++i) {
		pairs.emplace_back(L + i, L + i + half);
	}
}

void merge(int A, int B) {
	debug() << "merge" imie(A) imie(B);
	int h = B - A + 1;
	assert(__builtin_popcount(h) == 1);
	int prv = A - h;
	for(int i = 0; i < h; ++i) {
		pairs.emplace_back(prv + i, prv + h + i);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int big = 20;
	while(!(n & (1 << big))) {
		big--;
	}
	debug() << imie(big) imie((1<<big));
	rec(1, 1 << big);
	int last = 1 << big;
	int cnt_eq = 1 << big;
	for(int bit = 0; bit < big; ++bit) {
		if(n & (1 << bit)) {
			int me = 1 << bit;
			rec(last + 1, last + me);
			while(cnt_eq < me) {
				merge(last - cnt_eq + 1, last);
				cnt_eq *= 2;
			}
			merge(last + 1, last + me);
			last += me;
			cnt_eq = 2 * me;
			
		}
	}
	// rec(1, n);
	assert((int) pairs.size() <= 500 * 1000);
	vector<int> hack(n);
	for(int i = 0; i < n; ++i) {
		hack[i] = i;
	}
	printf("%d\n", (int) pairs.size());
	debug() << imie(pairs.size());
	for(pair<int,int> p : pairs) {
		printf("%d %d\n", p.first, p.second);
		int a = p.first - 1;
		int b = p.second - 1;
		hack[a] = hack[b] = (hack[a] + hack[b]) % n;
	}
	debug() << imie(hack);
}