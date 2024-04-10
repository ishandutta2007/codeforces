#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXA = 2e5;
const int MAXN = 2e5;

int N;
ll A[MAXN];
ll cnt[MAXA];

ll dp[MAXA];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = 0; i < N; i++) {
		cnt[A[i]] ++;
	}
	dp[0] = 0;
	dp[1] = cnt[1];
	for(ll i = 2; i < MAXA; i++) {
		dp[i] = max(i * cnt[i] + dp[i - 2], dp[i - 1]);
	}
	cout << dp[MAXA - 1] << '\n';
	return 0;
}