#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
int N, K, B;
pair<LL, LL> A[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K >> B;
	for (int i = 0; i < N; i++)
		cin >> A[i].second >> A[i].first;

	if (B == 0) {
		LL ans = 0;
		for (int i = 0; i < N; i++) {
			ans += A[i].first;
		}
		cout << ans << endl;
		return 0;
	}

	sort(A, A + N, [](pair<LL, LL> a, pair<LL, LL> b) {
		return a.second - a.first > b.second - b.first;
	}); //desc of increase

	int p = min(B - 2, N - 1);
	while (p >= 0 && A[p].second < A[p].first)
		--p;

	LL init = 0;
	for (int i = 0; i < N; i++) {
		init += (i <= p ? A[i].second : A[i].first);
	}

	LL ans = init;
	for (int i = 0; i < N; i++) {
		LL cur = init;
		if (i <= p) {
			cur += ((1LL<<K) - 1) * A[i].second;
			if (p < N - 1 && A[p + 1].second > A[p + 1].first)
				cur += A[p + 1].second - A[p + 1].first;
		}
		else {
			LL x = (1LL<<K) * A[i].second;
			if (x > A[i].first)
				cur += x - A[i].first;
			else {
				if (p < N - 1 && A[p + 1].second > A[p + 1].first)
					cur += A[p + 1].second - A[p + 1].first;
			}
		}
		ans = max(ans, cur);
	}

	cout << ans << endl;
	return 0;
}