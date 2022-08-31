#include<iostream>

using namespace std;

int M;
int cnt[10];
int base[10];
int mult[11];

long long dp[27000][100];

int main() {
	long long n; cin >> n;
	while(n) {
		cnt[n % 10] ++;
		n /= 10;
	}
	mult[0] = 1;
	for(int i = 0; i < 10; i++) {
		base[i] = cnt[i] + 1;
		mult[i + 1] = mult[i] * base[i];
	}
	cin >> M;
	for(int i = 1; i < 10; i++) {
		if(cnt[i]) dp[mult[i]][i % M] = 1;
	}
	for(int s = 1; s < mult[10]; s++) {
		for(int i = 0; i < 10; i++) {
			if(s / mult[i] % base[i] < cnt[i]) {
				for(int v = 0; v < M; v++) {
					dp[s + mult[i]][(10 * v + i) % M] += dp[s][v];
				}
			}
		}
	}
	cout << dp[mult[10] - 1][0] << '\n';
	return 0;
}