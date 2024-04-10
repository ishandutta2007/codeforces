#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int N;
int H[MAXN];
int L[MAXN];
int R[MAXN];
int ans[MAXN + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("547B.in", "r", stdin);
	// freopen("547B.out", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}

	stack<int> prev;
	for (int i = 0; i < N; i++) {
		while (!prev.empty() && H[prev.top()] >= H[i]) {
			prev.pop();
		}
		if (prev.empty()) {
			L[i] = -1;
		}
		else {
			L[i] = prev.top();
		}
		prev.push(i);
	}

	stack<int> after;
	for (int i = N - 1; i >= 0; i--) {
		while (!after.empty() && H[after.top()] >= H[i]) {
			after.pop();
		}
		if (after.empty()) {
			R[i] = N;
		}
		else {
			R[i] = after.top();
		}
		after.push(i);
	}

	for (int i = 0; i < N; i++) {
		int range = R[i] - L[i] - 1;
		ans[range] = max(ans[range], H[i]);
	}

	int ans2[N + 1];
	ans2[N] = ans[N];
	for (int i = N - 1; i >= 1; i--) {
		ans2[i] = max(ans2[i + 1], ans[i]);
	}

	/*
	for (int i = 0; i < N; i++) {
		cout << L[i] << ' ' << R[i] << endl;
	}
	*/

	for (int i = 1; i <= N - 1; i++) {
		cout << ans2[i] << ' ';
	}

	cout << ans2[N] << endl;
	return 0;
}