#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
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

struct A {
	int t[8];
	int x, X, y, Y;
	void read() {
		for(int i = 0; i < 8; ++i) scanf("%d", &t[i]);
		x = min({t[0], t[2], t[4], t[6]});
		X = max({t[0], t[2], t[4], t[6]});
		y = min({t[1], t[3], t[5], t[7]});
		Y = max({t[1], t[3], t[5], t[7]});
	}
	bool contains(int a, int b) {
		return x <= a && a <= X && y <= b && b <= Y;
	}
};

struct B {
	int t[8];
	int x, y;
	int dist(int a, int b) { return abs(a - x) + abs(b - y); }
	void read() {
		for(int i = 0; i < 8; ++i) scanf("%d", &t[i]);
		x = (t[0] + t[2] + t[4] + t[6]) / 4;
		y = (t[1] + t[3] + t[5] + t[7]) / 4;
	}
	bool contains(int a, int b) {
		return dist(a, b) <= dist(t[0], t[1]);
	}
};

void YES() {
	puts("YES");
	exit(0);
}

int main() {
	A a;
	a.read();
	B b;
	b.read();
	for(int i = -100; i <= 100; ++i)
		for(int j = -100; j <= 100; ++j)
			if(a.contains(i, j) && b.contains(i, j))
				YES();
	puts("NO");
}