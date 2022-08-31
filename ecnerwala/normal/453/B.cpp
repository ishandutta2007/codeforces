#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;

typedef pair<int, int> pii;
#define A first
#define B second

const int MAXN = 105;
const int MAXA = 30;
const int MAXB = 58;

int N;
pii A[MAXN];

const int MAXV = 500;
const int P = 16;
const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

int pMask[100];

// state: current bitmask, i is the current prime
int dp[MAXN][1 << P];
int prv[MAXN][1 << P];

int B[MAXN];

int main() {

	for(int i = 1; i <= MAXB; i++) {
		pMask[i] = 0;
		for(int j = 0; j < P; j++) {
			if(i % primes[j] == 0) pMask[i] += (1 << j);
		}
		cerr << i << ' ' << pMask[i] << '\n';
	}

	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A, A + N);

	for(int i = 0; i < N - P; i++) {
		B[A[i].second] = 1;
	}

	for(int i = 0; i <= N; i++) {
		for(int m = 0; m < (1 << P); m++) {
			dp[i][m] = INF;
		}
	}
	dp[0][0] = 0;

	for(int i = 0; i < N; i++) {
		if(i < N - P) {
			dp[i + 1][0] = dp[i][0] + A[i].first - 1;
			prv[i + 1][0] = 1;
			continue;
		}
		for(int m = 0; m < (1 << P); m++) {
			if(dp[i][m] == INF) continue;
			for(int a = 1; a <= MAXA * 2; a++) {
				if(!(m & pMask[a])) {
					int val = dp[i][m] + abs(a - A[i].first);
					if(val < dp[i + 1][m | pMask[a]]) {
						prv[i + 1][m | pMask[a]] = a;
						dp[i + 1][m | pMask[a]] = val;
					}
				}
			}
		}
	}

	int res = dp[N][0];
	int ind = N, mask = 0;
	for(int m = 0; m < (1 << P); m++) {
		int v = dp[N][m];
		if(v < res) {
			res = v;
			mask = m;
		}
	}

	while(ind > 0) {
		cerr << ind << ' ' << mask << ' ' ;
		cerr << prv[ind][mask] << '\n';
		B[A[ind - 1].second] = prv[ind][mask];
		mask -= pMask[prv[ind][mask]];
		ind--;
	}

	cerr << res << '\n';
	for(int i = 0; i < N; i++) cout << B[i] <<  ' ';
	cout << '\n';
	return 0;
}