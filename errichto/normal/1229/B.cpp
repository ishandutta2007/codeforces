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

vector<ll> value;
vector<vector<int>> edges;
vector<ll> stos;

const int pot = 128 * 1024;
ll tree[2*pot];

const int mod = 1e9 + 7;
ll answer;

ll my_gcd(ll a, ll b) {
	debug() << ">>>>>>>>>>>" imie(a) imie(b);
	if(a == 0 || b == 0) {
		return a + b;
	}
	return __gcd(a, b);
}
#define gcd gcd_dont_use

void dfs(int a, int par) {
	int where = stos.size();
	tree[pot+where] = value[a];
	for(int i = (pot + where) / 2; i >= 1; i /= 2) {
		tree[i] = my_gcd(tree[2*i], tree[2*i+1]);
		if(tree[i] < 0) {
			debug() << imie(tree[i]) imie(tree[2*i]) imie(tree[2*i+1]);
		}
		assert(tree[i] >= 0);
	}
	stos.push_back(value[a]);
	
	ll tmp = 0;
	int v = pot + where;
	while(true) {
		int memo_v = v;
		tmp = my_gcd(tmp, tree[v]);
		while(true) {
			if(v % 2 == 1 && my_gcd(tmp, tree[v-1]) != tmp) {
				v--;
				while(v < pot) {
					if(my_gcd(tmp, tree[2*v+1]) != tmp) {
						v = 2 * v + 1;
					}
					else {
						v = 2 * v;
					}
				}
				debug() << tmp % mod * (memo_v - v);
				answer = (answer + tmp % mod * (memo_v - v)) % mod;
				tmp = my_gcd(tmp, tree[v]);
				break;
			}
			else {
				v /= 2;
				if(v == 1) {
					debug() << imie(tmp) imie(tmp % mod * (memo_v - pot + 1));
					answer = (answer + tmp % mod * (memo_v - pot + 1)) % mod;
					break;
				}
			}
		}
		if(v == 1) {
			break;
		}
		
	}
	// for(int i = (int) stos.size() - 1; i >= 0; --i) {
		// tmp = my_gcd(tmp, stos[i]);
		// answer += tmp % mod;
	// }
	for(int b : edges[a]) {
		if(b != par) {
			dfs(b, a);
		}
	}
	stos.pop_back();
}

int main() {
	int n;
	scanf("%d", &n);
	value.resize(n);
	edges.resize(n);
	for(int i = 0; i < n; ++i) {
		scanf("%lld", &value[i]);
	}
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(0, -1);
	printf("%lld\n", answer % mod);
}