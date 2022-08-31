#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<string> is_connected(N);
		for (int i = 0; i < N; i++) {
			cin >> is_connected[i];
		}

		std::vector<int> stk; stk.reserve(N-1);
		for (int i = N-2; i >= 0; i--) {
			stk.push_back(i);
			for (int j = i+1; j < N; j++) {
				if (is_connected[i][j-i] == '1') {
					// j > stk.back()
					cout << i+1 << ' ' << j+1 << '\n';
					stk.pop_back();
					if (!stk.empty() && stk.back() < j) {
						cout << stk.back()+1 << ' ' << j+1 << '\n';
						stk.pop_back();
						assert(!stk.empty() && stk.back() < j);
						while (!stk.empty() && stk.back() < j) {
							cout << i+1 << ' ' << stk.back()+1 << '\n';
							stk.pop_back();
						}
					}

					if (stk.empty()) break;
					j = std::max(j, stk.back());
				}
			}
		}
	}

	return 0;
}