#include <bits/stdc++.h>

using namespace std;

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt(), r = nxt();
	vector<int> x(n);
	vector<double> y(n);
	cout << setprecision(10) << fixed;
	for (int i = 0; i < n; ++i) {
		x[i] = nxt();
		y[i] = r;
		for (int j = 0; j < i; ++j) {
			if (abs(x[i] - x[j]) > 2 * r) {
				continue;
			}
			y[i] = max(y[i], y[j] + sqrt(4 * r * r - (x[i] - x[j]) * (x[i] - x[j])));
		}
		cout << y[i] << " ";
	}
	cout << "\n";

	return 0;
}