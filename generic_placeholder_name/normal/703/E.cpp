#include <bits/stdc++.h>
using namespace std;

// 10^12 => 6720

template<class T1, class T2>
void chmin(T1 &a, T2 b) {
	if (b < a) a = b;
}

long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}

vector<long long> divisors(long long n) {
	vector<long long> ds;
	for (long long i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ds.push_back(i);
			if (n / i != i) ds.push_back(n / i);
		}
	}
	sort(ds.begin(), ds.end());
	return ds;
}

int main() {
	int n;
	long long K;
	cin >> n >> K;

	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	if (K == 1) {
		cout << 1 << endl;
		cout << min_element(a.begin(), a.end()) - a.begin() + 1 << endl;
		return 0;
	}

	vector<int> small(1e6 + 10), large(1e6 + 10);
	vector<long long> ds = divisors(K);
	int m = ds.size();
	for (int i = 0; i < m; i++) {
		if (ds[i] <= K / ds[i]) {
			small[ds[i]] = i;
		} else {
			large[K / ds[i]] = i;
		}
	}

	typedef pair<int, long long> Val;
	typedef pair<int, int> Prev;
	static pair<Val, Prev> dp[1010][7000];
	fill_n(*dp, 1010 * 7000, make_pair(Val(1e8, 1e17), Prev(-1, -1)));
	dp[0][0] = make_pair(Val(0, 0), Prev(-1, -1));

	for (int i = 0; i < n; i++) {
		long long A = gcd(a[i], K);
		for (int j = 0; j < m; j++) if (dp[i][j].first.first < n) {
			long long g = A * gcd(ds[j], K / A);
			int nj = g <= K / g ? small[g] : large[K / g];
			chmin(dp[i + 1][j], dp[i][j]);
			chmin(dp[i + 1][nj], make_pair(Val(dp[i][j].first.first + 1, dp[i][j].first.second + a[i]), Prev(i, j)));
		}
	}

	if (dp[n][m - 1].second.first == -1) {
		cout << -1 << endl;
		return 0;
	}

	vector<int> ans;
	pair<int, int> p = dp[n][m - 1].second;
	while (p.first != -1) {
		ans.push_back(p.first);
		p = dp[p.first][p.second].second;
	}

	cout << ans.size() << endl;
	for (int x : ans) cout << x + 1 << " ";
	cout << endl;
}