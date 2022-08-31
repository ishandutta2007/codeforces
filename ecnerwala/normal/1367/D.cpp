#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int Q; cin >> Q;
	while (Q--) {
		string S; cin >> S;
		map<char, int, std::greater<>> Scnt;
		for (char c : S) Scnt[c]++;

		int M; cin >> M;
		vector<int> B(M); for(auto& b : B) cin >> b;

		vector<int> alive(M); iota(alive.begin(), alive.end(), 0);

		string T(M, '*');

		while (!alive.empty()) {
			vector<int> nalive;
			vector<int> to_kill;
			for (int i : alive) {
				if (B[i]) {
					nalive.push_back(i);
				} else {
					to_kill.push_back(i);
				}
			}
			int v = int(to_kill.size());
			while (Scnt.begin()->second < v) Scnt.erase(Scnt.begin());
			char c = Scnt.begin()->first; Scnt.erase(Scnt.begin());
			for (int i : to_kill) {
				T[i] = c;
				for (int j : nalive) {
					B[j] -= abs(i-j);
				}
			}
			alive = std::move(nalive);
		}

		cout << T << '\n';
	}

	return 0;
}