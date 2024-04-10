#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define re register
#define ll long long
int n,m,a[100002],cov[400002];
ll mn[400002],val[400002],tg[400002];
set<ll>S;
const int Mxdt=100000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
void print(ll x)
{
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(ll x,char ch)
{
	print(x),pc(ch,false);
}
inline void Add(re int p,re ll x){
	mn[p]+=x,val[p]+=x;
	if(!cov[p])tg[p]+=x;
}
inline void pu(re int p){mn[p]=max(mn[p<<1],mn[p<<1|1]);}
inline void pd(re int p){
	if(cov[p]){
		mn[p<<1]=mn[p<<1|1]=mn[p];
		val[p<<1]=val[p<<1|1]=val[p];
		tg[p<<1]=tg[p<<1|1]=0;
		cov[p<<1]=cov[p<<1|1]=1;
		cov[p]=0;
	}
	if(tg[p])Add(p<<1,tg[p]),Add(p<<1|1,tg[p]),tg[p]=0;
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
inline ll ask(re int p,re int l,re int r,re int x){
	if(l==r)return val[p];
	pd(p);
	re int mid=l+r>>1;
	if(x<=mid)return ask(p<<1,l,mid,x);
	else return ask(p<<1|1,mid+1,r,x);
}
inline void Set(re int p,re ll x){
	val[p]=x,mn[p]=x-*S.lower_bound(x);
}
inline void add(re int p,re int l,re int r,re int x,re int y,re int z){
	if(l==r)return Set(p,val[p]+z);
	re int mid=l+r>>1;
	if(l>=x&&r<=y){
		if(cov[p])return Set(p,val[p]+z);
		if(mn[p]+z<=0)return Add(p,z);
	}
	pd(p);
	if(x<=mid)add(p<<1,l,mid,x,y,z);
	if(y>mid)add(p<<1|1,mid+1,r,x,y,z);
	pu(p);
}
inline void cg(re int p,re int l,re int r,re int x,re int y,re int z){
	if(l>=x&&r<=y){
		tg[p]=0,cov[p]=1,Set(p,z);
		return;
	}
	pd(p);
	re int mid=l+r>>1;
	if(x<=mid)cg(p<<1,l,mid,x,y,z);
	if(y>mid)cg(p<<1|1,mid+1,r,x,y,z);
	pu(p);
}
inline void build(re int p,re int l,re int r){
	if(l==r)return Set(p,a[l]);
	re int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
	pu(p);
}
signed main(){
	n=read(),m=read();
	for(re ll i=1;i<=1e15;i*=42)S.insert(i);
	for(re int i=1;i<=n;++i)a[i]=read();
	build(1,1,n);
	while(m--){
		re int o=read(),x=read(),y,z;
		if(o==1){
			printnum(ask(1,1,n,x),'\n');
		}
		else if(o==2){
			y=read(),z=read();
			cg(1,1,n,x,y,z);
		}
		else{
			y=read(),z=read();
			add(1,1,n,x,y,z);
			while(mn[1]==0)add(1,1,n,x,y,z);
		}
	}
	pc('o',1);
}