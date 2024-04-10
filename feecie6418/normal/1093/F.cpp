#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,len,f[100005][105],sum[100005],s[100005][105];
int main(){
	cin>>n>>m>>len,sum[0]=1;
	if(len==1)return puts("0"),0;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		for(int j=1;j<=m;j++)s[i][j]=s[i-1][j]+(x==-1||x==j);
		if(i==1){
			for(int j=1;j<=m;j++)if(j==x||x==-1)f[i][j]=1,sum[i]=(sum[i]+f[i][j])%mod;
			continue;
		}
		for(int j=1;j<=m;j++){
			if(j!=x&&x!=-1)continue;
			f[i][j]=sum[i-1];
			if(i>=len&&s[i][j]-s[i-len][j]==len)f[i][j]=(0ll+f[i][j]-sum[i-len]+mod+f[i-len][j])%mod;
			sum[i]=(sum[i]+f[i][j])%mod;
		}
	}
	cout<<sum[n];
}