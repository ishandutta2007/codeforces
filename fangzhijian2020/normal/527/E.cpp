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
int n,m,h[100005],cnt=1,x,y,rd[100005],p[100005],tot;
struct edge{int to,next;}e[500005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
int vis[500005],tp;
void dfs(int x){
	int y,t;
	for(int &i=h[x];i;i=e[i].next)if(!vis[i]){
		y=e[t=i].to;vis[i]=vis[i^1]=1;dfs(y);tp^=1;
		cout<<e[t^1^tp].to<<" "<<e[t^tp].to<<"\n";
	}
}
int main(){
	n=read();m=read();
	for(int i=1;i<=m;++i){
		x=read();y=read();
		add(x,y);add(y,x);
		++rd[x];++rd[y];
	}
	for(int i=1;i<=n;++i){
		if(rd[i]&1)p[++tot]=i;
	}
	for(int i=1;i<=tot;i+=2){
		add(p[i],p[i+1]);add(p[i+1],p[i]);
	}
	if((m+tot/2)&1)add(1,1),add(1,1);
	cout<<m+tot/2+((m+tot/2)&1)<<"\n";
	dfs(1);
	return 0;
}