#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 55
inline int read(){
	int x=0,f=1;
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
int T,n,m;
int a[N][N],tot,vis[N][N];
char s[N][N];
const int d[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
inline bool In(int x,int y){
	return x>=1&&y>=1&&x<=n&&y<=m;
}
void dfs(int x,int y){
	if(a[x][y])return;
	if(s[x][y]=='G')++tot;
	vis[x][y]=1;
	for(int i=0;i<4;++i){
		int nx=x+d[i][0],ny=y+d[i][1];
		if(!In(nx,ny)||a[nx][ny]||vis[nx][ny])continue;
		dfs(nx,ny);
	}
}
bool Solve(){
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
	int cnt=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(s[i][j]=='#')a[i][j]=1;
			else if(s[i][j]=='B'){
				a[i][j]=1;
				for(int k=0;k<4;++k){
					int nx=i+d[k][0],ny=j+d[k][1];
					if(!In(nx,ny))continue;
					if(s[nx][ny]=='G'){
						return false;
					}
					a[nx][ny]=1;
				}
			}
			else if(s[i][j]=='G')++cnt;
		}
	}
	tot=0;
	dfs(n,m);
	return tot==cnt;
}
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;++i){
			scanf("%s",s[i]+1);
		}
		printf(Solve()?"Yes\n":"No\n");
	}
	return 0;
}