#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int N;
LL X, Y;
string S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> X >> Y >> S;

	bool blk = false;
	int num = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '0') {
			if (!blk) {
				blk = true;
				num++;
			}
		}
		else blk = false;
	}

	LL ans = 0;
	if (num) {
		ans += Y;
		ans += min(X, Y) * (num - 1);
	}

	cout << ans << endl;
	return 0;
}