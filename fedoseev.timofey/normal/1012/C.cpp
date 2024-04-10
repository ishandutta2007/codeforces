#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 6000;
const int Inf = 2e9;

int dp[N][N];
int ndp[N][N];

int get(int x, int y) {
	if (x < y) return x;
	return y - 1;
}

int count(int a, int b, int c) {
	int res = 0;
	res += a - get(a, b);
	res += c - get(c, b);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(0); cin.tie(0);
	#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	vector <int> a(n + 2);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	a[0] = -Inf;
	a[n + 1] = -Inf;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			dp[i][j] = Inf;
			ndp[i][j] = Inf;
		}
	}
	dp[0][0] = 0;
	dp[1][0] = 0;
	dp[1][1] = a[2] - get(a[2], a[1]);

	for (int i = 0; i < N; ++i) {
		ndp[i][0] = 0;
		ndp[i][1] = (i == 0 ? Inf : dp[1][1]);
	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= (n + 1) / 2; ++j) {
			if (i != 2 && j != 1) dp[i][j] = min(dp[i][j], dp[i - 2][j - 1] + count(get(a[i - 1], a[i - 2]), a[i], a[i + 1]));
			else dp[i][j] = min(dp[i][j], dp[i - 2][j - 1] + count(a[i - 1], a[i], a[i + 1]));
			if (i >= 3) dp[i][j] = min(dp[i][j], ndp[i - 3][j - 1] + count(a[i - 1], a[i], a[i + 1]));
			ndp[i][j] = min(ndp[i - 1][j], dp[i][j]);
		}
	}
	for (int i = 1; i <= (n + 1) / 2; ++i) {
		cout << ndp[n][i] << ' ';
	}
}