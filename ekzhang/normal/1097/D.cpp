#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MOD 1000000007
template<int p> struct FF {
	LL val;

	FF(const LL x=0) { val = (x % p + p) % p; }

	bool operator==(const FF<p>& other) const { return val == other.val; }
	bool operator!=(const FF<p>& other) const { return val != other.val; }

	FF operator+() const { return val; }
	FF operator-() const { return -val; }

	FF& operator+=(const FF<p>& other) { val = (val + other.val) % p; return *this; }
	FF& operator-=(const FF<p>& other) { *this += -other; return *this; }
	FF& operator*=(const FF<p>& other) { val = (val * other.val) % p; return *this; }
	FF& operator/=(const FF<p>& other) { *this *= other.inv(); return *this; }

	FF operator+(const FF<p>& other) const { return FF(*this) += other; }
	FF operator-(const FF<p>& other) const { return FF(*this) -= other; }
	FF operator*(const FF<p>& other) const { return FF(*this) *= other; }
	FF operator/(const FF<p>& other) const { return FF(*this) /= other; }

	static FF<p> pow(const FF<p>& a, LL b) {
		if (!b) return 1;
		return pow(a * a, b >> 1) * (b & 1 ? a : 1);
	}

	FF<p> pow(const LL b) const { return pow(*this, b); }
	FF<p> inv() const { return pow(p - 2); }
};

template<int p> FF<p> operator+(const LL lhs, const FF<p>& rhs) { return FF<p>(lhs) += rhs; }
template<int p> FF<p> operator-(const LL lhs, const FF<p>& rhs) { return FF<p>(lhs) -= rhs; }
template<int p> FF<p> operator*(const LL lhs, const FF<p>& rhs) { return FF<p>(lhs) *= rhs; }
template<int p> FF<p> operator/(const LL lhs, const FF<p>& rhs) { return FF<p>(lhs) /= rhs; }

typedef FF<MOD> num;

LL N;
int K;
num ans = 1;

void check(LL p) {
	int j = 0;
	while (N % p == 0)
		N /= p, j++;
	vector<num> prob(j + 1);
	prob[j] = 1;
	for (int k = 0; k < K; k++) {
		num cum = 0;
		for (int i = j; i >= 0; i--) {
			cum += prob[i] / (i + 1);
			prob[i] = cum;
		}
	}
	num total = 0;
	for (int i = j; i >= 0; i--) {
		total *= p;
		total += prob[i];
	}
	ans *= total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	if (N % 2 == 0)
		check(2);
	for (LL p = 3; p * p <= N; p += 2) {
		if (N % p == 0) {
			check(p);
		}
	}

	if (N != 1)
		check(N);

	cout << ans.val << endl;
	return 0;
}