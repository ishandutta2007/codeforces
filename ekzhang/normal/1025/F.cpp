#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 2013
int N;
int X[MAXN], Y[MAXN];
LL ans = 0;

void solve(int p1) {
	vector<double> ng;
	for (int i = 0; i < N; i++) if (i != p1) {
		ng.push_back(atan2(Y[i] - Y[p1], X[i] - X[p1]) + PI);
	}
	sort(ng.begin(), ng.end());

	for (int i = 0; i < N - 1; i++) {
		ng.push_back(ng[i] + 2 * PI);
	}

	int t = 0;
	for (int i = 0; i < N - 1; i++) {
		while (ng[t] < ng[i] + PI)
			++t;
		LL num1 = t - i - 1;
		LL num2 = N - 2 - num1;
		ans += num2 * (num2 - 1) * num1 * (num1 - 1) / 4;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
	}

	for (int i = 0; i < N; i++) {
		solve(i);
	}

	cout << ans / 2 << endl;
	return 0;
}