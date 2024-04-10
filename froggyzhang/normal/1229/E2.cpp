#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __uint128_t u128;
const int mod=1e9+7;
const int inv100=570000004;
int p[7][7],n,all;
map<u128,int> dp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>p[i][j];
			p[i][j]=1LL*inv100*p[i][j]%mod;
		}
	}
	all=(1<<n)-1;
	dp[1]=1;
	for(int i=0;i<n;++i){
		map<u128,int> g;
		for(int s=0;s<=all;++s){
			int P=1;
			for(int j=0;j<n;++j){
				if(s>>j&1)P=1LL*p[i][j]*P%mod;
				else P=1LL*(mod+1-p[i][j])*P%mod;
			}
			for(auto [u,w]:dp){
				u128 v=0;
				for(int j=0;j<=all;++j){
					if(u>>j&1){
						for(int k=0;k<n;++k){
							if(s>>k&1&&!(j>>k&1)){
								v|=(u128)1<<(j|(1<<k));	
							}
						}
					}	
				}
				g[v]=(g[v]+1LL*w*P)%mod;
			}	
		}
		dp=g;	
	}
	cout<<dp[(u128)1<<all]<<'\n';
	return 0;
}