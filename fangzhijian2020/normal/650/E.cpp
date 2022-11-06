#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int Mxdt=100000;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int n,x,y,fa[500005],f[500005];map<int,int>mp[500005];
int getfzj(int x){
	if(x==fa[x])return x;
	return fa[x]=getfzj(fa[x]);
}
int tot,t1[500005],t2[500005],t3[500005],t4[500005];
void Add(int x,int y,int X,int Y){
	++tot;
	t1[tot]=x;t2[tot]=y;t3[tot]=X;t4[tot]=Y;
}
struct tree{
	int h[500005],cnt;
	struct edge{int to,next;}e[1000005];
	void add(int x,int y){
		e[++cnt]=(edge){y,h[x]};h[x]=cnt;
	}
	void dfs(int x,int prt){
		int i,y;
		for(i=h[x];i;i=e[i].next){
			y=e[i].to;if(y==prt)continue;
			if(mp[min(x,y)][max(x,y)]==2)fa[y]=x;
			dfs(y,x);f[y]=x;
		}
	}
	void DFS(int x,int prt){
		int i,y;
		for(i=h[x];i;i=e[i].next){
			y=e[i].to;if(y==prt)continue;
			DFS(y,x);
			if(mp[min(x,y)][max(x,y)]!=2){
				int p=getfzj(y);
				Add(x,y,p,f[p]);
			}
		}
	}
}T1,T2;
int main(){
	n=read();
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<n;++i){
		x=read();y=read();
		if(x>y)swap(x,y);
		T1.add(x,y);T1.add(y,x);
		++mp[x][y];
	}
	for(int i=1;i<n;++i){
		x=read();y=read();
		if(x>y)swap(x,y);
		T2.add(x,y);T2.add(y,x);
		++mp[x][y];
	}
	T2.dfs(1,0);T1.DFS(1,0);
	cout<<tot<<"\n";
	for(int i=1;i<=tot;++i){
		cout<<t1[i]<<" "<<t2[i]<<" "<<t3[i]<<" "<<t4[i]<<"\n";
	}
	return 0;
}