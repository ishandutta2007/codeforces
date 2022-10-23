// LUOGU_RID: 90914628
#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,c[150002],a[150002],pos[150002];
inline void Add(re int x){for(;x<=n;x+=x&(-x))++c[x];}
inline int ask(re int x,re int s=0){for(;x;x^=x&(-x))s+=c[x];return s;}
struct Seg{
	int p,mx[600002],se[600002],num[600002],tg[600002],len[600002];
	ll sum[600002];
	inline void pu(re int p){
		mx[p]=max(mx[p<<1],mx[p<<1|1]);
		se[p]=max(se[p<<1],se[p<<1|1]);
		num[p]=0;
		if(mx[p<<1]!=mx[p])se[p]=max(se[p],mx[p<<1]);
		else num[p]+=num[p<<1]; 
		if(mx[p<<1|1]!=mx[p])se[p]=max(se[p],mx[p<<1|1]);
		else num[p]+=num[p<<1|1]; 
		sum[p]=sum[p<<1]+sum[p<<1|1];
	}
	inline void build(re int p,re int l,re int r){
		len[p]=r-l+1;
		if(l==r){
			mx[p]=sum[p]=-1e9,se[p]=-1e9,num[p]=1;
			return;
		}
		re int mid=l+r>>1;
		build(p<<1,l,mid),build(p<<1|1,mid+1,r);
		pu(p);
	}
	inline void Add(re int x,re int y){tg[x]+=y,mx[x]+=y,sum[x]+=y*len[x],se[x]+=y;}
	inline void pd(re int p){
		if(tg[p])Add(p<<1,tg[p]),Add(p<<1|1,tg[p]),tg[p]=0;
		if(mx[p]<mx[p<<1])sum[p<<1]-=1ll*(mx[p<<1]-mx[p])*num[p<<1],mx[p<<1]=mx[p];
		if(mx[p]<mx[p<<1|1])sum[p<<1|1]-=1ll*(mx[p<<1|1]-mx[p])*num[p<<1|1],mx[p<<1|1]=mx[p];
	}
	inline void gmn(re int p,re int l,re int r,re int x,re int y,re int z){
		if(z>=mx[p])return;
		if(l>=x&&r<=y&&z>se[p]){
			sum[p]-=1ll*num[p]*(mx[p]-z),mx[p]=z;
			return;
		}
		if(l==r)return;
		pd(p);
		re int mid=l+r>>1;
		if(x<=mid)gmn(p<<1,l,mid,x,y,z);
		if(y>mid)gmn(p<<1|1,mid+1,r,x,y,z);
		pu(p);
	}
	inline void add(re int p,re int l,re int r,re int x,re int y,re int z){
		if(l>=x&&r<=y)return Add(p,z);
		pd(p);
		re int mid=l+r>>1;
		if(x<=mid)add(p<<1,l,mid,x,y,z);
		if(y>mid)add(p<<1|1,mid+1,r,x,y,z);
		pu(p);
	}
	inline void cg(re int p,re int l,re int r,re int x,re int y){
		if(l==r){
			mx[p]=sum[p]=y;
			return;
		}
		pd(p);
		re int mid=l+r>>1;  
		if(x<=mid)cg(p<<1,l,mid,x,y);
		else cg(p<<1|1,mid+1,r,x,y);
		pu(p);
	}
}T1,T2;
int main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read(),pos[a[i]]=i;
	T1.build(1,1,n),T2.build(1,1,n);
	for(re int i=1;i<=n;++i){
		re int x=pos[i];Add(x);re int o=ask(x);
		T1.cg(1,1,n,x,0),T2.cg(1,1,n,x,i+1);
		if(x<n)T1.add(1,1,n,x+1,n,-1),T2.add(1,1,n,x+1,n,1);
		if(x>1)T2.gmn(1,1,n,1,x-1,o);
		if(x<n)T1.gmn(1,1,n,x+1,n,-o);
		printf("%lld\n",T2.sum[1]+T1.sum[1]+2ll*(n-i)*1000000000-i);
	}
	
}