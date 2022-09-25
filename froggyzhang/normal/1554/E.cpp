#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int n,pw2[N],mu[N],f[N],ans[N];
vector<int> G[N];
void init(int n){
	pw2[0]=1;
	for(int i=1;i<=100000;++i)(pw2[i]=pw2[i-1]<<1)%=mod;
	mu[1]=1;
	for(int i=1;i<=n;++i)
		for(int j=i+i;j<=n;j+=i)
			mu[j]-=mu[i];
}
int dfs(int u,int fa,int D){
	int cnt=0;
	for(auto v:G[u]){
		if(v==fa)continue;
		int x=dfs(v,u,D);
		if(!~x)return -1;
		cnt+=x;
	}
	cnt%=D;
	if(!cnt)return 1;
	if(cnt==D-1)return 0;
	return -1;
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		G[i].clear();ans[i]=f[i]=0;
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	f[1]=pw2[n-1];
	for(int i=2;i<n;++i){
		if((n-1)%i==0){
			if(dfs(1,0,i)==1){
				++f[i];
			}	
		}
	}
	for(int i=n;i>=1;--i){
		for(int j=i;j<=n;j+=i){
			ans[i]+=mu[j/i]*f[j];
		}			
	}
	for(int i=1;i<=n;++i){
		ans[i]=(ans[i]%mod+mod)%mod;
		printf("%d ",ans[i]);
	}
	printf("\n");
}
int main(){
	init(100000);
	int T=read();
	while(T--)Solve();
	return 0;
}