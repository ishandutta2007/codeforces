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

const int pot = 512 * 1024;
int tr[2*pot];
int n;

int f(int start, int candidate) {
	start += pot;
	if(tr[start] % candidate) return start - pot;
	while(start > 1) {
		if(start % 2 == 0 && tr[start+1] % candidate > 0) {
			++start;
			break;
		}
		start /= 2;
	}
	if(start == 1) return n + 1;
	assert(tr[start] % candidate > 0);
	while(start < pot) {
		if(tr[2*start] % candidate) start *= 2;
		else start = 2 * start + 1;
	}
	return start - pot;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < 2 * pot; ++i) tr[i] = 1;
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		tr[pot+i] = x;
	}
	for(int i = pot - 1; i >= 1; --i)
		tr[i] = __gcd(tr[2*i], tr[2*i+1]);
	int q;
	scanf("%d", &q);
	while(q--) {
		int type;
		scanf("%d", &type);
		if(type == 1) {
			int low, high, candidate;
			scanf("%d%d%d", &low, &high, &candidate);
			if(candidate == 1) {
				puts("YES");
				continue;
			}
			int up_to = f(low, candidate);
			if(up_to >= n) {
				puts("YES");
				continue;
			}
			int x = f(up_to + 1, candidate);
			if(x > high) puts("YES");
			else puts("NO");
		}
		else {
			assert(type == 2);
			int i, new_value;
			scanf("%d%d", &i, &new_value);
			tr[pot+i] = new_value;
			for(int x = (pot + i) / 2; x >= 1; x /= 2)
				tr[x] = __gcd(tr[2*x], tr[2*x+1]);
		}
	}
}