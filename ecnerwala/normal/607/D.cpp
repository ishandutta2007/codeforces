#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll inv(ll a, ll m = MOD) {
	if(a == 1) return 1;
	return m - inv(m % a, a) * m / a;
}

typedef pair<ll, ll> pii;
#define A first
#define B second

const ll MAXN = 3e5;

const ll S = 1 << 19;
ll sum[S * 2];
ll prod[S * 2];
ll lazy[S * 2];

ll N;
ll L;
ll st[MAXN], en[MAXN]; // inclusive

ll V[MAXN];
ll P[MAXN];
vector<ll> ch[MAXN];

const ll MAXQ = 3e5;
ll Q;
pii queries[MAXQ];

ll deg[MAXN];

void build_tour(ll cur) {
	st[cur] = L;
	L++;
	for(ll nxt : ch[cur]) {
		build_tour(nxt);
	}
	en[cur] = L - 1;
}

void propogate(ll a) {
	if(a < S) {
		ll l = 2 * a, r = 2 * a + 1;
		ll v = lazy[a];
		lazy[l] *= v, lazy[l] %= MOD;
		lazy[r] *= v, lazy[r] %= MOD;
		sum[l] *= v, sum[l] %= MOD;
		sum[r] *= v, sum[r] %= MOD;
		prod[l] *= v, prod[l] %= MOD;
		prod[r] *= v, prod[r] %= MOD;
	}
	lazy[a] = 1;
}

// poll query
ll get_prod(ll a) {
	a = st[a];
	a += S;
	for(ll i = S; i; i /= 2) {
		propogate(a / i);
	}
	return prod[a];
}

// poll update
void add(ll a, ll v) {
	a = st[a];
	a += S;
	for(ll i = S; i; i /= 2) {
		propogate(a / i);
	}
	for(ll i = a; i; i /= 2) {
		assert(lazy[i] == 1);
		sum[i] += v;
		sum[i] %= MOD;
	}
}

// range update
void mult(ll a, ll v) {
	ll l = st[a], r = en[a];
	l += S, r += S;
	for(ll x = l, y = r; x <= y; x /= 2, y /= 2) {
		if(x & 1) {
			lazy[x] *= v, lazy[x] %= MOD;
			prod[x] *= v, prod[x] %= MOD;
			sum[x] *= v, sum[x] %= MOD;
			for(ll i = x / 2; i; i /= 2) {
				sum[i] = (sum[2 * i] + sum[2 * i + 1]) * lazy[i] % MOD; 
			}
			x++;
		}
		if(!(y & 1)) {
			lazy[y] *= v, lazy[y] %= MOD;
			prod[y] *= v, prod[y] %= MOD;
			sum[y] *= v, sum[y] %= MOD;
			for(ll i = y / 2; i; i /= 2) {
				sum[i] = (sum[2 * i] + sum[2 * i + 1]) * lazy[i] % MOD; 
			}
			y--;
		}
	}
}

// range query
ll get_sum(ll a) {
	ll l = st[a], r = en[a]; // inclusive
	l += S, r += S;
	ll res = 0;
	for(ll x = l, y = r; x <= y; x /= 2, y /= 2) {
		if(x & 1) {
			for(ll i = S; i; i /= 2) {
				if(x >= i) propogate(x / i);
			}
			res += sum[x], res %= MOD;
			x++;
		}
		if(!(y & 1)) {
			for(ll i = S; i; i /= 2) {
				if(y >= i) propogate(y / i);
			}
			res += sum[y], res %= MOD;
			y--;
		}
	}
	res *= inv(get_prod(P[a])), res %= MOD;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);

	N = 2;
	P[0] = -1;
	V[0] = 0;
	P[1] = 0;
	ch[0].push_back(1);
	cin >> V[1];
	cin >> Q; Q++;

	queries[0] = pii(1, 1);
	for(ll i = 1; i < Q; i++) {
		ll t; cin >> t;
		if(t == 1) {
			cin >> P[N] >> V[N];
			ch[P[N]].push_back(N);
			queries[i] = pii(t, N);
			N++;
		} else if(t == 2) {
			ll u;
			cin >> u;
			queries[i] = pii(t, u);
		} else assert(false);
	}

	L = 0;
	build_tour(0);

	for(ll i = 1; i < S * 2; i++) {
		sum[i] = 0;
		prod[i] = 1;
		lazy[i] = 1;
	}

	for(ll i = 0; i < Q; i++) {
		ll t = queries[i].A;
		ll v = queries[i].B;
		if(t == 1) {
			ll p = P[v];

			deg[p] ++;
			mult(p, inv(deg[p]) * (deg[p] + 1) % MOD);

			add(v, get_prod(v) * V[v] % MOD);

		} else if(t == 2) {
			cout << get_sum(v) << '\n';
		}
	}

	return 0;
}