#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
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
int T,n,x,y,h[200005],cnt,mi[200005],sp[200005],d[200005],tot,f[200005],t[200005];
queue<int>q;
struct edge{int to,next;}e[2000005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
int main(){
	T=read()+1;
	memset(mi,-1,sizeof(mi));
	for(int i=0;i<=16;++i){
		mi[1<<i]=i;
	}
	for(int i=1;i<(1<<16);++i){
		sp[i]=sp[i^(i&-i)]^mi[i&-i];
	}
	while(--T){
		n=read();
		for(int i=0;i<n*(1<<n-1);++i){
			x=read();y=read();
			add(x,y);add(y,x);
		}
		d[0]=1;tot=0;
		for(int i=h[0];i;i=e[i].next){
			int y=e[i].to;
			d[y]=2;f[y]=(1<<tot);++tot;
			q.push(y);
		}
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int i=h[x];i;i=e[i].next){
				y=e[i].to;
				if(!d[y]){
					d[y]=d[x]+1;
					f[y]|=f[x];
					q.push(y);
				}
				else if(d[y]==d[x]+1){
					f[y]|=f[x];
				}
			}
		}
		for(int i=0;i<(1<<n);++i)t[f[i]]=i;
		for(int i=0;i<(1<<n);++i)cout<<t[i]<<" ";puts("");
		if(mi[n]!=-1){
			for(int i=0;i<(1<<n);++i)cout<<sp[f[i]]<<" ";puts("");
		}
		else{
			puts("-1");
		}
		for(int i=0;i<(1<<n);++i){
			h[i]=0;d[i]=0;f[i]=0;
		}
		cnt=0;
	}
	return 0;
}