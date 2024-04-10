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

#warning fix MAGIC to 500
const int MAGIC = 500;

const int nax = 1e5 + 5;
vector<int> edges[nax];
bool is_big(int a) {
	return (int) edges[a].size() >= MAGIC;
}
bool is_small(int a) {
	return !is_big(a);
}

int smaller[nax];
int degree[nax];
vector<int> big_edges[nax];
int value[nax];

vector<int> big_bigger[nax];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int a = 1; a <= n; ++a) {
		value[a] = a;
	}
	for(int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for(int a = 1; a <= n; ++a) {
		degree[a] = edges[a].size();
	}
	
	ll answer = 0;
	
	auto inc = [&](int x) {
		answer += (ll) smaller[x] * (degree[x] - smaller[x]);
	};
	auto dec = [&](int x) {
		answer -= (ll) smaller[x] * (degree[x] - smaller[x]);
	};
	
	for(int a = 1; a <= n; ++a) {
		for(int b : edges[a]) {
			if(a > b) {
				smaller[a]++;
			}
		}
		inc(a);
	}
	for(int a = 1; a <= n; ++a) {
		if(is_big(a)) {
			for(int b : edges[a]) {
				big_edges[b].push_back(a);
				if(a < b) {
					big_bigger[a].push_back(b);
				}
			}
		}
	}
	int q;
	scanf("%d", &q);
	printf("%lld\n", answer);
	for(int day = n + 1; day <= n + q; ++day) {
		int a;
		scanf("%d", &a);
		dec(a);
		smaller[a] = degree[a];
		inc(a);
		if(is_big(a)) {
			for(int x : big_bigger[a]) {
				assert(value[a] < value[x]);
				dec(x);
				smaller[x]--;
				inc(x);
			}
			big_bigger[a].clear();
		}
		else {
			for(int x : edges[a]) {
				if(value[a] < value[x]) {
					dec(x);
					smaller[x]--;
					inc(x);
				}
			}
		}
		for(int b : big_edges[a]) {
			if(value[a] < value[b]) {
				if(is_big(b)) {
					big_bigger[b].push_back(a);
				}
			}
		}
		value[a] = day; // infinity
		printf("%lld\n", answer);
	}
}