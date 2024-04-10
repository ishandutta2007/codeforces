#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<int64_t> pref(N+1);
	for (int i = 0; i < N; i++) {
		pref[i+1] = pref[i] + A[i];
	}
	pair<int64_t, array<int, 3>> resp(-pref[N], {0,0,0});
	for (int i = 0; i <= N; i++) {
		int a = max_element(pref.begin(), pref.begin()+i+1) - pref.begin();
		int b = max_element(pref.begin()+i, pref.end()) - pref.begin();
		resp = max(resp, {-pref[N] + 2 * pref[a] + 2 * pref[b] - 2 * pref[i], {a,i,b}});
	}
	cout << resp.second[0] << ' ' << resp.second[1] << ' ' << resp.second[2] << '\n';

	return 0;
}