#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, P; cin >> N >> P;
	vector<int> A(N); for (auto& a : A) cin >> a;
	sort(A.begin(), A.end());
	int V = *max_element(A.begin(), A.end());

	// # of things <= i
	vector<int> pref(V + N + 1);
	for (auto a : A) pref[a]++;
	for (int i = 0; i+1 < int(pref.size()); i++) {
		pref[i+1] += pref[i];
	}

	vector<int> ans; ans.reserve(N);

	for (int x = 1; x <= V; x++) {
		bool good = true;
		for (int i = 0; i < N; i++) {
			if ((pref[x+i] - i) % P == 0) {
				good = false;
				break;
			}
		}
		if (good) {
			ans.push_back(x);
		}
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < int(ans.size()); i++) {
		if (i) cout << ' ';
		cout << ans[i];
	}
	cout << '\n';

	return 0;
}