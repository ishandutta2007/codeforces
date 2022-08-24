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
	// scanf("%d", &x);
	cin >> x;
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	long long a[3];
	generate(a, a + 3, nxt);
	cout << "First" << endl;

	auto prze = [&](long long y) {
		cout << y << endl;
		int idx = nxt() - 1;
		if (idx == -1) {
			exit(0);
		}
		a[idx] += y;
	};

	prze(1e10);
	prze(*max_element(a, a + 3) * 3 - accumulate(a, a + 3, 0ll));
	prze((*max_element(a, a + 3) - *min_element(a, a + 3)) / 2);
	assert(false);

	return 0;
}