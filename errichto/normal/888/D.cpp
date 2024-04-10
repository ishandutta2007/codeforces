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

long long binom(int a, int b) {
	assert(b <= 4);
	long long r = 1;
	for(int i = 1; i <= b; ++i) {
		r *= (a + 1 - i);
		r /= i;
	}
	return r;
}

int main() {
	debug() << imie(binom(5, 2));
	int n, k;
	cin >> n >> k;
	long long answer = 0;
	for(int bad = 0; bad <= min(k,n); ++bad) {
		long long ways = binom(n, bad);
		vector<int> perm;
		for(int i = 0; i < bad; ++i) {
			perm.push_back(i);
		}
		int count = 0;
		do {
			bool is_ok = true;
			for(int i = 0; i < bad; ++i) {
				if(perm[i] == i) {
					is_ok = false;
				}
			}
			if(is_ok) {
				++count;
			}
		} while(next_permutation(perm.begin(), perm.end()));
		answer += ways * count;
	}
	cout << answer << endl;
}