#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const int mod=998244353;
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
int n,m,sg[N],vis[N],g[522][522],p[N],ans[522];
vector<int> G[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
inline int get_mex(vector<int> &v){
	sort(v.begin(),v.end());
	for(int i=0,j=0;;++i){
		if(j==(int)v.size()||v[j]^i)return i;
		while(j<(int)v.size()&&v[j]==i)++j;
	}
}
void dfs(int u){
	vector<int> num;
	vis[u]=1;
	for(auto v:G[u]){
		if(!vis[v])dfs(v);
		num.push_back(sg[v]);
	}
	sg[u]=get_mex(num);
	++p[sg[u]];
}
void Guass(int n,int *ans){
	for(int i=0;i<n;++i){
		if(!g[i][i]){
			for(int j=i+1;j<n;++j){
				if(g[j][i]){
					swap(g[j],g[i]);
					break;
				}
			}
		}
		int inv=qpow(g[i][i],mod-2);
		for(int j=i+1;j<n;++j){	
			int div=1LL*inv*g[j][i]%mod;
			for(int k=i;k<=n;++k){
				g[j][k]=(g[j][k]-1LL*div*g[i][k]%mod+mod)%mod;
			}
		}
	}
	for(int i=n-1;i>=0;--i){
		ans[i]=g[i][n];
		for(int j=i+1;j<n;++j){
			ans[i]=(ans[i]-1LL*g[i][j]*ans[j]%mod+mod)%mod;
		}
		ans[i]=1LL*ans[i]*qpow(g[i][i],mod-2)%mod;
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].push_back(v);
	}
	for(int i=1;i<=n;++i){
		if(!vis[i])dfs(i);	
	}
	int invn=qpow(n+1,mod-2);
	for(int i=0;i<512;++i){
		g[0][i]=1;
	}
	g[0][512]=1;
	for(int i=1;i<512;++i){
		g[i][i]=1;
		for(int j=0;j<512;++j){
			g[i][i^j]=(g[i][i^j]+mod-1LL*invn*p[j]%mod)%mod;
		}	
	}
	Guass(512,ans);
	printf("%d\n",(mod+1-ans[0])%mod);
	return 0;
}