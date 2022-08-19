#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2000;
const int MAXM = 2000;
int N, M;
char G[MAXN][MAXM];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> G[i];
	for (int i = 0; i+2 < N; i++) {
		for (int j = 0; j+2 < M; j++) {
			bool good = true;
			for (int a = 0; a < 3; a++) {
				for (int b = 0; b < 3; b++) {
					if (a == 1 && b == 1) continue;
					if (G[i+a][j+b] == '.') good = false;
				}
			}
			if (!good) continue;
			for (int a = 0; a < 3; a++) {
				for (int b = 0; b < 3; b++) {
					if (a == 1 && b == 1) continue;
					G[i+a][j+b] = '@';
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (G[i][j] == '#') {
				cout << "NO\n";
				return 0;
			}
		}
	}

	cout << "YES\n";
	return 0;
}