#include <bits/stdc++.h>
using namespace std;

#define MAXN 50

int N;
bool good[MAXN][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N * N; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (!good[a][0] && !good[b][1]) {
			good[a][0] = true;
			good[b][1] = true;
			cout << i + 1 << ' ';
		}
	}

	cout << endl;
	return 0;
}