#include<bits/stdc++.h>
using namespace std;

vector<bool> query(vector<pair<int, int>> q) {
	if (q.empty()) {
		return vector<bool>();
	}
	cout << "Q" << ' ' << q.size();
	for (auto it : q) {
		cout << ' ' << it.first+1 << ' ' << it.second+1;
	}
	cout << '\n' << flush;
	string s; cin >> s;
	if (s == "-1") exit(0);
	assert(s.size() == q.size());
	vector<bool> res(q.size());
	for (int i = 0; i < int(q.size()); i++) {
		res[i] = s[i] - '0';
	}
	return res;
}

void go() {
	int N; cin >> N;
	cerr << "N " << N << '\n';
	vector<bool> isSame(N-1);
	for (int z = 0; z < 2; z++) {
		vector<pair<int, int>> q;
		for (int i = z; i < N-1; i += 2) {
			q.emplace_back(i, i + 1);
		}
		vector<bool> ans = query(q);
		for (int i = z, j = 0; i < N-1; i += 2) {
			isSame[i] = ans[j++];
		}
	}

	vector<pair<int, int>> intervals; // inclusive
	for (int i = 0; i < N; i++) {
		int j = i;
		while (j < N-1 && isSame[j]) j++;
		intervals.emplace_back(i, j);
		i = j;
	}

	int M = int(intervals.size());
	vector<bool> intIsSame(M);
	for (int z = 0; z < 2; z++) {
		vector<pair<int, int>> q;
		for (int i = 2; i < M; i++) {
			if ((i / 2) % 2 == z) {
				q.emplace_back(intervals[i-2].first, intervals[i].first);
			}
		}
		vector<bool> ans = query(q);
		for (int i = 2, j = 0; i < M; i++) {
			if ((i / 2) % 2 == z) {
				intIsSame[i] = ans[j++];
			}
		}
	}
	vector<int> color(M);
	for (int i = 0; i < M; i++) {
		if (i < 2) {
			color[i] = i;
		} else {
			if (intIsSame[i]) {
				color[i] = color[i-2];
			} else {
				color[i] = (0 + 1 + 2) - color[i-1] - color[i-2];
			}
		}
	}
	vector<int> ans[3];
	for (int i = 0; i < M; i++) {
		for (int j = intervals[i].first; j <= intervals[i].second; j++) {
			ans[color[i]].push_back(j);
		}
	}
	cout << "A" << ' ' << ans[0].size() << ' ' << ans[1].size() << ' ' << ans[2].size() << '\n';
	for (int z = 0; z < 3; z++) {
		for (int v : ans[z]) { cout << v+1 << ' '; }
		cout << '\n';
	}
	cout << flush;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		go();
	}

	return 0;
}