#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int T,n,i,fl,a[N],j,k,b[N],sum,res,dp[105][10005];
long long ans;
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;ans=sum=0;
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=2;i<n;++i)if(a[i]!=1)sum=1;
		if(!sum)cout<<-1<<"\n";
		else{
			for(i=2;i<n;++i)if(a[i]%2==0)sum=0;
			for(i=2;i<n;++i)ans+=((a[i]+1)/2);
			if(!sum){
				cout<<ans<<"\n";
			}
			else if(n>3){
				cout<<ans<<"\n"; 
			}
			else cout<<-1<<"\n";
		}
	}
}