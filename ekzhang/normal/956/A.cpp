#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 53
int N, M;
string S[MAXN];
bool used[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	sort(S, S + N);
	int K = unique(S, S + N) - S;

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < M; j++) {
			if (S[i][j] == '#') {
				if (used[j]) {
					cout << "No" << endl;
					return 0;
				}
				used[j] = true;
			}
		}
	}

	cout << "Yes" << endl;
	return 0;
}