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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	long long n;
	cin >> n;
	vector<int> d;
	while (n) {
		d.push_back(n % 10);
		n /= 10;
	}
	int i = 0;
	while (i < (int)d.size() && d[i] == 9) {
		++i;
	}
	while (i < (int)d.size() - 1) {
		d[i] += 10;
		d[i + 1] -= 1;
		++i;
	}
	cout << accumulate(all(d), 0) << "\n";

	return 0;
}