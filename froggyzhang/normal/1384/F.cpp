#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 255
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
int n,m,a[N][N],vis1[N*N],vis2[N*N];
int ans[N][N],l,r,X,Y;
pair<int,int> q[N*N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=read();
		}
	}
	for(int i=1;i<=n;++i){
		int mx=0;
		for(int j=1;j<=m;++j){
			mx=max(mx,a[i][j]);
		}
		vis1[mx]=1;
	}
	for(int j=1;j<=m;++j){
		int mx=0;
		for(int i=1;i<=n;++i){
			mx=max(mx,a[i][j]);
		}
		vis2[mx]=1;
	}
	l=1,r=0;
	for(int i=n*m;i>=1;--i){
		X+=vis1[i],Y+=vis2[i];
		if(vis1[i]||vis2[i]){
			ans[X][Y]=i;
		}
		else{
			pair<int,int> p=q[l++];
			ans[p.first][p.second]=i;
		}
		if(vis2[i]){
			for(int j=X-1;j>=1;--j){
				q[++r]=make_pair(j,Y);
			}
		}
		if(vis1[i]){
			for(int j=Y-1;j>=1;--j){
				q[++r]=make_pair(X,j);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}