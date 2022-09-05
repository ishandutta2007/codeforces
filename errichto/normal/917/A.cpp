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

const int nax = 5005;
char sl[nax];
bool ok[nax][nax];

int main() {
	scanf("%s", sl);
	int n = strlen(sl);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			ok[i][j] = (j - i + 1) % 2 == 0;
	for(int a = 0; a < n; ++a) {
		int so_far = 0;
		for(int b = a; b < n; ++b) {
			if(sl[b] == ')') --so_far;
			else ++so_far;
			if(so_far < 0) {
				ok[a][b] = false;
				for(int i = b + 1; i < n; ++i)
					ok[a][i] = false;
				break;
			}
		}
	}
	for(int a = n - 1; a >= 0; --a) {
		int so_far = 0;
		for(int b = a; b >= 0; --b) {
			if(sl[b] == '(') --so_far;
			else ++so_far;
			if(so_far < 0) {
				ok[b][a] = false;
				for(int i = b - 1; i >= 0; --i)
					ok[i][a] = false;
				break;
			}
		}
	}
	int ans = 0;
	for(int a = 0; a < n; ++a)
		for(int b = a; b < n; ++b)
			ans += ok[a][b];
	printf("%d\n", ans);
}