#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
int T;
int N;
int A[MAXN];

void solve() {
	// max after min
	map<int, int> m;
	// we want a subarray sum >= 1
	for (int i = 0; i < N; i++) {
		int x = A[i] - i;
		auto it = m.lower_bound(x);
		if (it != m.begin()) {
			int j = (--it)->second;
			cout << "YES\n";
			cout << j + 1 << ' ' << i + 1;
			cout << '\n';
			return;
		}
		m[x] = i;
	}

	// min after max
	m.clear();
	// we want a subarray sum >= 1
	for (int i = N - 1; i >= 0; i--) {
		int x = A[i] + i;
		auto it = m.lower_bound(x);
		if (it != m.begin()) {
			int j = (--it)->second;
			cout << "YES\n";
			cout << i + 1 << ' ' << j + 1;
			cout << '\n';
			return;
		}
		m[x] = i;
	}

	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> A[i];

		solve();
	}

	cout.flush();
	return 0;
}