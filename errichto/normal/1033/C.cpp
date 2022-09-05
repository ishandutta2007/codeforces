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



int main() {
	int n;
	scanf("%d", &n);
	vector<int> in(n + 1);
	vector<int> where(n + 1);
	vector<bool> answer(n + 1, true);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &in[i]);
		where[in[i]] = i;
	}
	auto ye = [&] (int i) {
		return 1 <= i && i <= n && !answer[i];
	};
	for(int x = n; x >= 1; --x) {
		//~ bool win = false;
		answer[where[x]] = false;
		for(int jump = x; jump <= n; jump += x) {
			debug() << imie(x) imie(where[x]) imie(jump) imie(where[x] + jump) imie(ye(where[x]+jump));
			if(ye(where[x] - jump) || ye(where[x] + jump)) {
				answer[where[x]] = true;
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		printf(answer[i] ? "A" : "B");
	}
	puts("");
}