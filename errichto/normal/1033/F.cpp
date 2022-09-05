#include "bits/stdc++.h"
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

typedef long long ll;

//~ int my_pow(int a, int b) {
	//~ int r = 1;
	//~ while(b) {
		//~ r *= a;
		//~ --b;
	//~ }
	//~ return r;
//~ }

int w;
char sl[25];
vector<int> three, cnt;

int answer;

void rec(int i, int mask) {
	if(i == -1) {
		answer += cnt[mask];
		debug() << imie(mask) imie(cnt[mask]);
		return;
	}
	if(sl[i] == 'A') {
		rec(i - 1, mask + three[i]);
		rec(i - 1, mask);
		return;
	}
	if(sl[i] == 'X') {
		rec(i - 1, mask);
		rec(i - 1, mask + 2 * three[i]);
		return;
	}
	if(sl[i] == 'o') {
		rec(i - 1, mask + three[i]);
		rec(i - 1, mask + 2 * three[i]);
		return;
	}
	if(sl[i] == 'x') {
		rec(i - 1, mask + three[i]);
		return;
	}
	if(sl[i] == 'a') {
		rec(i - 1, mask + 2 * three[i]);
		return;
	}
	if(sl[i] == 'O') {
		rec(i - 1, mask);
		return;
	}
	assert(false);
}

int main() {
	int n, m;
	scanf("%d%d%d", &w, &n, &m);
	vector<int> in(1 << w);
	three.resize(w + 1);
	three[0] = 1;
	for(int i = 1; i <= w; ++i) {
		three[i] = three[i-1] * 3;
	}
	while(n--) {
		int x;
		scanf("%d", &x);
		++in[x];
	}
	cnt.resize(three[w]);
	for(int a = 0; a < (1 << w); ++a) {
		for(int b = a; b < (1 << w); ++b) {
			int ways = in[a] * in[b] * 2;
			if(a == b) {
				ways = in[a] * in[a];
			}
			if(ways == 0) {
				continue;
			}
			int x = 0;
			for(int i = 0; i < w; ++i) {
				int sum = bool(a & (1 << i));
				sum += bool(b & (1 << i));
				x += three[i] * sum;
			}
			assert(x < three[w]);
			cnt[x] += ways;
		}
	}
	while(m--) {
		answer = 0;
		scanf("%s", sl);
		reverse(sl, sl + w);
		rec(w - 1, 0);
		printf("%d\n", answer);
	}
	//~ for(int mask = 0; mask < three[w]; ++mask) {
		//~ int ways = cnt[mask];
		//~ if(ways == 0) {
			//~ continue;
		//~ }
		
	//~ }
}