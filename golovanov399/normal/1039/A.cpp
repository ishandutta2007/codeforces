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

void panic() {
	cout << "No\n";
	exit(0);
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(0);

	int n;
	long long t;
	cin >> n >> t;
	vector<long long> a(n);
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] += t;
	}
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		--x[i];
		if (x[i] < i) {
			panic();
		}
	}

	if (!is_sorted(all(x))) {
		panic();
	}

	vector<long long> b = a;
	vector<int> counter(n);
	for (int i = 0; i < n; ++i) {
		counter[i] += 1;
		counter[x[i]] -= 1;
	}
	for (int i = 1; i < n; ++i) {
		counter[i] += counter[i - 1];
	}
	for (int i = 0; i < n - 1; ++i) {
		if (counter[i]) {
			b[i] = max(b[i], a[i + 1]);
		}
	}

	for (int i = 1; i < n; ++i) {
		b[i] = max(b[i], b[i - 1] + 1);
	}

	for (int i = 0; i < n; ++i) {
		if (x[i] < n - 1 && counter[x[i]]) {
			panic();
		}
		if (x[i] < n - 1 && a[x[i] + 1] <= b[x[i]]) {
			panic();
		}
	}

	cout << "Yes\n";
	for (auto x : b) {
		cout << x << " ";
	}
	cout << "\n";

	return 0;
}