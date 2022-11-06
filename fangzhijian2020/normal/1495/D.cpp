#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=1e9,mod=998244353;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,m,x,y,f[405][405],vis[405],instack[405],ans[405][405],h[405],cnt;
struct edge{int to,next;}e[1205];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
int solve(int x,int y){
	int ans=1;
//	cout<<x<<" "<<y<<":\n";
	for(int i=1;i<=n;++i){
		if(!instack[i]){
//			cout<<i<<" ";
			int tmp=0;
			for(int j=h[i];j;j=e[j].next){
				if(f[x][e[j].to]==f[x][i]-1&&f[y][e[j].to]==f[y][i]-1){
					++tmp;
				}
			}
			ans=1ll*ans*tmp%mod;
		}
	}
//	cout<<ans<<"\n";
	return ans;
}
void dfs(int x,int rt){
	int i,y;vis[x]=instack[x]=1;
	ans[rt][x]=solve(rt,x);
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(f[rt][y]!=f[rt][x]+1||vis[y])continue;
		dfs(y,rt);
	}
	instack[x]=0;
}
int main(){
	n=read();m=read();
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;++i)f[i][i]=0;
	for(int i=1;i<=m;++i){
		x=read();y=read();
		add(x,y);add(y,x);
		f[x][y]=f[y][x]=1;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(f[i][k]<INF&&f[k][j]<INF){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
	}
//	instack[1]=instack[2]=1;cout<<solve(1,2);
	for(int i=1;i<=n;++i){
		memset(vis,0,sizeof(vis));dfs(i,i);
		for(int j=1;j<=n;++j)cout<<ans[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}