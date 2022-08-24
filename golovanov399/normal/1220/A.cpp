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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	string s;
	cin >> s;
	int num_zs = 0;
	int num_ones = 0;
	for (char c : s) {
		if (c == 'z') {
			++num_zs;
		}
		if (c == 'n') {
			++num_ones;
		}
	}
	for (int i = 0; i < num_ones; ++i) {
		printf("1 ");
	}
	for (int i = 0; i < num_zs; ++i) {
		printf("0 ");
	}
	printf("\n");

	return 0;
}