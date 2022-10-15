#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

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

typedef FF<998244353> num;

#define MAXN 5013
int N;
int cnt[MAXN];
num fact[MAXN];
num ss[MAXN][MAXN]; // k-th symmetric sum
int cur = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		++cnt[x];
	}

	fact[0] = 1;
	for (int i = 1; i <= N; i++)
		fact[i] = i * fact[i - 1];

	ss[0][0] = 1;
	num ans = 0;
	for (int x = 1; x <= N; x++) {
		if (cnt[x]) {
			if (cnt[x] >= 2) {
				// ok win!
				num delt = 0;
				for (int k = 0; k <= cur; k++)
					delt += ss[cur][k] * fact[N - 2 - k];
				delt *= cnt[x] * (cnt[x] - 1);
				ans += delt;
			}
			// +positive number of occurrences
			ss[cur + 1][0] = 1;
			for (int k = 1; k <= cur + 1; k++)
				ss[cur + 1][k] = ss[cur][k] + cnt[x] * ss[cur][k - 1];
			++cur;
		}
	}

	cout << (ans / fact[N]).val << endl;
	return 0;
}