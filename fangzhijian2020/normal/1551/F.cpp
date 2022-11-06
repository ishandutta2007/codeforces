#include<iostream> 
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int mod=1e9+7;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,n,k,x,y,ans,c[105][105],g[105][105],f[105][105],tmp[105][105];vector<int>son[105];
void dfs(int x,int prt,int dep){
	int i,y;memset(g[x],0,sizeof(g[x]));
	++g[x][dep];
	for(i=0;i<son[x].size();++i){
		y=son[x][i];if(y==prt)continue;
		dfs(y,x,dep+1);
		for(int i=1;i<=n;++i)g[x][i]=(g[x][i]+g[y][i])%mod;
	}
}
int main(){
	T=read()+1;
	c[0][0]=1;
	for(int i=1;i<=100;++i){
		c[i][0]=1;
		for(int j=1;j<=100;++j){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
	while(--T){
		n=read();k=read();ans=0;
		for(int i=1;i<n;++i){
			x=read();y=read();
			son[x].push_back(y);
			son[y].push_back(x);
		}
		if(k<=2)cout<<c[n][k]<<"\n";
		else{
			for(int x=1;x<=n;++x){
				dfs(x,0,1);int opt=0;
				memset(f,0,sizeof(f));
				for(int i=1;i<=n;++i)f[i][0]=1;
				for(int i=0;i<son[x].size();++i){
					y=son[x][i];
					memset(tmp,0,sizeof(tmp));
					for(int j=1;j<=n;++j){
						for(int t=0;t<=k;++t){
							tmp[j][t+1]=1ll*f[j][t]*g[y][j]%mod;
						}
					}
					for(int j=1;j<=n;++j){
						for(int t=0;t<=k;++t){
							f[j][t]=(f[j][t]+tmp[j][t])%mod;
						}
					}
				}
				for(int j=1;j<=n;++j){
					ans=(ans+f[j][k])%mod;
				}
			}cout<<ans<<"\n";
		}
		
		for(int i=1;i<=n;++i)son[i].clear();
	}
	return 0;
}