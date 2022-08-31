#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,tg[800002],mx[800002],inf=1e9,a[200002],pos[200002],ans;
inline void build(re int p,re int l,re int r){
	mx[p]=n-l+(l&1),tg[p]=0;
	if(l==r)return;
	re int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
}
inline void Add(re int x,re int y){tg[x]+=y,mx[x]+=y;}
inline void add(re int p,re int l,re int r,re int x,re int y,re int z){
	if(l>=x&&r<=y)return Add(p,z);
	re int mid=l+r>>1;
	if(x<=mid)add(p<<1,l,mid,x,y,z);
	if(y>mid)add(p<<1|1,mid+1,r,x,y,z);
	mx[p]=max(mx[p<<1],mx[p<<1|1])+tg[p];
}
inline int ask(re int p,re int l,re int r,re int x){
	if(l>=x)return mx[p];
	re int mid=l+r>>1,s=ask(p<<1|1,mid+1,r,x);
	if(x<=mid)s=max(s,ask(p<<1,l,mid,x));
	return s+tg[p];
}
int main(){
	int t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)pos[a[i]=read()]=i;
		build(1,1,n);re int pp=n;ans=0;
		for(re int i=n;i;--i){
			re int x=pos[i];pp=min(pp,x);
			add(1,1,n,x,x,-inf);
			if(x^n)add(1,1,n,x+1,n,1);
			if(x^1)add(1,1,n,1,x-1,-1);
			if(pp^n)ans=max(ans,ask(1,1,n,pp+1));
		}
		printf("%d\n",ans);
	}
}