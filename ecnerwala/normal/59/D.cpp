#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	vector<int> order(3*N);
	for (int& a : order) cin >> a, a--;
	vector<int> score(3*N);
	for (int i = 0; i < 3*N; i++) score[order[i]] = i;
	vector<array<int, 3>> teams(N);
	for (auto& a : teams) for (auto& v : a) cin >> v, v--;

	vector<bool> used(3*N, false);

	vector<int> ans(3*N);

	int K; cin >> K; K--;
	for (auto& team : teams) {
		for (int v : team) used[v] = true;
		if (team[0] == K || team[1] == K || team[2] == K) {
			if (score[K] == min({score[team[0]], score[team[1]], score[team[2]]})) {
				fill(used.begin() + max({team[0] == K ? -1 : team[0], team[1] == K ? -1 : team[1], team[2] == K ? -1 : team[2]}) + 1, used.end(), false); 
				ans.clear();
				for (int i = 0; i < 3*N; i++) if (used[i]) ans.push_back(i);
				for (int i = 0; i < 3*N; i++) if (!used[i]) ans.push_back(i);
			} else {
				iota(ans.begin(), ans.end(), 0);
			}
			break;
		}
	}

	for (int a : ans) {
		if (a == K) continue;
		cout << a+1 << ' ';
	}
	cout << '\n';


	return 0;
}