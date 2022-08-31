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
	while (n--) {
		string s;
		cin >> s;
		int num_even = 0;
		int num_z = 0;
		int sum_3 = 0;
		for (char c : s) {
			if (c == '0') {
				++num_z;
			}
			if ((c - '0') % 2 == 0) {
				++num_even;
			}
			sum_3 += c - '0';
		}
		puts(sum_3 % 3 == 0 && num_z && num_even >= 2 ? "red" : "cyan");
	}

	return 0;
}