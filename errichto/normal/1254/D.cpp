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
void add_self(int& a, int b) {
	a += b;
	if(a >= mod) {
		a -= mod;
	}
}
int mul(int a, int b) {
	return (ll) a * b % mod;
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

const int nax = 150123;
vector<int> edges[nax];
int in[nax], out[nax], parent[nax];
bool is_big[nax];
int subtree_size[nax];
int memo_his[nax];
int which_big[nax];
int fast_size[605][nax]; // 105 -> 15'000'000 * int = 60MB

const int B = 512 * 1024;
ll tree[2 * B];
//~ ll sum(int low, int high) {
	//~ low += B;
	//~ high += B;
	//~ ll r = tree[low];
	//~ if(high != low) {
		//~ r += tree[high];
	//~ }
	//~ while(low + 1 < high) {
		//~ if(low % 2 == 0) {
			//~ r += tree[low+1];
		//~ }
		//~ if(high % 2 == 1) {
			//~ r += tree[high-1];
		//~ }
		//~ low /= 2;
		//~ high /= 2;
	//~ }
	//~ return r;
//~ }
//~ void add(int i, int d) {
	//~ for(int j = B + i; j >= 1; j /= 2) {
		//~ tree[j] += d;
	//~ }
//~ }
void add(int L, int R, int d) {
	debug() << "add" imie(L) imie(R) imie(d);
	L += B;
	R += B;
	tree[L] += d;
	if(L != R) {
		tree[R] += d;
	}
	int low = L, high = R;
	while(low + 1 < high) {
		if(low % 2 == 0) {
			tree[low+1] += d;
		}
		if(high % 2 == 1) {
			tree[high-1] += d;
		}
		low /= 2;
		high /= 2;
	}
}
ll get(int x) {
	debug() << "get" imie(x);
	ll r = 0;
	for(int i = B + x; i >= 1; i /= 2) {
		r += tree[i];
	}
	return r;
}

int T = 0;
void dfs(int a) {
	in[a] = T++;
	subtree_size[a] = 1;
	for(int b : edges[a]) {
		if(b != parent[a]) {
			parent[b] = a;
			dfs(b);
			subtree_size[a] += subtree_size[b];
		}
	}
	out[a] = T++;
}
bool is_ancestor(int a, int b) {
	return in[a] <= in[b] && out[b] <= out[a];
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(1);
	vector<int> bigs;
	for(int a = 1; a <= n; ++a) {
		if((int) edges[a].size() >= 600) {
			is_big[a] = true;
			bigs.push_back(a);
		}
	}
	assert((int) bigs.size() < 603);
	for(int i = 0; i < (int) bigs.size(); ++i) {
		which_big[bigs[i]] = i;
		for(int b : edges[bigs[i]]) {
			if(b != parent[bigs[i]]) {
				vector<int> kol{b};
				int value = n - subtree_size[b];
				for(int j = 0; j < (int) kol.size(); ++j) {
					int x = kol[j];
					fast_size[i][x] = value;
					for(int y : edges[x]) {
						if(y != parent[x]) {
							kol.push_back(y);
						}
					}
				}
			}
		}
	}
	
	//~ int sum_d = 0;
	int n_power = 1;
	int one_inv = my_inv(n);
	while(q--) {
		int type;
		scanf("%d", &type);
		if(type == 1) {
			n_power = mul(n_power, one_inv);
			int v, d;
			scanf("%d%d", &v, &d);
			add_self(memo_his[v], d);
			// increase
			if(!is_big[v]) {
				for(int b : edges[v]) {
					if(b != parent[v]) {
						add(in[b], out[b], mul(d, n - subtree_size[b]));
						debug() << imie(v) imie(b) imie(n - subtree_size[b]);
					}
				}
			}
			add(in[v], in[v], mul(d, n));
			add(0, T, mul(d, subtree_size[v]));
			add(in[v], out[v], -mul(d, subtree_size[v]));
			//~ add(in[v], d);
			//~ add_self(sum_d, d);
		}
		else {
			int v;
			scanf("%d", &v); // query
			ll answer = get(in[v]) % mod;
			//~ ll answer = mul(sum_d, n);
			//~ for(int b : edges[v]) {
				//~ if(is_ancestor(v, b)) {
					//~ answer -= (ll) subtree_size[b] * sum(in[b], out[b]);
				//~ }
			//~ }
			//~ answer -= mul(n - subtree_size[v], sum_d - sum(in[v], out[v]));
			answer = (answer % mod + mod) % mod;
			for(int big : bigs) {
				if(is_ancestor(big, v) && big != v) {
					answer += (ll) memo_his[big] * fast_size[which_big[big]][v];
				}
			}
			answer = (answer % mod + mod) % mod;
			
			answer = mul(answer, one_inv);
			printf("%lld\n", answer);
		}
	}
}