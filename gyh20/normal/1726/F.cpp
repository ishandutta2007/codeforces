#include<bits/stdc++.h>
#define int long long
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
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
int t,n,m,a[1000002],ans,A[1000002],B[1000002],D[1000002],sum,L[1000002],R[1000002],tot,rt,inf=1e6,f[1000002],g[1000002],tg[4000002],C[4000002],ls[4000002],rs[4000002],X[4000002],ttt;
inline void Cov(re int p,re int x){tg[p]=C[p]=x;}
inline void pd(re int p){
	if(tg[p]){
		if(!ls[p])ls[p]=++tot;
		if(!rs[p])rs[p]=++tot;
		Cov(ls[p],tg[p]),Cov(rs[p],tg[p]),tg[p]=0;
	}
}
inline void Cov(re int &p,re int l,re int r,re int x,re int y,re int z){
	if(!p)p=++tot;
	if(l>=x&&r<=y)return Cov(p,z);
	pd(p);
	re int mid=l+r>>1;
	if(x<=mid)Cov(ls[p],l,mid,x,y,z);
	if(y>mid)Cov(rs[p],mid+1,r,x,y,z);
}
inline int ask(re int&p,re int l,re int r,re int x){
	if(l==r)return C[p];
	pd(p);
	re int mid=l+r>>1;
	if(x<=mid)return ask(ls[p],l,mid,x);
	else return ask(rs[p],mid+1,r,x);
}
signed main(){
	n=read(),t=read();
	for(re int i=1;i<=n;++i)A[i]=read(),B[i]=read();
	for(re int i=1;i<n;++i)D[i]=read(),ans+=D[i];
	for(re int i=1;i<=n;++i){
		L[i]=0,R[i]=A[i]-1;
		L[i]-=sum,R[i]-=sum;
		L[i]-=B[i],R[i]-=B[i];
		L[i]%=t,R[i]%=t;
		if(L[i]<0)L[i]+=t;
		if(R[i]<0)R[i]+=t;
		sum+=D[i];
	}
	for(re int i=1;i<=n;++i)X[++ttt]=L[i],X[++ttt]=R[i];
	sort(X+1,X+ttt+1);
	for(re int i=1;i<=n;++i)L[i]=lower_bound(X+1,X+ttt+1,L[i])-X,R[i]=lower_bound(X+1,X+ttt+1,R[i])-X;
	Cov(rt,0,inf,0,inf,n+1);
	for(re int i=n;i;--i){
		if(L[i]<=R[i]){
			if(L[i])Cov(rt,0,inf,0,L[i]-1,i);
			if(R[i]<inf)Cov(rt,0,inf,R[i]+1,inf,i);
		}
		else{
			if(L[i]!=R[i]+1)Cov(rt,0,inf,R[i]+1,L[i]-1,i);
		}
		re int pos=ask(rt,0,inf,R[i]);
		f[i]=g[pos];
		re int dlt=X[L[pos]]-X[R[i]];
		if(dlt<0)dlt+=t;
		if(pos==n+1)dlt=0;
		f[i]+=dlt;
		pos=ask(rt,0,inf,L[i]);
		g[i]=g[pos];
		dlt=X[L[pos]]-X[L[i]];
		if(dlt<0)dlt+=t;
		if(pos==n+1)dlt=0;
		g[i]+=dlt;
	}
	Cov(rt,0,inf,0,inf,-1);re int mn=1e18;
	for(re int i=1;i<=n;++i){
		if(L[i]<=R[i]){
			if(L[i])Cov(rt,0,inf,0,L[i]-1,i);
			if(R[i]<inf)Cov(rt,0,inf,R[i]+1,inf,i);
		}
		else{
			if(L[i]!=R[i]+1)Cov(rt,0,inf,R[i]+1,L[i]-1,i);
		}
		if(ask(rt,0,inf,R[i])==-1)mn=min(mn,f[i]);
	}printf("%lld",ans+mn);
}