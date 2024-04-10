#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
const int Mxdt=1000000;
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline ll read(){
	re ll t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int n,m,mx,T1[2100002],T2[2100002],X,Y,Z,num[2100002],tg1[2100002],tg2[2100002],len[2100002],stk1[1000002],stk2[1000002],C[1000002],stk3[1000002],stk4[1000002],nn,L1[1000002],L2[1000002];
ll a[1000002],ans;
inline void Cov1(re int p,re int x){
	num[p]=x*T2[p];
	T1[p]=x*len[p];
	tg1[p]=x;
}
inline void Cov2(re int p,re int x){
	num[p]=x*T1[p];
	T2[p]=x*len[p];
	tg2[p]=x;
}
inline void pd(re int p){
	if(~tg1[p])Cov1(p<<1,tg1[p]),Cov1(p<<1|1,tg1[p]),tg1[p]=-1;
	if(~tg2[p])Cov2(p<<1,tg2[p]),Cov2(p<<1|1,tg2[p]),tg2[p]=-1;
}
inline void Cov1(re int p,re int l,re int r){
	if(l>=X&&r<=Y){
		Cov1(p,Z);
		return;
	}
	pd(p);
	re int mid=l+r>>1;
	if(X<=mid)Cov1(p<<1,l,mid);
	if(Y>mid)Cov1(p<<1|1,mid+1,r);
	T1[p]=T1[p<<1]+T1[p<<1|1],num[p]=num[p<<1]+num[p<<1|1];
}
inline void Cov2(re int p,re int l,re int r){
	if(l>=X&&r<=Y){
		Cov2(p,Z);
		return;
	}
	pd(p);
	re int mid=l+r>>1;
	if(X<=mid)Cov2(p<<1,l,mid);
	if(Y>mid)Cov2(p<<1|1,mid+1,r);
	T2[p]=T2[p<<1]+T2[p<<1|1],num[p]=num[p<<1]+num[p<<1|1];
}
inline void build(re int p,re int l,re int r){
	tg1[p]=tg2[p]=-1,len[p]=r-l+1,T1[p]=T2[p]=num[p]=0;
	if(l==r)return;
	re int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
	mx=max(mx,p);
}
int main(){
	n=read();
	for(re int i=1;i<=n;++i){
		a[i]=read();
		for(re int j=0;j<=59;++j)if(a[i]&(1ll<<j))++C[i];
	}
	build(1,1,n);
	re int tp3=0,tp4=0;
	for(re int j=1;j<=n;++j){
		while(tp3&&a[stk3[tp3]]<=a[j])--tp3;
		while(tp4&&a[stk4[tp4]]>=a[j])--tp4;
		L1[j]=stk3[tp3],L2[j]=stk4[tp4];
		stk3[++tp3]=j,stk4[++tp4]=j;
	}
	for(re int i=0;i<=59;++i){
		memset(tg1,-1,sizeof(tg1)),memset(tg2,-1,sizeof(tg2)),memset(T1,0,sizeof(T1)),memset(T2,0,sizeof(T2)),memset(num,0,sizeof(num));
		int tp1=0,tp2=0;
		for(re int j=1;j<=n;++j){
			while(tp1&&a[stk1[tp1]]<=a[j]){
				X=stk1[tp1-1]+1,Y=stk1[tp1],Z=0,Cov1(1,1,n),++nn;
				--tp1;
			}
			while(tp2&&a[stk2[tp2]]>=a[j]){
				X=stk2[tp2-1]+1,Y=stk2[tp2],Z=0,Cov2(1,1,n),++nn;
				--tp2;
			}
			if(C[j]==i){
				X=L1[j]+1,Y=j,Z=(C[j]==i),Cov1(1,1,n),++nn;
				X=L2[j]+1,Y=j,Z=(C[j]==i),Cov2(1,1,n),++nn;
			}
			ans+=num[1];
			if(C[j]==i)stk1[++tp1]=j,stk2[++tp2]=j;
		}
	}
	printf("%lld",ans);
}