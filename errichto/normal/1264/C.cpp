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

const int mod = 998244353;

int mul(int a, int b) {
	return (long long) a * b % mod;
}
int my_pow(int a, int b) {
	int r = 1;
	while(b) {
		if(b % 2) {
			r = mul(r, a);
		}
		a = mul(a, a);
		b /= 2;
	}
	return r;
}
int my_inv(int a) {
	return my_pow(a, mod - 2);
}
int sub(int a, int b) {
	a -= b;
	if(a < 0) {
		a += mod;
	}
	return a;
}
int add(int a, int b) {
	a += b;
	if(a >= mod) {
		a -= mod;
	}
	return a;
}

struct Node {
	int p, ev, len;
	void merge(Node L, Node R) {
		len = L.len + R.len;
		p = mul(L.p, R.p);
		debug() << imie(L.p) imie(L.ev) imie(R.p) imie(R.ev);
		ev = add(L.ev, add(mul(L.p, R.ev), mul(L.p, mul(sub(1, R.p), L.len))));
	}
};

int B;
vector<Node> tree, tree2;

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	B = 1;
	while(B < n) {
		B *= 2;
	}
	tree.resize(2 * B, Node{1, 0, 1});
	// tree2 = tree;
	const int memo_inv = my_inv(100);
	for(int i = 0; i < n; ++i) {
		int p;
		scanf("%d", &p);
		p = mul(p, memo_inv);
		tree[B+i] = Node{p, sub(1, p), 1};
	}
	for(int i = B - 1; i >= 1; --i) {
		tree[i].merge(tree[2*i], tree[2*i+1]);
	}
	auto get_interval = [&](int L, int R) {
		debug() << "get_interval" imie(L) imie(R);
		L += B;
		R += B;
		vector<int> left, right;
		left.push_back(L);
		if(L != R) {
			right.push_back(R);
		}
		while(L < R - 1) {
			if(L % 2 == 0) {
				left.push_back(L + 1);
			}
			if(R % 2 == 1) {
				right.push_back(R - 1);
			}
			L /= 2;
			R /= 2;
		}
		Node node = tree[left[0]];
		left.erase(left.begin());
		for(int i : left) {
			node.merge(node, tree[i]);
		}
		reverse(right.begin(), right.end());
		for(int i : right) {
			node.merge(node, tree[i]);
		}
		debug() << imie(left) imie(right) imie(B) imie(my_inv(node.p)) imie(node.p) imie(node.ev) imie(mul(my_inv(node.p), node.ev));
		if(node.p == 1) {
			return 0;
		}
		else {
			return mul(my_inv(node.p), node.ev);
		}
	};
	// tree2[B+0] = get_interval(0, n - 1);
	int answer = get_interval(0, n - 1);
	// for(int i = (B+0)/2; i >= 1; i /= 2) {
		// tree2[i].merge(tree2[2*i], tree2[2*i+1]);
	// }
	set<int> safe{0, n};
	// debug() << imie(tree2[1].p) imie(tree2[1].ev);
	debug() << imie(answer) imie(add(n, answer));
	while(q--) {
		int u;
		scanf("%d", &u);
		--u;
		int big = *safe.upper_bound(u);
		int small = *prev(safe.lower_bound(u));
		debug() << imie(small) imie(u) imie(big);
		if(safe.count(u)) {
			safe.erase(u);
			answer = sub(answer, get_interval(u, big - 1));
			answer = sub(answer, get_interval(small, u - 1));
			answer = add(answer, get_interval(small, big - 1));
			// tree2[B+u] = Node{1, 0};
			// tree2[B+small] = get_interval(small, big - 1);
		}
		else {
			safe.insert(u);
			answer = add(answer, get_interval(u, big - 1));
			answer = add(answer, get_interval(small, u - 1));
			answer = sub(answer, get_interval(small, big - 1));
			// tree2[B+small] = get_interval(small, u - 1);
			// tree2[B+u] = get_interval(u, big - 1);
		}
		// for(int start : {B + u, B + small}) {
			// for(int i = start / 2; i >= 1; i /= 2) {
				// tree2[i].merge(tree2[2*i], tree2[2*i+1]);
			// }
		// }
		// printf("%d %d\n", tree2[1].p, tree2[1].ev);
		debug() << imie(answer) imie(add(n, answer));
		printf("%d\n", add(n, answer));
	}	
}