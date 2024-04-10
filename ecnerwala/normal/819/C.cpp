#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXV = 2e6;
bool is_prime[MAXV];
int prime_facs[MAXV];

typedef map<ll, ll> mp;

ll exp(ll p, ll e) {
	ll q = 1;
	for (int i = 0; i < e; i++) q *= p;
	return q;
}

void pf(ll i, mp& res) {
	while (i > 1) {
		ll p = prime_facs[i];
		ll cnt = 0;
		while (i % p == 0) {
			i /= p;
			cnt ++;
		}
		res[p] += cnt;
	}
}

ll count_not(ll a, mp b) {
	vector<ll> facs;
	facs.clear();
	for (auto it : b) {
		ll p = it.first, e = it.second;
		ll q = exp(p, e);
		facs.push_back(q);
	}
	int L = int(facs.size());
	assert(L <= 20);
	ll res = 0;
	for (int msk = 0; msk < (1 << L); msk++) {
		ll v = a;
		int parity = 0;
		for (int i = 0; i < L; i++) {
			if (msk & (1ll << i)) {
				v /= facs[i];
				parity ^= 1;
			}
		}
		if (parity) res -= v;
		else res += v;
	}
	return res;
}

pair<ll, mp> input() {
	ll n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	ll n = ll(n1) * ll(n2) * ll(n3);
	mp nf;
	pf(n1, nf);
	pf(n2, nf);
	pf(n3, nf);
	return pair<ll, mp>(n, nf);
}

ll factors(ll limit, mp &m) {
	vector<ll> res;
	if (limit) res.push_back(1);
	for (auto it : m) {
		ll p = it.first, e = it.second;
		int len = int(res.size());
		ll q = 1;
		for (ll v = 1; v <= e; v++) {
			q *= p;
			for (int i = 0; i < len; i++) {
				ll val = res[i] * q;
				if (val <= limit) {
					res.push_back(val);
				}
			}
		}
	}
	return res.size();
}


ll go() {
	pair<ll, mp> n, m, s;
	n = input();
	m = input();
	s = input();
	s.first *= 2;
	s.second[2] ++;
	// part 1: (1..m, n) not fac of s
	mp avoid;
	for (auto it : n.second) {
		ll p = it.first, e = it.second;
		if (e > s.second[p]) avoid[p] = s.second[p] + 1;
	}
	ll res = count_not(m.first, avoid);
	res += factors(n.first, s.second);
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);

	prime_facs[0] = 0;
	prime_facs[1] = 1;
	for (int i = 2; i < MAXV; i++) is_prime[i] = true;
	for (int i = 2; i < MAXV; i++) {
		if (!is_prime[i]) continue;
		for (int j = i; j < MAXV; j += i) {
			is_prime[j] = false;
			prime_facs[j] = i;
		}
		is_prime[i] = true;
	}

	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		ll res = go();
		cout << res << '\n';
	}

	return 0;
}