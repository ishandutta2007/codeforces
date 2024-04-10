#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1010
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,m,vis[N][N];
char s[N][N];
int a[N],b[N],tota,totb,ans;
const int d[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
void dfs(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<4;++i){
		int nx=x+d[i][0],ny=y+d[i][1];
		if(nx<1||ny<1||nx>n||ny>m||vis[nx][ny]||s[nx][ny]=='.')continue;
		dfs(nx,ny);
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		scanf("%s",s[i]+1);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(s[i][j]=='#'){
				if(j>1&&a[i]&&s[i][j-1]=='.'){
					printf("-1\n");return 0;
				}
				a[i]=1;
			}
		}
		tota+=a[i];
	}
	for(int j=1;j<=m;++j){
		for(int i=1;i<=n;++i){
			if(s[i][j]=='#'){
				if(i>1&&b[j]&&s[i-1][j]=='.'){
					printf("-1\n");return 0; 
				}
				b[j]=1;
			}
		}
		totb+=b[j];
	}
	if(tota<n&&totb==m||tota==n&&totb<m){
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!vis[i][j]&&s[i][j]=='#'){
				++ans;dfs(i,j);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}