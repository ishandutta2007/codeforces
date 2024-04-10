#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	const int L = 20;
	vector<int> cnt(L);
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		for (int v = 0; v < 20; v++) {
			if (a & (1<<v)) cnt[v]++;
		}
	}
	int64_t ans = 0;
	for (int i = 0; i < N; i++) {
		int a = 0;
		for (int v = 0; v < 20; v++) {
			if (i < cnt[v]) a |= (1 << v);
		}
		ans += int64_t(a) * int64_t(a);
	}
	cout << ans << '\n';

	return 0;
}