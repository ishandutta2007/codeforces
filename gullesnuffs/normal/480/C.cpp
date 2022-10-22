#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long dp[2][5005];
long long sum[5005];
int n, a, b, k;

int main(){
	cin >> n >> a >> b >> k;
	if(a > b){
		b=n+1-b;
		a=n+1-a;
	}
	bool read=0, write=1;
	dp[write][a]=1;
	for(int i=0; i < k; ++i){
		read^=1;
		write^=1;
		sum[0]=0;
		for(int j=1; j < b; ++j)
			sum[j]=(sum[j-1]+dp[read][j])%MOD;
		for(int j=1; j < b; ++j){
			int x=1;
			int y=j+(b-j-1)/2;
			dp[write][j]=(sum[y]+sum[x-1]+MOD-dp[read][j])%MOD;
		}
	}
	long long ans=0;
	for(int i=1; i < b; ++i)
		ans=(ans+dp[write][i])%MOD;
	cout << ans << endl;
}