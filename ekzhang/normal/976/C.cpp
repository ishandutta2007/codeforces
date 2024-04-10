#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 300013
int N;
pair<pair<int, int>, int> A[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i].first.first >> A[i].first.second;
		A[i].first.second *= -1;
		A[i].second = i;
	}

	sort(A, A + N);

	int big = 0;
	for (int i = 1; i < N; i++) {
		if (A[i].first.second >= A[big].first.second) {
			cout << A[i].second + 1 << ' ' << A[big].second + 1 << endl;
			return 0;
		}
		big = i;
	}

	cout << -1 << ' ' << -1 << endl;
	return 0;
}