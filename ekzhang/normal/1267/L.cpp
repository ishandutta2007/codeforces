#include <bits/stdc++.h>
using namespace std;

#define MAXN 1013
#define MAXL 1013
int N, L, K;
string S;
char ans[MAXN][MAXL];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> L >> K;
	cin >> S;
	sort(S.begin(), S.end());

	int inde = K * L;
	int s = 0; // [s, K)
	int idx = 0; // index in S

	for (int i = 0; i < L; i++) {
		int last = s;
		for (int j = s; j < K; j++) {
			ans[j][i] = S[idx++];
			if (j > s && ans[j][i] != ans[j - 1][i])
				last = j;
		}
		s = last;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < L; j++) {
			if (!ans[i][j])
				ans[i][j] = S[idx++];
		}
	}

	assert(idx == N * L);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < L; j++)
			cout << ans[i][j];
		cout << '\n';
	}

	cout.flush();
	return 0;
}