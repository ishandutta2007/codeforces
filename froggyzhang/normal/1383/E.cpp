#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
const int mod=1e9+7;
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
int n,tot,c[N],dp[N],sum,ans;
char a[N];
int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	tot=1;
	for(int i=1;i<=n;++i){
		if(a[i]=='1')++tot;
		else ++c[tot];
	}
	if(tot==1){
		return !printf("%d\n",c[tot]);
	}
	int ans=1;
	for(int i=2;i<tot;++i){
		for(int j=0;j<=c[i];++j){
			sum=(sum-dp[j]+ans)%mod;
			sum=(sum+mod)%mod;
			dp[j]=ans;
		}
		ans=(sum+1)%mod;
	}
	ans=1LL*ans*(c[1]+1)%mod*(c[tot]+1)%mod;
	printf("%d\n",ans);
	return 0;
}