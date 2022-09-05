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

const int nax = 1e6 + 5;
bool is_prime[nax];
vector<int> primes[nax];
int form[nax];

void test_case() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	map<int, int> cnt;
	int start = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		a[i] = form[a[i]];
		start = max(start, ++cnt[form[a[i]]]);
	}
	int zero = 0;
	for(pair<int,int> p : cnt) {
		if(p.first == 1 || p.second % 2 == 0) {
			zero += p.second;
		}
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		long long x;
		scanf("%lld", &x);
		if(x == 0) {
			printf("%d\n", start);
		}
		else {
			debug() << imie(start) imie(zero);
			printf("%d\n", max(start, zero));
		}
	}
}

int main() {
	for(int i = 2; i < nax; ++i) {
		is_prime[i] = true;
	}
	form[1] = 1;
	for(int i = 2; i < nax; ++i) {
		if(is_prime[i]) {
			form[i] = i;
			for(int j = 2 * i; j < nax; j += i) {
				is_prime[j] = false;
				if(form[j] == 0) {
					if(form[j / i] % i == 0) {
						form[j] = form[j / i] / i;
					}
					else {
						form[j] = form[j / i] * i;
					}
				}
			}
		}
	}
	for(int i = 1; i <= 100; ++i) {
		debug() << imie(i) imie(form[i]);
	}
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}