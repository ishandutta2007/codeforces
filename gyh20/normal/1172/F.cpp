#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int n,m,M,a[1000002];
ll ans,sum[4000002],inf=1e18;
vector<ll>C[4000002];
inline void build(re int p,re int l,re int r){
	if(l==r){
		sum[p]=a[l];
		C[p].push_back(-inf),C[p].push_back(M-a[l]);
		return;
	}
	re int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r),sum[p]=sum[p<<1]+sum[p<<1|1];
	C[p].resize(r-l+2),C[p][0]=-inf;re int pos=0,pp=0;
	for(re int i=1;i<C[p].size();++i){
		while(pos<C[p<<1].size()){
			re ll tmp=sum[p<<1]+C[p<<1][pos]-1ll*pos*M;
			while(pp<C[p<<1|1].size()&&C[p<<1|1][pp]<=tmp)++pp;
			re int p1=pp-1;
			if(p1+pos<i)++pos;
			else break; 
		}
		re int o=i-(pos-1);
		if(o<C[p<<1|1].size()&&C[p<<1|1][o]-sum[p<<1]+1ll*(pos-1)*M>=C[p<<1][pos-1])C[p][i]=C[p<<1|1][o]-sum[p<<1]+1ll*(pos-1)*M;
		else C[p][i]=inf;
		if(pos<C[p<<1].size())C[p][i]=min(C[p][i],C[p<<1][pos]);
	}sum[p]=sum[p<<1]+sum[p<<1|1];
}
inline void ask(re int p,re int l,re int r,re int x,re int y){
	if(l>=x&&r<=y){
		ans-=1ll*(upper_bound(C[p].begin(),C[p].end(),ans)-C[p].begin()-1)*M,ans+=sum[p];
		return;
	}
	re int mid=l+r>>1;
	if(x<=mid)ask(p<<1,l,mid,x,y);
	if(y>mid)ask(p<<1|1,mid+1,r,x,y);
}
signed main(){
	n=read(),m=read(),M=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	build(1,1,n);
	while(m--){
		re int l=read(),r=read();ans=0,ask(1,1,n,l,r);
		printf("%lld\n",ans);
	}
}