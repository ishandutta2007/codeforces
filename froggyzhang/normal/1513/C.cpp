#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int mod=1e9+7;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,dp[N][10];
int main(){
	for(int i=0;i<=200000;++i){
		for(int c=0;c<10;++c){
			if(c+i<10)dp[i][c]=1;
			else{
				dp[i][c]=(dp[i-(10-c)][1]+dp[i-(10-c)][0])%mod;
			}
		}
	}
	T=read();
	while(T--){
		int n=read(),m=read();
		int ans=0;
		while(n){
			ans=(ans+dp[m][n%10])%mod;
			n/=10;
		}
		printf("%d\n",ans);
	}
	return 0;
}