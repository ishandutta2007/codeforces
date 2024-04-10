#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 123
const int mod=998244353;
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
int n,dp[N][N*N],a[N],ans,cnt[N],sum,C[N][N],type;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		++cnt[a[i]];
		if(cnt[a[i]]==1)++type;
	}
	if(type==1)return !printf("%d\n",n);
	C[0][0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		sum+=a[i];
		for(int p=i;p>=1;--p){
			for(int j=sum;j>=a[i];--j){
				dp[p][j]=(dp[p][j]+dp[p-1][j-a[i]])%mod;
			}
		}
	}
	for(int i=1;i<=100;++i){
		for(int j=1;j<=cnt[i];++j){
			if(dp[j][i*j]==C[cnt[i]][j]){
				ans=max(ans,j);
				if(type==2&&j==cnt[i])ans=max(ans,n);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}