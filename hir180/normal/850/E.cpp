#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define rep(i,x) for(int i=0;i<x;i++)
ll dp[(1<<20)+5][21],ret;
int n; string s;
int main(){
	cin>>n>>s;
	rep(i,1<<n)if(s[i]=='1')dp[i][0]=1;
	rep(j,n)rep(i,1<<n)dp[i][j+1]=(dp[i][j]*2LL+dp[i^(1<<j)][j])%mod;
	rep(i,1<<n)if(s[i]=='1')ret=(ret+dp[i][n]*3LL)%mod;
	cout<<ret<<endl;
}