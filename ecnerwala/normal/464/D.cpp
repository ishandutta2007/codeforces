#include<bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld EPS = 1e-100;

const int MAXN = 1e5 + 200;
const int MAXK = 200;

int N, K;

ld dp[MAXN]; // probability that on the kth roll, this item is level a
ld ndp[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> K;
	dp[1] = 1;
	for(int i = 2; i <= N + 20; i++) {
		dp[i] = 0;
		ndp[i] = 0;
	}
	ld res = 0;
	int a = 1, b = 1;
	for(int i = 1; i <= N; i++) {
		for(int l = a; l <= b; l++) {
			ndp[l + 1] = dp[l] / K / (l + 1);
			ndp[l] += dp[l] - ndp[l + 1];
			res += (dp[l] / K) * (l + 2) / 2;
			res -= ndp[l + 1]; // we only get l if we level up
		}
		for(int l = a; l <= b + 1; l++) {
			dp[l] = ndp[l];
			ndp[l] = 0;
		}
		b++;
		while(dp[a] <= EPS) a++;
		while(dp[b] <= EPS) b--;
	}
	res *= K;
	cout << fixed << setprecision(10) << res << '\n';
	return 0;
}