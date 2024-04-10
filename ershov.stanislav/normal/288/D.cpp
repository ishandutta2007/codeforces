#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>

using namespace std;

int n;
unsigned long long ans, dp[80010];
vector<int> v[80010];

void dfs(int i, int p) {
	dp[i]=1;
	unsigned long long through=0;
	for (int j=0; j<(int)v[i].size(); j++) {
		int k=v[i][j];
		if (k==p) continue;
		dfs(k, i);
		through+=dp[i]*dp[k];
		dp[i]+=dp[k];
	}
	ans-=through*(through+2*dp[i]*(n-dp[i]));
}

int main() {
	cin >> n;
	for (int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	ans=(n*(n-1LL))/2;
	ans*=ans;
	dfs(1, 0);
	cout << ans;
	return 0;
}