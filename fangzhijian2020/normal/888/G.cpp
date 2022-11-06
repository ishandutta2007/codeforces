#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mxdt=100000;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int n,a[200005];long long ans;
int tot,ch[6000005][2],sz[6000005];
void clear(){
	while(tot){
		ch[tot][0]=ch[tot][1]=sz[tot]=0;
		--tot;
	}
	tot=1;
}
void insert(int a){
	int now=1;
	for(int i=29;~i;--i){
		int x=(a>>i)&1;
		if(!ch[now][x])ch[now][x]=++tot;
		now=ch[now][x];
	}
}
int query(int a){
	int now=1,ans=0;
	for(int i=29;~i;--i){
		int x=(a>>i)&1;
		if(!ch[now][x]){
			ans+=(1<<i);x^=1;
		}
		now=ch[now][x];
	}
	return ans;
}
void div(int l,int r,int d){
	if(l>=r||d==-1)return;int mid=l-1;
	while(mid<r&&!(a[mid+1]&(1<<d)))++mid;
	if(mid>=l&&mid<r){
		clear();
		for(int i=l;i<=mid;++i)insert(a[i]);
		int Min=(1<<30);
		for(int i=mid+1;i<=r;++i)Min=min(Min,query(a[i]));
		ans+=Min;
	}
	div(l,mid,d-1);div(mid+1,r,d-1);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1);n=unique(a+1,a+n+1)-a-1;
	div(1,n,30);cout<<ans<<"\n";
	return 0;
}