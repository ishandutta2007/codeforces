#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	struct seg {
		int l, r;
		bool t;
	};
	vector<seg> S(N);
	for (auto& s : S) {
		cin >> s.l >> s.r;
		int t; cin >> t;
		s.t = t-1;
	}

	sort(S.begin(), S.end(), [&](const seg& a, const seg& b) { return a.l < b.l; });

	array<priority_queue<int, vector<int>, greater<int>>, 2> vals;
	array<int, 2> pref_val{0, 0};
	for (seg s : S) {
		for (int z = 0; z < 2; z++) {
			while (!vals[z].empty() && vals[z].top() < s.l) {
				pref_val[z]++; vals[z].pop();
			}
		}
		for (int z = 0; z < 2; z++) {
			while (pref_val[z] < pref_val[!z]) {
				pref_val[z]++;
				if (!vals[z].empty()) vals[z].pop();
			}
		}
		vals[s.t].push(s.r);
	}
	cout << max(int(vals[0].size()) + pref_val[0], int(vals[1].size()) + pref_val[1]) << '\n';

	return 0;
}