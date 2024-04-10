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

void test_case() {
	int n;
	scanf("%d", &n);
	vector<bool> is_b(2 * n + 1);
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		is_b[x] = true;
	}
	int answer = n + 1;
	for(int rep = 0; rep < 2; ++rep) {
		int balance = 0;
		int lower = 0;
		for(int i = 1; i <= 2 * n; ++i) {
			if(is_b[i]) {
				balance++;
			}
			else {
				balance--;
			}
			lower = max(lower, balance); // at least that many
				// need to be minimum in its pair
		}
		answer -= lower;
		reverse(is_b.begin() + 1, is_b.end());
	}
	printf("%d\n", answer);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}


// x = 0 -> max from every pair


// 2 4 5 9 10 -> 0101100011

// 1 2 3 4 5
  // ^   ^ ^

// (1,2), (3, 4), (?, 5)


// go from low values and get lower limit for x