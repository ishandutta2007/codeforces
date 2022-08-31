#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A.begin(), A.end());

	int last = 0;
	int ans = 0;
	for (int v : A) {
		int cnd = max(last+1, v-1);
		if (cnd <= v+1) {
			last = cnd;
			ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}