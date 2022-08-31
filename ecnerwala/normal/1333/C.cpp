#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	int64_t pref = 0;
	unordered_map<int64_t, int> lastInd;
	int64_t ans = 0;
	int ind = 0;
	for (int i = 0; i < N; i++) {
		lastInd[pref] = i+1;
		int a; cin >> a;
		pref += a;
		ind = max(ind, lastInd[pref]);
		ans += (i+1 - ind);
	}
	cout << ans << '\n';

	return 0;
}