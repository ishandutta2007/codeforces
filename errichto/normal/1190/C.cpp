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

using ll = long long;

const int nax = 1e5 + 5;
char in[nax];

void ONE() {
	puts("tokitsukaze");
	exit(0);
}
void TWO() {
	puts("quailty");
	exit(0);
}
void DRAW() {
	puts("once again");
	exit(0);
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", in);
	vector<int> pref(n + 1);
	for(int i = 1; i <= n; ++i) {
		pref[i] = pref[i-1] + (in[i-1] == '1');
	}
	auto get_sum = [&](int a, int b) {
		if(a > b) {
			return 0;
		}
		return pref[b+1] - pref[a];
	};
	for(int i = 0; i <= n - k; ++i) {
		int others = get_sum(0, i - 1) + get_sum(i + k, n - 1);
		if(others == n - k || others == 0) {
			ONE();
		}
	}
	set<int> ones, zeros;
	auto add = [&](int i) {
		if(in[i] == '1') {
			ones.insert(i);
		}
		else {
			zeros.insert(i);
		}
	};
	auto rem = [&](int i) {
		if(in[i] == '1') {
			ones.erase(i);
		}
		else {
			zeros.erase(i);
		}
	};
	for(int i = k; i < n; ++i) {
		add(i);
	}
	auto needs_span = [&](const set<int>& s) {
		if(s.empty()) {
			return 0;
		}
		return *s.rbegin() - *s.begin() + 1;
	};
	for(int i = 0; i <= n - k; ++i) {
		zeros.insert(i);
		zeros.insert(i + k - 1);
		if(needs_span(zeros) <= k || needs_span(ones) <= k) {
			// he can win against us :(
		}
		else {
			debug() << imie(i) imie(zeros) imie(ones);
			DRAW();
		}
		zeros.erase(i);
		zeros.erase(i + k - 1);
		
		ones.insert(i);
		ones.insert(i + k - 1);
		if(needs_span(zeros) <= k || needs_span(ones) <= k) {
			// he can win against us :(
		}
		else {
			debug() << imie(i) imie(zeros) imie(ones);
			DRAW();
		}
		ones.erase(i);
		ones.erase(i + k - 1);
		
		if(i != n - k) {
			add(i);
			rem(i + k);
		}
	}
	TWO();
	
	// vector<int> diff(n - 1);
	// for(int i = 0; i < n - 1; ++i) {
		// diff[i] = in[i] != in[i+1];
	// }
	// debug() << imie(diff);
	
}