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

bool test_case() {
	int n;
	scanf("%d", &n);
	n *= 2;
	vector<int> in(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &in[i]);
		in[i]--;
	}
	int big = in[0];
	int cur = 1;
	vector<int> all;
	for(int i = 1; i < n; ++i) {
		if(in[i] > big) {
			all.push_back(cur);
			cur = 1;
			big = in[i];
		}
		else {
			cur++;
		}
	}
	all.push_back(cur);
	vector<bool> can(n + 1);
	can[0] = true;
	for(int x : all) {
		for(int i = n - x; i >= 0; --i) {
			if(can[i]) {
				can[i+x] = true;
			}
		}
	}
	return can[n/2];
	// int big = -1;
	// int cur = 0;
	// vector<int> all;
	// for(int x : in) {
		// cur++;
		// if(x > big) {
			// big = x;
			// all.push_back(cur);
			// cur = 0;
		// }
	// }
	// all.push_back(cur);
	/*
	debug() << imie(all);
	return true;
	vector<vector<bool>> can(n, vector<bool>(n));
	can[1][1] = true;
	for(int i = 1; i < n - 1; ++i) {
		for(int cnt_me = 1; cnt_me <= i; ++cnt_me) {
			int cnt_he = i + 1 - cnt_me;
			if(can[i][cnt_me]) {
				debug() << imie(i) imie(cnt_me) imie(cnt_he);
				if(in[i-1] < in[i]) {
					can[i+1][cnt_he+1] = true;
				}
				else {
					int j = i;
					while(j < n && in[j] < in[i-1]) {
						++j;
					}
					if(j < n) {
						can[j][cnt_he+1] = true;
					}
				}
			}
		}
	}
	return can[n-1][n/2];*/
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		puts(test_case() ? "YES" : "NO");
	}
}