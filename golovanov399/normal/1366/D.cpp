#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

const int N = 11111111;
vector<int> primes;
int erat[N];

void solve() {
	erat[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (erat[i] == 0) {
			erat[i] = i;
			primes.push_back(i);
		}
		for (int p : primes) {
			if (p > erat[i] || i * p >= N) {
				break;
			}
			erat[i * p] = p;
		}
	}
	int n = nxt();
	vector<int> d1(n, -1);
	vector<int> d2(n, -1);
	for (int i = 0; i < n; ++i) {
		int x = nxt();
		int p = erat[x];
		int y = 1;
		while (erat[x] == p) {
			x /= p;
			y *= p;
		}
		if (x > 1) {
			d1[i] = x;
			d2[i] = y;
		}
	}
	for (int x : d1) {
		cout << x << " ";
	}
	cout << "\n";
	for (int x : d2) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}