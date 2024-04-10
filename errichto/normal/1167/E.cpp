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

const int INF = 1e9 + 5;

int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	vector<int> small(x, INF);
	vector<int> big(x, -1);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		--a[i]; // values 0 through x-1
		small[a[i]] = min(small[a[i]], i);
		big[a[i]] = max(big[a[i]], i);
	}
	bool already_inc = true;
	for(int i = 0; i < n - 1; ++i) {
		if(!(a[i] <= a[i+1])) {
			already_inc = false;
		}
	}
	if(already_inc) {
		printf("%lld\n", (long long) x * (x + 1) / 2);
		return 0;
	}
	int L = 0;
	vector<int> one, two;
	int big_so_far = big[L];
	one.push_back(-1);
	one.push_back(big_so_far);
	while(big_so_far < small[L+1]) {
		big_so_far = max(big_so_far, big[L+1]);
		++L;
		one.push_back(big_so_far);
	}
	int R = x - 1;
	int small_so_far = small[R];
	two.push_back(INF);
	two.push_back(small_so_far);
	while(small_so_far > big[R-1]) {
		small_so_far = min(small_so_far, small[R-1]);
		--R;
		two.push_back(small_so_far);
	}
	debug() << imie(L) imie(R);
	debug() << imie(one);
	debug() << imie(two);
	long long answer = 0;
	// two pointers
	int up_to = (int) two.size() - 1;
	for(int A : one) {
		while(up_to >= 0 && two[up_to] < A) {
			--up_to;
		}
		answer += up_to + 1;
	}
	//~ for(int A : one) {
		//~ for(int B : two) {
			//~ if(A < B) {
				//~ ++answer;
			//~ }
		//~ }
	//~ }
	printf("%lld\n", answer);
}