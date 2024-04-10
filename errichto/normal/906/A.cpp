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

const int nax = 1e5 + 5;
char sl[nax];

int read() {
	int mask = 0;
	scanf("%s", sl);
	int n = strlen(sl);
	for(int i = 0; i < n; ++i)
		mask |= 1 << (sl[i] - 'a');
	return mask;
}

int main() {
	int n;
	scanf("%d", &n);
	const int ALL = (1 << 26) - 1;
	int possible = ALL;
	bool already = false;
	int answer = 0;
	bool flag = false;
	for(int i = 0; i < n; ++i) {
		char type;
		scanf(" %c", &type);
		int mask = read();
		if(type == '.') {
			possible &= ALL ^ mask;
		}
		else if(type == '!') {
			if(already) ++answer;
			possible &= mask;
		}
		else {
			if(!already) {
				possible &= ALL ^ mask;
			}
			else if(already && mask != possible) {
				++answer;
			}
			else if(already && mask == possible) {
				if(!flag) {
					flag = true;
				}
				else ++answer;
			}
		}
		already = __builtin_popcount(possible) == 1;
	}
	printf("%d\n", answer);
}