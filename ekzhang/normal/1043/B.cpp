#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 1013
int N;
int A[MAXN];
int Z[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	int pre = 0;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		A[i] = x - pre;
		pre = x;
	}

	Z[0] = N;
	int L = 0, R = 0;
	for (int i = 1; i < N; i++) {
		if (R > i)
			Z[i] = min(Z[i - L], R - i);
		while (i + Z[i] < N && A[i + Z[i]] == A[Z[i]])
			++Z[i];
		if (i + Z[i] > R)
			L = i, R = i + Z[i];
	}

	vector<int> ans;
	for (int i = 1; i < N; i++)
		if (Z[i] == N - i)
			ans.push_back(i);

	ans.push_back(N);
	cout << ans.size() << endl;
	for (int x : ans)
		cout << x << ' ';
	cout << endl;
	return 0;
}