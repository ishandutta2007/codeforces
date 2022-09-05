#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
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

using ll = long long;

int cnt[4];
int sum;
vector<int> all;
void add(int x) {
	all.push_back(x);
	assert(cnt[x] > 0);
	--cnt[x];
	if(sum == (int) all.size()) {
		puts("YES");
		for(int y : all) {
			printf("%d ", y);
		}
		puts("");
		exit(0);
	}
}
void pop() {
	++cnt[all.back()];
	all.pop_back();
}

void rec() {
	int last = all.back();
	int must = -1;
	if(last == 0) {
		must = 1;
	}
	if(last == 1) {
		if(cnt[0]) {
			must = 0;
		}
		else {
			must = 2;
		}
	}
	if(last == 2) {
		if(cnt[3]) {
			must = 3;
		}
		else {
			must = 1;
		}
	}
	if(last == 3) {
		must = 2;
	}
	assert(must != - 1 && abs(last - must) == 1);
	if(cnt[must] == 0) {
		return;
	}
	add(must);
	rec();
	pop();
}

int main() {
	for(int i = 0; i < 4; ++i) {
		scanf("%d", &cnt[i]);
		sum += cnt[i];
	}
	// if(cnt[0] + cnt[1] + cnt[2] + cnt[3] == 1) {
		// puts("YES");
		// for(int i = 0; i < 4; ++i) {
			// if(cnt[i]) {
				// printf("%d", i);
			// }
		// }
		// return 0;
	// }
	for(int start = 0; start < 4; ++start) {
		if(cnt[start] > 0) {
			add(start);
			rec();
			pop();
		}
	}
	puts("NO");
}