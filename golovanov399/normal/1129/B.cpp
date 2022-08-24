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

long long findAnswer(const vector<int>& a) {
	long long res = 0, cur = 0;
	int k = -1;
	for (int i = 0; i < (int)a.size(); ++i) {
		cur += a[i];
		if (cur < 0) {
			cur = 0;
			k = i;
		}
		res = max(res, 1ll * (i - k) * cur);
	}
	return res;
}

long long findReal(const vector<int>& a) {
	int n = a.size();
	vector<long long> pref(n + 1);
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i] + a[i];
	}
	long long res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			res = max(res, (i - j) * (pref[i] - pref[j]));
		}
	}
	// for (int i = 1; i <= n; ++i) {
	// 	for (int j = 0; j < i; ++j) {
	// 		if (res == (i - j) * (pref[i] - pref[j])) {
	// 			cout << j << " " << i << "\n";
	// 			return res;
	// 		}
	// 	}
	// }
	return res;
}

void solveStupid(int k) {
	const int n = 1999;

	int s = (k + 1000) / 1000;
	while ((2999 * 1ll * s - k) % n) {
		++s;
	}
	int m = (2999 * 1ll * s - k) / n;
	vector<int> ans(n);
	for (int i = 0; i < n / 2; ++i) {
		ans[i] = s / (n / 2) + (i < s % (n / 2));
		ans[n / 2 + 1 + i] = ans[i];
	}
	ans[n / 2] = -m;

	// cerr << findReal(ans) << " " << 1ll * n * accumulate(all(ans), 0ll) << "\n";
	// assert(findAnswer(ans) + k == findReal(ans));
	cout << n << "\n";
	for (int x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	const int k = 665;

	int K = nxt();
	if (K < 10000000) {
		solveStupid(K);
		return 0;
	}

	int t = K % 2;
	if (t) {
		K += k;
	}
	int s = K / (2 * k + 2) + 1;
	while ((8ll * k * s + 6 * s - K) % (2 * (3 * k + 2))) {
		++s;
	}
	int m = (8ll * k * s + 6 * s - K) / (2 * (3 * k + 2));
	// assert(m > s);
	vector<int> ans(3 * k + 2);
	for (int i = 0; i < k; ++i) {
		ans[i] = s / k + (i < s % k);
		ans[i + k + 1] = ans[i + 2 * k + 2] = ans[i];
	}
	ans[k] = ans[2 * k + 1] = -m;
	ans[k - 1] -= t;
	ans[2 * k + 2] += t;
	if (t) {
		K -= k;
	}

	int n = ans.size();
	// cerr << findReal(ans) << " " << 1ll * n * accumulate(all(ans), 0ll) << " " << (3 * s - 2 * m) * 1ll * n << "\n";
	// cerr << findAnswer(ans) + K << " " << findReal(ans) << "\n";
	cout << n << "\n";
	for (int x : ans) {
		cout << x << " ";
	}
	cout << "\n";
	// assert(findAnswer(ans) + K == findReal(ans));

	return 0;
}