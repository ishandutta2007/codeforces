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

	int n = nxt();
	vector<int> a;
	int last = 0;
	int fst_a, lst_a;
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			last = nxt();
			fst_a = last;
		} else {
			int x = nxt();
			a.push_back(x - last);
			last = x;
		}
	}
	lst_a = last;
	vector<int> b;
	last = 0;
	int fst_b, lst_b;
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			last = nxt();
			fst_b = last;
		} else {
			int x = nxt();
			b.push_back(x - last);
			last = x;
		}
	}
	lst_b = last;
	sort(all(a));
	sort(all(b));
	cout << ((a == b && fst_a == fst_b && lst_a == lst_b) ? "Yes" : "No") << "\n";


	return 0;
}