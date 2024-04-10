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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	int n = nxt(), m = nxt();

	int s = nxt() - 1;
	long long t;
	cin >> t;
	while (t % n) {
		if (s < m) {
			s = (s + t % n) % n;
		} else {
			s = (s - t % n + n) % n;
		}
		--t;
	}

	function<int(int, int)> get = [&](int v, int k) {
		if (k == 0) {
			return v;
		}
		if (v < m) {
			v = (v + k) % n;
		} else {
			v = (v - k + n) % n;
		}
		return get(v, k - 1);
	};

	vector<int> big(n, -1);
	vector<int> step(n, -1);
	int cur = 0;
	while (t) {
		if (big[s] > -1) {
			break;
		}
		step[s] = cur++;
		s = big[s] = get(s, n);
		t -= n;
	}

	t /= n;
	t %= cur - step[s];
	while (t) {
		s = big[s];
		t -= 1;
	}

	cout << s + 1 << "\n";

	return 0;
}