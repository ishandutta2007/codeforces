#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e6;
int N;
int A[MAXN];

const int S = 1 << 21;
pair<int, int> rightMost[S];

void merge(pair<int, int>& a, pair<int, int> b) {
	if (a.first < b.first) swap(a, b);
	a.second = max(a.second, b.first);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	for (int v = 0; v < S; v++) {
		rightMost[v] = {-1, -1};
	}
	for (int i = 0; i < N; i++) {
		merge(rightMost[A[i]], {i, -1});
	}

	for (int l = 0; l < 21; l++) {
		for (int v = 0; v < S; v++) {
			if (v & (1 << l)) continue;
			merge(rightMost[v], rightMost[v | (1 << l)]);
		}
	}

	int ans = 0;
	for (int l = 20; l >= 0; l--) {
		int cnd = ans | (1 << l);
		bool isGood = false;
		for (int i = 0; i < N; i++) {
			if (rightMost[cnd - (cnd & A[i])].second > i) {
				isGood = true;
				break;
			}
		}
		if (isGood) {
			ans = cnd;
		}
	}
	cout << ans << '\n';

	return 0;
}