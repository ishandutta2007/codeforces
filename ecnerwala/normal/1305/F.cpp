#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()

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
	for(auto a : A) {   // ^ count trailing zeroes
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

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<ull> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	auto primeDist = [&](ull p) -> ull {
		ull cnd = 0;
		for (int i = 0; i < N; i++) {
			if (A[i] < p) {
				cnd += p - A[i];
			} else {
				ull d = A[i] % p;
				cnd += min(d, p-d);
			}
		}
		return cnd;
	};

	mt19937 mt(48);
	shuffle(A.begin(), A.end(), mt);

	unordered_map<ull, int> cnt;
	int numSamp = min(N, 1000);
	for (int i = 0; i < numSamp; i++) {
		unordered_set<ull> pfacs;
		for (ull v : factor(A[i])) pfacs.insert(v);
		for (ull v : factor(A[i]+1)) pfacs.insert(v);
		if (A[i] > 1) for (ull v : factor(A[i]-1)) pfacs.insert(v);

		for (ull v : pfacs) cnt[v]++;
	}

	vector<pair<int, ull>> cnds; cnds.reserve(cnt.size());
	for (auto it : cnt) {
		cnds.emplace_back(it.second, it.first);
	}
	sort(cnds.begin(), cnds.end());
	reverse(cnds.begin(), cnds.end());

	ull ans = N+1;

	for (auto it : cnds) {
		if (it.first + 10 < 0.4 * numSamp) break;
		//cerr << p << ' ' << cnd << '\n';
		ans = min(ans, primeDist(it.second));
	}
	cout << ans << '\n';

	return 0;
}