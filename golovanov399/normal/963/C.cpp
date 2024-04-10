#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

long long dcnt(long long n) {
	long long ans = 1;
	for (long long i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			int c = 0;
			while (n % i == 0) {
				n /= i;
				++c;
			}
			ans *= c + 1;
		}
	}
	if (n > 1) {
		ans *= 2;
	}
	return ans;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<array<long long, 3>> a(n);
	vector<long long> ws, hs;
	for (int i = 0; i < n; ++i) {
		scanf("%lld%lld%lld", &a[i][0], &a[i][1], &a[i][2]);
		ws.push_back(a[i][0]);
		hs.push_back(a[i][1]);
	}

	make_unique(ws);
	make_unique(hs);
	if (1ll * ws.size() * hs.size() != n) {
		puts("0");
		return 0;
	}

	long long g = 0;
	for (const auto& v : a) {
		g = gcd(g, v[2]);
	}
	for (auto& v : a) {
		v[2] /= g;
	}

	int wsz = ws.size();
	int hsz = hs.size();
	vector<vector<long long>> cnt(wsz, vector<long long>(hsz, 0));
	for (const auto& v : a) {
		cnt[lower_bound(all(ws), v[0]) - ws.begin()][lower_bound(all(hs), v[1]) - hs.begin()] = v[2];
	}

	for (int i = 0; i < wsz; ++i) {
		for (int j = 0; j < hsz - 1; ++j) {
			if ((long double)cnt[i][j] * cnt[0][j + 1] != (long double)cnt[i][j + 1] * cnt[0][j]) {
				puts("0");
				return 0;
			}
			if (cnt[i][j] * cnt[0][j + 1] != cnt[i][j + 1] * cnt[0][j]) {
				puts("0");
				return 0;
			}
		}
	}
	for (int i = 0; i < wsz - 1; ++i) {
		for (int j = 0; j < hsz; ++j) {
			if ((long double)cnt[i][j] * cnt[i + 1][0] != (long double)cnt[i + 1][j] * cnt[i][0]) {
				puts("0");
				return 0;
			}
			if (cnt[i][j] * cnt[i + 1][0] != cnt[i + 1][j] * cnt[i][0]) {
				puts("0");
				return 0;
			}
		}
	}

	cout << dcnt(g) << "\n";

	return 0;
}