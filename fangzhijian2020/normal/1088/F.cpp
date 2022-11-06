#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,a[500005],x,y,root,h[500005],cnt;
struct edge{int to,next;}e[500005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
int f[500005][20];long long ans;
void dfs(int x){
	int i,y;long long Min=a[f[x][0]];
	for(i=1;i<20;++i){
		f[x][i]=f[f[x][i-1]][i-1];
		if(f[x][i])Min=min(Min,1ll*(i+1)*a[f[x][i]]);
		else Min=min(Min,1ll*(i+1)*a[root]);
		if(!f[x][i])break;
	}
	if(x!=root)ans+=Min+a[x];
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;dfs(y);
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(!root||a[i]<a[root])root=i;
	}
	for(int i=1;i<n;++i){
		x=read();y=read();
		if(a[x]>a[y])swap(x,y);
		add(x,y);f[y][0]=x;
	}
	dfs(root);cout<<ans;
	return 0;
}