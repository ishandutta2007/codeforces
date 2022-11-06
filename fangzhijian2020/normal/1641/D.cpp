#pragma GCC optimize(2)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize(3,"Ofast","inline")
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int Mxdt=100000,mod=998244353,INF=1e9;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2),*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int n,m,sz[105],Max=2*INF+1,tmp[10000005],tot;
struct node{
	int p[10],w;
	bool operator<(const node&a)const{
		return w<a.w;
	}
}a[100005];
const int M=9999997;
struct Hash {
	int H[M+1],cnt,nx[10000005],id[10000005];__int128 to[10000005];
	inline Hash(){memset(H,cnt=0,sizeof(H));}
	inline void Clear(){
		while(cnt)H[to[cnt--]%M]=0;
	}
	inline int& operator [] (const __int128 x){
		int p=x%M;
		for(int i=H[p];i;i=nx[i])
		if(to[i]==x)return id[i];
		return nx[++cnt]=H[p],to[H[p]=cnt]=x,id[cnt];
	}
	inline int Find(const __int128 x){
		for(int i=H[x%M];i;i=nx[i])
		if(to[i]==x)return id[i];
		return -1;
	}
}mp;
void add(int x,int opt){
	for(int s=1;s<(1<<m);++s){
		__int128 v=0;
		for(int j=0;j<m;++j){
			if((s>>j)&1)v=v*tot+a[x].p[j];
		}
		mp[v]+=opt;
	}
}
int ask(int x){
	int ans=0;
	for(int s=1;s<(1<<m);++s){
		__int128 v=0;
		for(int j=0;j<m;++j){
			if((s>>j)&1)v=v*tot+a[x].p[j];
		}
		if(sz[s]&1)ans+=mp[v];else ans-=mp[v];
	}
	return ans;
}
int check(int l,int r){
	for(int i=0;i<m;++i){
		for(int j=0;j<m;++j){
			if(a[l].p[i]==a[r].p[j])return 0;
		}
	}
	return 1;
}
int main(){
	n=read();m=read();
	for(int i=1;i<(1<<m);++i)sz[i]=(sz[i>>1])+(i&1);
	for(int i=1;i<=n;++i){
		for(int j=0;j<m;++j)a[i].p[j]=read(),tmp[++tot]=a[i].p[j];a[i].w=read();
		sort(a[i].p,a[i].p+m);
	}
	sort(tmp+1,tmp+tot+1);tot=unique(tmp+1,tmp+tot+1)-tmp-1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<m;++j)a[i].p[j]=lower_bound(tmp+1,tmp+tot+1,a[i].p[j])-tmp;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)add(i,1);
	int r=n;
	for(int i=1;i<r;++i){
		int tmp=r-i+1-ask(i);
		while(tmp>=1){
			if(check(i,r))Max=min(Max,a[i].w+a[r].w),--tmp;
			add(r,-1);--r;
		}
		add(i,-1);
	}
	if(Max>2*INF)puts("-1");
	else cout<<Max<<"\n";
	return 0;
}