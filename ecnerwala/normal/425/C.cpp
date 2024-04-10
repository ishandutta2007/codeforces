#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

const int INF = 1e8;

const int MAXN = 2e5;
const int MAXM = 2e5;
const int MAXS = 6e5;
const int MAXE = 2e4;
const int MINE = 5e2;
const int MAXV = 2e5;

int N, M, S, E;
int A[MAXN];
int B[MAXM];

vector<int> locs[MAXV];

int dp[MAXN];

int go() {
	int maxVal = S / E;
	for(int i = 0; i < M; i++) {
		locs[B[i]].push_back(i);
	}
	memset(dp, 0, sizeof(dp));
	for(int v = 1; v <= maxVal; v++) {
		for(int i = N; i > 0; i--) {
			vector<int>::iterator it = lower_bound(locs[A[i - 1]].begin(), locs[A[i - 1]].end(), dp[i - 1]);
			if(it == locs[A[i - 1]].end()) {
				dp[i] = INF;
			} else {
				dp[i] = *it + 1;
			}
		}
		dp[0] = INF;

		for(int i = 0; i < N; i++) {
			if(dp[i] < dp[i + 1]) dp[i + 1] = dp[i];
		}

		//cerr << v << '\n';
		//for(int i = 0; i <= N; i++) {
			//cerr << i << ' ' << dp[i] << '\n';
		//}
		bool good = false;
		for(int i = 0; i <= N; i++) {
			if(dp[i] + i + v * E <= S) {
				good = true;
				break;
			}
		}
		if(!good) return v - 1;
	}
	return maxVal;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M >> S >> E;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for(int j = 0; j < M; j++) {
		cin >> B[j];
	}
	cout << go() << '\n';

	return 0;
}