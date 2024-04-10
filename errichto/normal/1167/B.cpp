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

using ll = long long;

// _ _ _ _ _ _

vector<int> hidden{-1, 16, 8, 4, 23, 42, 15};

int main() {
	vector<int> answer(7);
	for(int i = 2; i <= 5; ++i) {
		printf("? 1 %d\n", i);
		fflush(stdout);
		//~ answer[i] = hidden[1] * hidden[i];
		scanf("%d", &answer[i]);
	}
	const vector<int> values = {4, 8, 15, 16, 23, 42};
	for(int x : values) {
		bool ok = true;
		for(int i = 2; i <= 5; ++i) {
			if(answer[i] % x != 0) {
				ok = false;
			}
		}
		if(ok) {
			answer[1] = x;
		}
	}
	for(int i = 2; i <= 5; ++i) {
		answer[i] /= answer[1];
	}
	for(int x : values) {
		answer[6] += x;
	}
	for(int i = 1; i <= 5; ++i) {
		answer[6] -= answer[i];
	}
	printf("!");
	for(int i = 1; i <= 6; ++i) {
		printf(" %d", answer[i]);
	}
	puts("");
}