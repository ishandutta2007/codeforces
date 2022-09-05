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

const int inf = 1e9 + 5;

struct S {
	int big, cnt, lazy;
	void merge(const S& a, const S& b) {
		assert(lazy == 0);
		big = max(a.big, b.big);
		cnt = 0;
		if(big == a.big) {
			cnt += a.cnt;
		}
		if(big == b.big) {
			cnt += b.cnt;
		}
	}
	void add_self(int by) {
		big += by;
		lazy += by;
	}
};
vector<S> tree;
int pot;

void rec(int id, int low, int high, int q_low, int q_high, int by) {
	if(high < q_low || q_high < low) {
		return;
	}
	if(q_low <= low && high <= q_high) {
		tree[id].add_self(by);
		return;
	}
	
	// propagate
	tree[2*id].add_self(tree[id].lazy);
	tree[2*id+1].add_self(tree[id].lazy);
	tree[id].lazy = 0;
	
	// recursive
	int last_left = (low + high) / 2;
	rec(2 * id, low, last_left, q_low, q_high, by);
	rec(2 * id + 1, last_left + 1, high, q_low, q_high, by);
	
	// merge
	tree[id].merge(tree[2*id], tree[2*id+1]);
}

const int nax = 4e5 + 5;
vector<int> w[nax];
int A[nax], B[nax];
int par[nax][20], h[nax];

int T = 0;
void dfs(int a) {
	A[a] = ++T;
	for(int b : w[a]) {
		if(b != par[a][0]) {
			h[b] = h[a] + 1;
			par[b][0] = a;
			for(int i = 1; i <= 19; ++i) {
				par[b][i] = par[ par[b][i-1] ][i-1];
			}
			dfs(b);
		}
	}
	B[a] = T;
	debug() << imie(a) imie(A[a]) imie(B[a]);
}

//~ int get_lca(int a, int b) {
	//~ if(h[a] < h[b]) {
		//~ swap(a, b);
	//~ }
	//~ for(int k = 19; k >= 0; --k) {
		//~ if(h[a] >= h[b] + (1 << k)) {
			//~ a = par[a][k];
		//~ }
	//~ }
	//~ assert(h[a] == h[b]);
	//~ for(int k = 19; k >= 0; --k) {
		//~ if(par[a][k] != par[b][k]) {
			//~ a = par[a][k];
			//~ b = par[b][k];
		//~ }
	//~ }
	//~ if(a != b) {
		//~ a = par[a][0];
		//~ b = par[b][0];
	//~ }
	//~ assert(a == b);
	//~ return a;
//~ }

bool contains(int a, int b) {
	return A[a] <= A[b] && A[b] <= B[a];
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].push_back(b);
		w[b].push_back(a);
	}
	h[1] = 1;
	dfs(1);
	pot = 1;
	while(pot <= n) {
		pot *= 2;
	}
	tree.resize(2 * pot, S{-inf, 0, 0});
	for(int i = 1; i <= n; ++i) {
		tree[pot+i] = S{0, 1, 0};
	}
	for(int i = pot - 1; i >= 1; --i) {
		tree[i].merge(tree[2*i], tree[2*i+1]);
	}
	assert(tree[1].cnt == n);
	int should = 0;
	set<pair<int,int>> present;
	while(q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(a > b) {
			swap(a, b);
		}
		if(present.count(make_pair(a, b))) {
			present.erase(make_pair(a, b));
			if(contains(b, a)) {
				swap(a, b);
			}
			if(contains(a, b)) {
				//~ rec(1, 0, pot - 1, A[a], B[a], 1);
				rec(1, 0, pot - 1, A[b], B[b], -1);
				//~ rec(1, 0, pot - 1, A[a], A[a], -1);
				int g = b;
				for(int k = 19; k >= 0; --k) {
					if(h[g] >= h[a] + (1 << k) + 1) {
						g = par[g][k];
					}
				}
				assert(h[a] + 1 == h[g]);
				rec(1, 0, pot - 1, A[g], B[g], 1);
			}
			else {
				rec(1, 0, pot - 1, A[a], B[a], -1);
				rec(1, 0, pot - 1, A[b], B[b], -1);
				--should;
			}
		}
		else {
			present.insert(make_pair(a, b));
			if(contains(b, a)) {
				swap(a, b);
			}
			if(contains(a, b)) {
				debug() << "contains" imie(a) imie(b);
				//~ rec(1, 0, pot - 1, A[a], B[a], -1);
				rec(1, 0, pot - 1, A[b], B[b], 1);
				//~ rec(1, 0, pot - 1, A[a], A[a], 1);
				int g = b;
				for(int k = 19; k >= 0; --k) {
					if(h[g] >= h[a] + (1 << k) + 1) {
						g = par[g][k];
					}
				}
				assert(h[a] + 1 == h[g]);
				rec(1, 0, pot - 1, A[g], B[g], -1);
			}
			else {
				rec(1, 0, pot - 1, A[a], B[a], 1);
				rec(1, 0, pot - 1, A[b], B[b], 1);
				++should;
			}
		}
		assert(tree[1].big <= should);
		debug() << imie(tree[1].big) imie(should);
		if(tree[1].big == should) {
			printf("%d\n", tree[1].cnt);
		}
		else {
			puts("0");
		}
	}
}