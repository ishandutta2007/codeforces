#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

bool check(const vector<int>& a) {
	int n = a.size();
	assert(n % 2 == 0);
	n /= 2;
	vector<long long> p(2 * n + 1);
	for (int i = 0; i < 2 * n; ++i) {
		p[i + 1] = p[i] + a[i];
	}
	long long s = p[2 * n];
	for (int i = 0; i < n; ++i) {
		long long t = p[i + n] - p[i];
		if (abs(t - (s - t)) > 1) {
			return false;
		}
	}
	return true;
}

vector<int> solve(int n) {
	vector<int> ans(n + n);
	if (n % 2 == 1) {
		for (int i = 0; i < n; ++i) {
			ans[2 * i] = 2 * i + 1;
			ans[(2 * i + n) % (2 * n)] = 2 * i + 2;
		}
	} else {
		return {};
	}
	return ans;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	auto ans = solve(nxt());
	if (ans.empty()) {
		puts("NO");
	} else {
		printf("YES\n");
		for (int x : ans) {
			printf("%d ", x);
		}
		printf("\n");
	}

	return 0;
}