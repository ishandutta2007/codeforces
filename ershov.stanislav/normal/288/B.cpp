#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

const int mod=1e9+7;

int dp[11], c[11][11];

int main() {
	int n, k;
	cin >> n >> k;
	long long ans=1;
	for (int i=0; i<n-k; i++) ans*=n-k, ans%=mod;
	dp[1]=1;
	dp[0]=1;
	c[0][0]=1;
	for (int i=1; i<11; i++) {
		c[i][0]=1;
		for (int j=1; j<=i; j++) c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
	for (int i=2; i<=k-1; i++) {
		for (int j=0; j<=i-1; j++) dp[i]+=dp[j]*(i-j)*c[i-1][j]*dp[i-j-1];
	}
	ans*=dp[k-1]*k;
	ans%=mod;
	cout << ans;
	return 0;
}