#include<bits/stdc++.h>
using namespace std;
#define N 41
typedef long long ll;
typedef unsigned long long ull;
#define int ll
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
int n,m,mp[N][N],K,H,vis[N],Z,d[N],col[N],er;
int f[1<<20];
ll ans,pw2[N],t[N];
bool dfs(int u){
	bool ok=true;
	for(int v=0;v<n;++v){
		if(mp[u][v]){
			if(~col[v]){
				if(col[u]==col[v])ok=false;
			}
			else{
				col[v]=col[u]^1;
				if(!dfs(v))ok=false;
			}
		}
	}
	return ok;
}
signed main(){
	n=read(),m=read();
	if(m<=2){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=m;++i){
		int u=read()-1,v=read()-1;
		mp[u][v]=mp[v][u]=1;
		++d[u],++d[v];
		t[u]|=1LL<<v;
		t[v]|=1LL<<u;
	}
	for(int i=0;i<n;++i)Z+=d[i]==0,col[i]=-1;
	pw2[0]=1;
	for(int i=1;i<=n;++i){
		pw2[i]=pw2[i-1]<<1;
	}
	er=1;
	for(int i=0;i<n;++i){
		if(!~col[i]){
			col[i]=0;
			if(!dfs(i))er=0;
			++H;
		}
	}
	ans=pw2[n]-pw2[H];
	ans+=pw2[Z]<<1;
	if(er)ans+=pw2[H];
	K=(n>>1);
	for(int i=0;i<(1<<K);++i){
		bool ok=true;
		for(int j=0;j<K;++j){
			if(i>>j&1){
				if(t[j]&i){
					ok=false;break;
				}	
			}
		}
		if(ok)++f[i];
	}
	for(int j=0;j<K;++j){
		for(int i=0;i<(1<<K);++i){
			if(i>>j&1)f[i]+=f[i^(1<<j)];
		}
	}
	ll tmp=0;
	for(int i=0;i<(1<<n-K);++i){
		bool ok=true;
		int st=0;
		for(int j=0;j<n-K;++j){
			if(i>>j&1){
				if(t[j+K]>>K&i){
					ok=false;break;
				}
				st|=t[j+K]&((1<<K)-1);
			}
		}
		if(ok){
			tmp+=f[st^((1<<K)-1)];
		}
	}
	ans-=tmp<<1;
	printf("%lld\n",ans);
	return 0;
}