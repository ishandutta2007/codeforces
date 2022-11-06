#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long read(){
	long long a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,m,k,x,y,h[100005],cnt,col[100005],sum,d[100005],vis[100005],fa[100005];
struct edge{int to,next;}e[400005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
void DFS(int x,int prt){
	int i,y;if(col[x])++sum;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		col[y]=col[x]^1;DFS(y,x);
	}
}
void dfs(int x,int prt){
	int i,y;vis[x]=1;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		if(vis[y]){
			if(d[x]<=k){
				puts("2");
				cout<<d[x]-d[y]+1<<"\n";
				while(x!=y){
					cout<<x<<" ";x=fa[x];
				}
				cout<<y<<"\n";
				exit(0);
			}
			else{
				x=fa[x];puts("1");
				for(int j=1;j<=(k+1)/2;++j){
					cout<<x<<" ";x=fa[fa[x]];
				}
				exit(0);
			}
		}
	}
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		if(!vis[y]){
			d[y]=d[x]+1;fa[y]=x;dfs(y,x);
		}
	}
}
int main(){
	n=read();m=read();k=read();
	for(int i=1;i<=m;++i){
		x=read();y=read();
		add(x,y);add(y,x);
	}
	if(m==n-1){
		DFS(1,0);puts("1");int tot=(k+1)/2;
		if(sum>=(k+1)/2){
			for(int i=1;i<=n;++i){
				if(col[i]==1&&tot){
					cout<<i<<" ";--tot;
				}
			}
		}
		else{
			for(int i=1;i<=n;++i){
				if(col[i]==0&&tot){
					cout<<i<<" ";--tot;
				}
			}
		}
	}
	else{
		d[1]=1;dfs(1,0);
	}
	return 0;
}