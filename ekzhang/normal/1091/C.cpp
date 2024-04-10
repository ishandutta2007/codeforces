#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int N;
vector<int> divisors;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int k = 1; k * k <= N; k++) {
		if (N % k == 0)
			divisors.push_back(k);
	}

	for (int i = divisors.size() - 1; i >= 0; i--) {
		if (divisors[i] * divisors[i] != N)
			divisors.push_back(N / divisors[i]);
	}

	for (LL d : divisors) {
		cout << (d + N * (d - 1) / 2) << ' ';
	}

	cout << endl;
	return 0;
}