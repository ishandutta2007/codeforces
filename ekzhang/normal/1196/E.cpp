#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAX 500000000
int Q;
int B, W;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> Q;
	while (Q--) {
		cin >> B >> W;
		int x = MAX, y = MAX; // current square is white which is _smaller_
		if (B < W) {
			++x;
			swap(B, W);
		}
		// B > W
		if (B > 3 * W + 1) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		vector<pair<int, int> > extra;
		extra.emplace_back(x, y - 1);
		for (int i = 0; i < W; i++) {
			extra.emplace_back(x - 1, y + 2 * i);
			extra.emplace_back(x + 1, y + 2 * i);
			cout << x << ' ' << y + 2 * i << '\n';
			cout << x << ' ' << y + 2 * i + 1 << '\n';
		}
		for (int i = 0; i < B - W; i++) {
			cout << extra[i].first << ' ' << extra[i].second << '\n';
		}
	}

	cout.flush();
	return 0;
}