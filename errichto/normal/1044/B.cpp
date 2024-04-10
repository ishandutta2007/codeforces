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

const int nax = 1005;
vector<int> w[nax];

vector<int> read_one() {
	int k;
	scanf("%d", &k);
	vector<int> vec(k);
	for(int& x : vec) {
		scanf("%d", &x);
	}
	return vec;
}

int query(char type, int a) {
	assert(type == 'A' || type == 'B');
	printf("%c %d\n", type, a);
	fflush(stdout);
	int r;
	scanf("%d", &r);
	return r;
}

void answer(int x) {
	printf("C %d\n", x);
	fflush(stdout);
}

int found;
bool is_spec[nax];

void dfs(int a, int par) {
	if(is_spec[a]) {
		found = a;
		return;
	}
	for(int b : w[a]) {
		if(b == par) {
			continue;
		}
		dfs(b, a);
	}
}

void test_case() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i <= n + 1; ++i) {
		w[i].clear();
	}
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].push_back(b);
		w[b].push_back(a);
	}
	vector<int> A = read_one();
	vector<int> B = read_one();
	int for_me = query('B', B[0]);
	for(int x : A) {
		if(x == for_me) {
			answer(x);
			return;
		}
	}
	for(int i = 0; i <= n + 1; ++i) {
		is_spec[i] = false;
	}
	for(int x : A) {
		is_spec[x] = true;
	}
	found = -1;
	dfs(for_me, -1);
	if(found == -1) {
		answer(-1);
		return;
	}
	int maybe = query('A', found);
	for(int x : B) {
		if(x == maybe) {
			answer(found);
			return;
		}
	}
	answer(-1);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}