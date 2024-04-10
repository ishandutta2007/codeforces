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

int n;
const int nax = 25;
int mask[nax];
int memo[nax][nax];

int answer = nax;
int ans_print;

int print;
void rec(int a, int already) {
	if(a == n) {
		bool ok = true;
		for(int i = 0; i < n; ++i)
			if(mask[i] != ((1 << n) - 1))
				ok = false;
		if(ok && already < answer) {
			answer = already;
			ans_print = print;
		}
		return;
	}
	if(print & (1 << a)) print ^= 1 << a;
	rec(a + 1, already);
	print ^= 1 << a;
	for(int i = 0; i < n; ++i) {
		memo[a][i] = mask[i];
		if(mask[a] & (1 << i))
			mask[i] |= mask[a];
	}
	rec(a + 1, already + 1);
	for(int i = 0; i < n; ++i)
		mask[i] = memo[a][i];
}

int main() {
	int m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		mask[i] = 1 << i;
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		mask[a] |= 1 << b;
		mask[b] |= 1 << a;
	}
	rec(0, 0);
	printf("%d\n", answer);
	assert(answer == __builtin_popcount(ans_print));
	for(int i = 0; i < n; ++i)
		if(ans_print & (1 << i))
			printf("%d ", i + 1);
	puts("");
}