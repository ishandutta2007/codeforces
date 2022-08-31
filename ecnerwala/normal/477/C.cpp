#include<bits/stdc++.h>
using namespace std;

const int INF = 1e8;

const int MAXN = 4000;
const int MAXM = 1000;

int N;
char S[MAXN];

int M;
char P[MAXM];

int en[MAXN];

int dp[MAXN][MAXN]; // in the first a, min cost to get k occurrences:w

int main() {
	cin >> S >> P;
	N = strlen(S), M = strlen(P);

	for(int i = 0; i < N; i++) {
		en[i] = i;
		for(int k = 0; k < M; ) {
			if(en[i] == N) {
				en[i] ++;
				break;
			} else if(S[en[i]] != P[k]) {
				en[i] ++;
			} else {
				k++;
				en[i] ++;
			}
		}
	}

	for(int i = 0; i <= N; i++) {
		for(int j = 0; j <= N; j++) {
			dp[i][j] = INF;
		}
	}

	dp[0][0] = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j <= N; j++) {
			if(dp[i][j] == INF) continue;
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			if(en[i] <= N) {
				dp[en[i]][j + 1] = min(dp[en[i]][j + 1], dp[i][j] + ((en[i] - i) - M));
			}
		}
	}

	int num = 0;
	for(int i = 0; i <= N; i++) {
		while(num + 1 <= N && dp[N][num + 1] <= i) num++;
		cout << min(num, (N - i) / M) << '\n';
	}

	return 0;
}