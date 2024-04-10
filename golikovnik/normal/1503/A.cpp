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

const int nax = 2e5 + 5;
char s[nax];

bool test_case() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int ones = 0;
	for(int i = 0; i < n; ++i) {
		if(s[i] == '1') {
			ones++;
		}
	}
	if(ones % 2) {
		return false;
	}
	int done_ones = 0;
	string a, b;
	int A = 0, B = 0;
	for(int i = 0; i < n; ++i) {
		if(s[i] == '0') {
			if(A < B) {
				swap(A, B);
				swap(a, b);
			}
			a += ')';
			b += '(';
			A--;
			B++;
			if(A < 0) {
				return false;
			}
		}
		else {
			if(done_ones < ones / 2) {
				a += '(';
				b += '(';
				A++;
				B++;
			}
			else {
				a += ')';
				b += ')';
				A--;
				B--;
				if (A < 0 || B < 0) return false;
			}
			done_ones++;
		}
	}
	if(A != 0 || B != 0) {
		return false;
	}
	puts("YES");
	printf("%s\n", a.c_str());
	printf("%s\n", b.c_str());
	return true;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		if(!test_case()) {
			puts("NO");
		}
	}
}