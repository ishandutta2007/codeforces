#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[2000];

int main() {
	dp[0] = 1;
	dp[1] = 1;
	int N; cin >> N;
	for(int i = 2; i <= N + 2; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	ll K; cin >> K;

	for(int i = 1; i <= N; i++) {
		if(K > dp[N - i]) {
			K -= dp[N - i];
			cout << i + 1 << ' ' << i << ' ';
			i++;
		} else {
			cout << i << ' ';
		}
	}

	assert(K == 1);

	cout << '\n';

	return 0;
}