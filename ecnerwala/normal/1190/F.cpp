#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define all(x) (x).begin(), (x).end()
#define trav(a, x) for (auto& a : x)
typedef unsigned long long ull;
typedef long double ld;
ull mod_mul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(ld(a) * ld(b) / ld(M));
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull mod_pow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = mod_mul(b, b, mod), e /= 2)
		if (e & 1) ans = mod_mul(ans, b, mod);
	return ans;
}
bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return n - 2 < 2;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
		s = __builtin_ctzll(n-1), d = n >> s;
	trav(a, A) {   // ^ count trailing zeroes
		ull p = mod_pow(a, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = mod_mul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}
ull pollard(ull n) {
	auto f = [n](ull x) { return (mod_mul(x, x, n) + 1) % n; };
	if (!(n & 1)) return 2;
	for (ull i = 2;; i++) {
		ull x = i, y = f(x), p;
		while ((p = __gcd(n + y - x, n)) == 1)
			x = f(x), y = f(f(y));
		if (p != n) return p;
	}
}
vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}

ll N, M, B;
ll P, E;


void factorizeM() {
	for (ll p = 2; p * p * p <= M; p++) {
		if (M % p == 0) {
			P = p;
			E = 0;
			for (ll v = M; v % p == 0; v /= p) {
				E++;
			}
			return;
		}
	}

	ll mi = 0, ma = ll(1.1e9);
	while (ma - mi > 1) {
		ll md = (mi + ma) / 2;
		if (md * md == M) {
			P = md;
			E = 2;
			return;
		} else if (md * md < M) mi = md;
		else ma = md;
	}

	P = M;
	E = 1;
	return;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> B;
	factorizeM();
	cerr << P << ' ' << E << '\n';
	vector<ull> factors = factor(P-1);
	map<ll, ll> pfac;
	if (E > 1) pfac[P] += E-1;
	for (auto f : factors) pfac[f] ++;

	if (B % P == 0) B = 1;

	ll phi = M / P * (P-1);

	ll ord = phi;
	for (auto it : pfac) {
		while (ord % it.first == 0 && mod_pow(B, ord / it.first, M) == 1) {
			ord /= it.first;
		}
	}
	cerr << ord << '\n';

	if (phi - ord >= N) {
		// let's output everything
		ll cnt = 0;
		unordered_set<ll> ans;
		while (int(ans.size()) < N) {
			ll v = cnt++;
			if (v % P == 0) continue;
			if (mod_pow(v, ord, M) != 1 || (P == 2 && E >= 3 && ((ord >= 2 && mod_pow(v, ord/2, M) == 1) ? v%8 != 1 : v%8 != B%8))) {
				ans.insert(v);
			}
		}
		for (ll a : ans) { cout << a << ' '; } cout << '\n';
	} else {
		cout << -1 << '\n';
	}

	return 0;
}