#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[1000002],b[1000002],P[1000002],p1,p2,C[2000002],mn[4000002],tg[4000002],c[1000002];
inline void add(re int x){for(;x<=n;x+=x&(-x))++c[x];}
inline int ask(re int x){re int s=0;for(;x;x^=x&(-x))s+=c[x];return s;}
inline bool cmp(re int x,re int y){return a[x]<a[y];}
inline void Add(re int x,re int y){tg[x]+=y,mn[x]+=y;}
inline void pd(re int p){
	if(tg[p]){
		Add(p<<1,tg[p]);
		Add(p<<1|1,tg[p]);
		tg[p]=0;
	}
}
inline void add(re int p,re int l,re int r,re int x,re int y,re int z){
	if(l>=x&&r<=y)return Add(p,z);
	pd(p);
	re int mid=l+r>>1;
	if(x<=mid)add(p<<1,l,mid,x,y,z);
	if(y>mid)add(p<<1|1,mid+1,r,x,y,z);
	mn[p]=min(mn[p<<1],mn[p<<1|1]);
}
inline void build(re int p,re int l,re int r){
	mn[p]=l,tg[p]=0;
	if(l==r)return;
	re int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
}
int main(){
	int t=read();
	while(t--){
		long long ans=0;
		n=read(),m=read();
		for(re int i=1;i<=n;++i)a[i]=C[i]=read(),P[i]=i;
		for(re int i=1;i<=m;++i)b[i]=read();sort(b+1,b+m+1);
		p1=p2=1;
		sort(P+1,P+n+1,cmp);
		sort(b+1,b+m+1);
		build(1,1,n);
		for(re int i=1;i<=m;++i){
			while(p1<=n&&a[P[p1]]<=b[i])add(1,1,n,P[p1],n,-1),++p1;
			while(p2<=n&&a[P[p2]]<b[i])add(1,1,n,P[p2],n,-1),++p2;
			ans+=p2-1+min(0,mn[1]);
		}
		sort(C+1,C+n+1);
		for(re int i=1;i<=n;++i)a[i]=lower_bound(C+1,C+n+1,a[i])-C;
		for(re int i=1;i<=n;++i)ans+=i-1-ask(a[i]),add(a[i]);
		for(re int i=1;i<=n;++i)c[i]=0;
		printf("%lld\n",ans);
	}
}