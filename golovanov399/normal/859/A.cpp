#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

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

bool contains(const vector<int>& a, int x) {
	auto it = lower_bound(all(a), x);
	return (it != a.end() && *it == x);
}

int main() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	sort(all(a));
	int cur = 1;
	for (int i = n; i < 25; ++i) {
		while (contains(a, cur)) {
			++cur;
		}
		a.push_back(cur);
		sort(all(a));
	}

	cout << *max_element(all(a)) - 25 << "\n";

	return 0;
}