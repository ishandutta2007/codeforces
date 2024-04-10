#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 503
int N, K;
bool B[MAXN];

pair<int, int> query() {
	cout << '?';
	for (int i = 0; i < N; i++) {
		if (B[i])
			cout << ' ' << i + 1;
	}
	cout << endl;
	int p, x;
	cin >> p >> x;
	return {p - 1, x};
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	for (int i = 0; i < K; i++)
		B[i] = true;

	pair<int, int> p = query();
	int yi = p.first, y = p.second;

	B[yi] = false;
	B[K] = true;

	p = query();
	bool gt = p.second > y;

	B[yi] = true;
	int o = 0;
	for (int i = 0; i < K; i++) {
		if (i != yi) {
			B[i] = false;
			if (query().second == y) {
				// med did not change
				++o;
			}
			B[i] = true;
		}
	}

	int ans = K - o;
	if (!gt) ans = o + 1;

	cout << "! " << ans << endl;
	return 0;
}