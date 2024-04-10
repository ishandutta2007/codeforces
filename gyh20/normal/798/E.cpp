#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int n,m,a[500002],rt,tot,ls[11000002],rs[11000002],head[11000002],cnt,hd,tl,du[11000002],ans,pos[500002];
struct edge{int to,next;}e[40000002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt,++du[y];}
inline void build(re int&p,re int l,re int r){
	if(l^r)p=++tot;else p=l;
	if(l==r)return;
	re int mid=l+r>>1;
	build(ls[p],l,mid),build(rs[p],mid+1,r);
	add(ls[p],p),add(rs[p],p);
}
inline void ins(re int &p,re int l,re int r,re int x){
	++tot,ls[tot]=ls[p],rs[tot]=rs[p],p=tot;
	if(l==r)return;
	re int mid=l+r>>1;
	if(x<=mid)ins(ls[p],l,mid,x);
	else ins(rs[p],mid+1,r,x);
	add(ls[p],p),add(rs[p],p);
}
inline void Add(re int p,re int l,re int r,re int x,re int y,re int z){
	if(l>=x&&r<=y)return add(p,z);
	re int mid=l+r>>1;
	if(x<=mid)Add(ls[p],l,mid,x,y,z);
	if(y>mid)Add(rs[p],mid+1,r,x,y,z);
}
int main(){
	n=read(),tot=n,build(rt,1,n);
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=n;++i){
		re int x=a[i]==-1?n:a[i]-1;
		if(x<i){
			if(x)Add(rt,1,n,1,x,i);
		}
		else{
			if(i^1)Add(rt,1,n,1,i-1,i);
			if(x>i)Add(rt,1,n,i+1,x,i);
		}
		if(a[i]!=-1)add(i,a[i]),ins(rt,1,n,a[i]);
	}
	hd=1,memset(ls,0,sizeof(ls));
	for(re int i=1;i<=tot;++i)if(!du[i])ls[++tl]=i;
	while(hd<=tl){
		re int x=ls[hd++];
		if(x<=n)pos[x]=++ans;
		for(re int i=head[x];i;i=e[i].next)if(!--du[e[i].to])ls[++tl]=e[i].to;
	}for(re int i=1;i<=n;++i)printf("%d ",pos[i]);
}