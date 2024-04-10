#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 505
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
int n,m,vis[N][N];
char a[N][N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		scanf("%s",a[i]+1);
	}
	int x=0,y=0,tot=0;
	for(int i=2;i<n;++i){
		for(int j=2;j<m;++j){
			if(a[i][j]=='*'&&a[i-1][j]=='*'&&a[i+1][j]=='*'&&a[i][j-1]=='*'&&a[i][j+1]=='*'){
				x=i,y=j,++tot;
			}
		}
	}
	if(tot^1){
		printf("NO\n");
		return 0;
	}
	int i=x;
	vis[x][y]=1;
	while(i>1&&a[i-1][y]=='*'){
		--i,vis[i][y]=1;
	}
	i=x;
	while(i<n&&a[i+1][y]=='*'){
		++i,vis[i][y]=1;
	}
	i=y;
	while(i>1&&a[x][i-1]=='*'){
		--i,vis[x][i]=1;
	}
	i=y;
	while(i>1&&a[x][i+1]=='*'){
		++i,vis[x][i]=1;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!vis[i][j]&&a[i][j]=='*'){
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}