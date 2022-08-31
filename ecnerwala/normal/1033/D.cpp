#include<bits/stdc++.h>
using namespace std;

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");

private:
	using ll = long long;

	int v;

	static int minv(int a, int m) {
		a %= m;
		assert(a);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}

public:

	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}

	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}

	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
using num = modnum<998244353>;

using ll = long long;
using ld = long double;

const int MAXN = 600;
int N;

// 3 and 5 divisors:
// A = p^2 (3)
// A = p^3 (4)
// A = p^4 (5)
// A = p * q (4)
// NOT A = p^2 * q (6)
// NOT A = p * q * r (8)

map<ll, ll> primes;
// always relatively prime, and rel prime to primes
vector<pair<ll, ll>> semiprimes;

void addPrime(ll p, ll c) {
	primes[p] += c;
	for (int i = 0; i < int(semiprimes.size()); i++) {
		ll s = semiprimes[i].first;
		if (s % p == 0) {
			ll q = s / p;
			assert(q > 1);
			assert(q != p);
			assert(!primes.count(q));

			// relatively prime, so we don't have to keep searching
			primes[p] += semiprimes[i].second;
			primes[q] += semiprimes[i].second;

			semiprimes.erase(semiprimes.begin() + i);
			break;
		}
	}
}

void addSemiPrime(ll s) {
	for (const auto& it : primes) {
		ll p = it.first;
		if (s % p == 0) {
			ll q = s / p;
			assert(q != p);
			addPrime(p, 1);
			addPrime(q, 1);
			return;
		}
	}

	for (pair<ll, ll>& v : semiprimes) {
		if (s == v.first) {
			v.second++;
			return;
		}
		ll g = __gcd(s, v.first);
		if (g == 1) continue;
		assert(g < s);
		ll p = g;
		ll q = s / g;
		addPrime(p, 1);
		addPrime(q, 1);
		return;
	}

	semiprimes.emplace_back(s, 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		ll a; cin >> a;
		{
			ll r4 = ll(pow(ld(a), ld(1) / ld(4)));
			while (r4 * r4 * r4 * r4 < a) {
				r4 ++;
			}
			while (r4 * r4 * r4 * r4 > a) {
				r4 --;
			}
			if (r4 * r4 * r4 * r4 == a) {
				addPrime(r4, 4);
				continue;
			}
		}
		{
			ll r3 = ll(pow(ld(a), ld(1) / ld(3)));
			while (r3 * r3 * r3 < a) {
				r3 ++;
			}
			while (r3 * r3 * r3 > a) {
				r3 --;
			}
			if (r3 * r3 * r3 == a) {
				addPrime(r3, 3);
				continue;
			}
		}
		{
			ll r2 = ll(pow(ld(a), ld(1) / ld(2)));
			while (r2 * r2 < a) {
				r2 ++;
			}
			while (r2 * r2 > a) {
				r2 --;
			}
			if (r2 * r2 == a) {
				addPrime(r2, 2);
				continue;
			}
		}

		addSemiPrime(a);
	}

	num res = 1;
	for (auto& it : primes) {
		res *= num(it.second + 1);
	}
	for (auto& it : semiprimes) {
		res *= num(it.second + 1);
		res *= num(it.second + 1);
	}
	cout << res << '\n';

	return 0;
}