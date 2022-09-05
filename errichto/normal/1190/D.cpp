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

void mapping(vector<int>& vec) {
	set<int> secik;
	for(int x : vec) {
		secik.insert(x);
	}
	int cnt = 0;
	map<int,int> mapka;
	for(int x : secik) {
		mapka[x] = cnt++;
	}
	for(int& x : vec) {
		x = mapka[x];
	}
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> x(n), y(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
	}
	mapping(x);
	mapping(y);
	
	vector<pair<int,int>> they(n);
	for(int i = 0; i < n; ++i) {
		they[i] = {x[i], y[i]};
	}
	sort(they.begin(), they.end(), [&](const pair<int,int>& a, const pair<int,int>& b) {
		return make_pair(a.second, a.first) > make_pair(b.second, b.first);
	});
	debug() << imie(they);
	
	int B = 1;
	while(B <= n) {
		B *= 2;
	}
	vector<int> tree(2 * B);
	auto get_sum = [&](int L, int R) {
		L += B;
		R += B;
		int r = tree[L];
		if(L != R) {
			r += tree[R];
		}
		while(L < R - 1) {
			if(L % 2 == 0) {
				r += tree[L+1];
			}
			if(R % 2 == 1) {
				r += tree[R-1];
			}
			L /= 2;
			R /= 2;
		}
		return r;
	};
	long long answer = 0;
	reverse(they.begin(), they.end());
	for(int i = n - 1; i >= 0; --i) {
		int my_x = they[i].first;
		int my_y = they[i].second;
		if(!tree[my_x+B]) {
			for(int z = my_x + B; z >= 1; z /= 2) {
				tree[z]++;
			}
		}
		int lim_x = 0;
		if(i != 0 && they[i-1].second == my_y) {
			lim_x = they[i-1].first + 1;
		}
		int left = get_sum(lim_x, my_x);
		int right = get_sum(my_x, n - 1);
		debug() << imie(left) imie(right);
		answer += (long long) left * right;
	}
	printf("%lld\n", answer);
}