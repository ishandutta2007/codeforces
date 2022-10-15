#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int N, K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	if (N >= 3 * K) {
		string ans(N, '0');
		for (int i = K; i < N; i += K) {
			ans[i] = '1';
		}
		cout << ans << endl;
	}
	else {
		int p = (N - K) / 2 + 1;
		string ans(N, '0');
		for (int i = 0; i < N; i += p)
			ans[i] = '1';
		cout << ans << endl;
	}

	cout.flush();
	return 0;
}