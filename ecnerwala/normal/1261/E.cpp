#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<pair<int, int>> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A.begin(), A.end(), [&](auto a, auto b) { return min(a.first, N+1-a.first) > min(b.first, N+1-b.first); });
	vector<vector<int>> res(N+1, vector<int>(N));
	vector<pair<int, int>> bads;
	for (int i = 0; i < N+1; i++) {
		res[i][A[0].second] = (i < A[0].first);
	}
	bads.push_back({0, A[0].first});
	bads.push_back({A[0].first, N+1});
	for (int z = 1; z < N; z++) {
		{
			vector<pair<int, int>> nbads;
			for (auto it : bads) {
				if (it.second - it.first <= 1) {
					continue;
				}
				nbads.push_back(it);
			}
			bads = std::move(nbads);
		}
		int j = A[z].second;
		for (auto& it : bads) {
			if (min(A[z].first, N+1-A[z].first) <= N+1 - (it.second - it.first) + 1) {
				bool specialVal = (A[z].first <= N+1-A[z].first ? 1 : 0);
				for (int i = 0; i < N+1; i++) {
					res[i][j] = !specialVal;
				}
				int cnt = min(A[z].first, N+1-A[z].first);
				res[it.first][j] = specialVal;
				cnt--;
				for (int i = 0; cnt; i++) {
					if (it.first <= i && i < it.second) continue;
					res[i][j] = specialVal;
					cnt--;
				}
				it.first++;
				break;
			}
		}
	}

	for (int i = 0; i < int(res.size()); i++) {
		if (*max_element(res[i].begin(), res[i].end()) == 0) {
			res.erase(res.begin() + i);
			--i;
		}
	}
	cout << int(res.size()) << '\n';
	for (int i = 0; i < int(res.size()); i++) {
		for (int j = 0; j < N; j++) {
			cout << res[i][j];
		}
		cout << '\n';
	}

	return 0;
}