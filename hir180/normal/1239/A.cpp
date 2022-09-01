#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
typedef long long ll;
const ll mod = 1000000007;
int n,m;
ll dp[100005];

int main(){
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3;i<=100000;i++) dp[i] = (dp[i-1]+dp[i-2])%mod;
	cin >> n >> m;
	ll ans = dp[n]*2LL+dp[m]*2LL-2LL;
	cout << (ans%mod+mod)%mod << endl;
}