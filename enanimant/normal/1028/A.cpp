// August 26, 2018
// http://codeforces.com/contest/1028/problem/A

/*

*/


#include <bits/stdc++.h>

using namespace std;


int N, M;
char b[115][115];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG)


	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> b[i][j];
		}
	}

	bool found = false;
	pair<int, int> tl, br;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (b[i][j] == 'B') {
				tl = {i, j};
				found = true;
				break;
			}
		}
		if (found) break;
	}

	found = false;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = M - 1; j >= 0; j--) {
			if (b[i][j] == 'B') {
				br = {i, j};
				found = true;
				break;
			}
		}
		if (found) break;
	}

	cout << (tl.first + br.first) / 2 + 1 << ' ' << (tl.second + br.second) / 2 + 1 << '\n';


	return 0;
}