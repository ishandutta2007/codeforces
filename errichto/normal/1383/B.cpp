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


bool brute(int even, int odd, int my_par, int his_par) {
	if(even == 0 && odd == 0) {
		return my_par == 1;
	}
	if(even && !brute(even-1, odd, his_par, my_par)) {
		return true;
	}
	if(odd && !brute(even, odd-1, his_par, my_par^1)) {
		return true;
	}
	return false;
}
bool fast(int even, int odd) {
	if((even + odd) % 2 == 1) {
		return (even%2 + odd) % 4 == 1;
	}
	else {
		return even % 2 == 1 || odd % 4 == 2;
	}
	// return brute(even, odd, 0, 0);
}

void test_case() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	vector<int> cnt(30);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		for(int bit = 0; bit < 30; ++bit) {
			if(a[i] & (1 << bit)) {
				++cnt[bit];
			}
		}
	}
	for(int bit = 29; bit >= 0; --bit) {
		if(cnt[bit] % 2 == 1) {
			int ones = cnt[bit];
			int zeros = n - ones;
			debug() << imie(zeros) imie(ones);
			puts(fast(zeros, ones) ? "WIN" : "LOSE");
			// puts(brute(zeros, ones, 0, 0) ? "WIN" : "LOSE");
			return;
		}
	}
	puts("DRAW");
}

int main() {
	/*
	for(int i = 0; i < 18; ++i) {
		for(int j = 0; j < 18; ++j) {
			// if((i + j) % 2 == 0) {
				assert(fast(i, j) == brute(i, j, 0, 0));
				printf("%d", (int) brute(i, j, 0, 0));
			// }
			// debug() << imie(i) imie(j) << brute(i, j, 0, 0); //printf("%d", (int) brute(i, j, 0, 0));
		}
		puts("");
	}*/
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}