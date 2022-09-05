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

bool is_prime(int a) {
	if(a < 2) {
		return false;
	}
	for(int i = 2; i * i <= a; ++i) {
		if(a % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	int a = 0, b = 0;
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		if(x == 1) {
			++a;
		}
		else {
			++b;
		}
	}
	int sum = 0;
	auto one = [&]() {
		sum += 1;
		--a;
		printf("%d ", 1);
	};
	auto two = [&]() {
		sum += 2;
		--b;
		printf("%d ", 2);
	};
	for(int i = 0; i < n; ++i) {
		if(i == 0 && b) {
			two();
		}
		else if(i == 1 && a) {
			one();
		}
		else if(is_prime(sum+1) && a) {
			one();
		}
		else if(b) {
			two();
		}
		else {
			one();
		}
	}
}