#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2.1e5;
int N;
char S[MAXN];

const int MAXM = 2.1e5;
int M;
char T[MAXM];

int loc[2][MAXM];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> S >> T;
	N = int(strlen(S));
	M = int(strlen(T));

	for (int z = 0; z < 2; z++) {
		loc[z][0] = 0;
		for (int i = 0, j = 0; j < M; i++, j++) {
			while (S[i] != T[j]) i++;
			loc[z][j+1] = i+1;
		}
		reverse(S, S + N);
		reverse(T, T + M);
	}
	int ans = 0;
	for (int i = 0; i <= M; i++) {
		ans = max(ans, N - loc[0][i] - loc[1][M-i]);
	}
	cout << ans << '\n';

	return 0;
}