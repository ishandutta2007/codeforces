#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

template<int p> struct FF {
	LL val;

	FF(LL x=0) { val = (x % p + p) % p; }

	bool operator==(const FF<p>& other) { return val == other.val; }
	bool operator!=(const FF<p>& other) { return val != other.val; }

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

	FF<p> pow(LL b) const { return pow(*this, b); }
	FF<p> inv() const { return pow(p - 2); }
};

template<int p> FF<p> operator+(LL lhs, const FF<p>& rhs) { return FF<p>(lhs) += rhs; }
template<int p> FF<p> operator-(LL lhs, const FF<p>& rhs) { return FF<p>(lhs) -= rhs; }
template<int p> FF<p> operator*(LL lhs, const FF<p>& rhs) { return FF<p>(lhs) *= rhs; }
template<int p> FF<p> operator/(LL lhs, const FF<p>& rhs) { return FF<p>(lhs) /= rhs; }

typedef FF<998244353> num;
const num half = 1 / num(2);

#define MAXN 500013
int N;
vector<int> adj[MAXN];
num dp[MAXN]; // probability unmatched
num ans;

void dfs(int n, int par=-1) {
	dp[n] = 1;
	for (int v : adj[n]) if (v != par) {
		dfs(v, n);
		dp[n] *= 1 - dp[v] * half;
	}
	ans += 1 - dp[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(0);

	for (int i = 0; i < N; i++)
		ans = ans * 2;

	cout << ans.val << endl;
	return 0;
}