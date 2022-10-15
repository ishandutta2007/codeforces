#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 300013
int T, A, B;
int pre[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (int i = 1; i < MAXN; i++) {
		pre[i] = i ^ pre[i - 1];
	}

	while (T--) {
		cin >> A >> B;
		int diff = pre[A - 1] ^ B;
		int ans = (diff == 0 ? A : diff != A ? A + 1 : A + 2);
		cout << ans << '\n';
	}

	cout.flush();
	return 0;
}