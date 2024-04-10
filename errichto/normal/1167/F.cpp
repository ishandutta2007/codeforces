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

const int mod = 1e9 + 7;

void add_self(int& a, int b) {
	a += b;
	if(a >= mod) {
		a -= mod;
	}
}

int answer;

void solve(vector<int> a) {
	int n = a.size();
	vector<pair<int,int>> b;
	for(int i = 0; i < n; ++i) {
		b.emplace_back(a[i], i);
	}
	sort(b.begin(), b.end());
	
	int B = 1;
	while(B < n) {
		B *= 2;
	}
	vector<int> tree(2 * B);
	
	for(pair<int,int> p : b) {
		// p = (value, index)
		int i = p.second;
		int L = 0, R = i - 1;
		int sum = 0;
		if(L <= R) {
			L += B;
			R += B;
			add_self(sum, tree[L]);
			if(L != R) {
			add_self(sum, tree[R]);
			}
			while(L < R - 1) {
				if(L % 2 == 0) {
					add_self(sum, tree[L+1]);
				}
				if(R % 2 == 1) {
					add_self(sum, tree[R-1]);
				}
				L /= 2;
				R /= 2;
			}
		}
		answer = (answer + (long long) sum * a[i] % mod * (n - i)) % mod;
		for(int x = B + i; x >= 1; x /= 2) {
			add_self(tree[x], i + 1);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int rep = 0; rep < 2; ++rep) {
		solve(a);
		reverse(a.begin(), a.end());
	}
	for(int i = 0; i < n; ++i) {
		answer = (answer + (long long) a[i] * (i + 1) % mod * (n - i)) % mod;
	}
	printf("%d\n", answer);
}