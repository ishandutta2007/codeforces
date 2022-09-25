#include<bits/stdc++.h>
using namespace std;
#define N 55
typedef long long ll;
const ll inf=1e18;
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
int T,n,ans[N],vis[N],f[N];
ll dp[N],k,fac[N];
inline ll Get(int x){
	return x<0?1:fac[x];
}
inline int getf(int x){
	return f[x]==x?x:f[x]=getf(f[x]);
}
void Solve(){
	memset(vis,0,sizeof(vis));
	n=read(),k=read()-1;
	for(int i=1;i<=n;++i)f[i]=i;
	if(dp[n]<=k){
		return (void)(printf("-1\n"));
	}
	for(int i=1;i<=n;){
		for(int j=1;;++j){
			ll w=dp[n-i-j+1];
			ll tmp=w<=inf/Get(j-2)?w*Get(j-2):inf;
			if(k<tmp){
				ans[i]=i+j-1;
				vis[i+j-1]=1;
				f[i+j-1]=i;
				for(int d=i+1;d<=i+j-1;++d){
					for(int p=i;p<=i+j-2;++p){
						if(vis[p]||(d<i+j-1&&p==getf(d)))continue;
						if(k>=(w<=inf/Get(i+j-2-d)?w*Get(i+j-2-d):inf)){
							k-=w*Get(i+j-2-d);
							continue;
						}
						ans[d]=p;
						vis[p]=1;
						f[p]=d;
						break;
						
					}
				}
				i+=j;
				break;
			}
			else{
				k-=tmp;
			}
		}	
	}
	for(int i=1;i<=n;++i){
		printf("%d ",ans[i]);
	}
	printf("\n");
}
int main(){
	fac[0]=1;
	for(int i=1;i<=50;++i){
		fac[i]=(fac[i-1]<=inf/i?fac[i-1]*i:inf);
	}
	dp[1]=dp[0]=1;
	for(int i=2;i<=50;++i){
		for(int j=1;j<=i;++j){
			dp[i]+=(dp[i-j]<=inf/Get(j-2)?dp[i-j]*Get(j-2):inf);
			if(dp[i]>=inf){dp[i]=inf;break;}
		}
	}
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}