#include<bits/stdc++.h>
using namespace std;

typedef int ll;

const ll MOD = 1e9 + 7;

const ll INF = MOD + 100000;

const int MAXN = 6e3;
int N;
char S[MAXN];
int firstdiff[MAXN][MAXN];

ll numways[MAXN][MAXN];
ll minprts[MAXN][MAXN];

int main() {
	cin >> S;
	N = strlen(S);

	assert(S[N] < '0');

	for(int d = 1; d <= N; d++) {
		for(int j = N; j >= d; j--) {
			int i = j - d;
			if(S[i] != S[j]) firstdiff[i][j] = 0;
			else firstdiff[i][j] = firstdiff[i + 1][j + 1] + 1;
		}
	}

	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j <= N; j++) {
			numways[i][j] = 0;
			minprts[i][j] = INF;
		}
	}

	numways[0][1] = 1;
	minprts[0][1] = 1;

	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j <= N; j++) {
			if(j - i > 1) {
				numways[i][j] += numways[i][j - 1];
				numways[i][j] %= MOD;
				minprts[i][j] = min(minprts[i][j], minprts[i][j - 1]);
			}

			if(S[j] < '1') continue;

			int l = j - i;
			int d = firstdiff[i][j];
			if(d >= j - i || S[i + d] < S[j + d]) {
			} else {
				l++;
			}

			if(j + l <= N) {
				numways[j][j + l] += numways[i][j];
				numways[j][j + l] %= MOD;
				minprts[j][j + l] = min(minprts[j][j + l], minprts[i][j] + 1);
			}
		}
	}

	ll ways = 0;
	for(int i = 0; i < N; i++) {
		ways += numways[i][N];
		ways %= MOD;
	}
	cout << ways << '\n';

	ll suff = 0, exp = 1;
	ll best = INF;
	bool big = false;
	for(int i = N - 1; i >= 0; i--) {
		suff += exp * (S[i] - '0');
		if(suff >= MOD) {
			if(best < INF) {
				break;
			}
			suff -= MOD;
			big = true;
		}

		if(minprts[i][N] <= N) {

			//cerr << i << ' ' << minprts[i][N] << '\n';
			best = min(best, suff + minprts[i][N]);
			if(big) break;
		}

		exp *= 2;
		exp %= MOD;
	}

	best %= MOD;
	cout << best << '\n';

	return 0;
}