#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

const int MAXN = 6e5;
int N;

ll A[MAXN];

const int MAXK = 6e3;
int K;
ll dp[MAXK];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> K;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);

	for(int i = N - 1; i > 0; i--) {
		A[i] -= A[i - 1];
	}
	A[0] = 0;

	ll S = 0;
	for(int i = 0; i < N; i++) {
		S += A[i];
	}


	memset(dp, 0, sizeof(dp));

	for(int i = 0; i < K; i++) {
		for(int j = 0; j <= i; j++) {
			dp[j] += A[N / K * i + j];
		}

		for(int j = i + 1; j >= 0; j--) {
			dp[j] = max(dp[j - 1], dp[j]);
		}
	}

	cout << S - dp[N % K] << '\n';
	return 0;
}