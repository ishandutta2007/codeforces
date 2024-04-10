#include<bits/stdc++.h>
using namespace std;
#define N 14
const int mod=1e9+7;
typedef long long ll;
int a[N],n,dp[1<<N],ans,p[N][N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			p[i][j]=1LL*a[i]*qpow(a[i]+a[j],mod-2)%mod;
		}
	}
	int all=(1<<n)-1;
	for(int i=1;i<=all;++i)dp[i]=1;
	for(int s=1;s<all;++s){
		int h=s^all;
		for(int t=h;t;t=(t-1)&h){
			int z=1;
			for(int i=0;i<n;++i){
				if(s>>i&1){
					for(int j=0;j<n;++j){
						if(t>>j&1){
							z=1LL*z*p[j][i]%mod;
						}
					}
				}
			}
			dp[s|t]=(dp[s|t]-1LL*z*dp[s]%mod+mod)%mod;			
		}
	}
	for(int s=1;s<(1<<n);++s){
		int t=all^s;
		int z=1;
		for(int i=0;i<n;++i){
			if(s>>i&1){
				for(int j=0;j<n;++j){
					if(t>>j&1){
						z=1LL*z*p[i][j]%mod;
					}
				}
			}
		}
		ans=(ans+1LL*dp[s]*__builtin_popcount(s)%mod*z)%mod;
	}
	printf("%d\n",ans);
	return 0;
}