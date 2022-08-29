#include<bits/stdc++.h>
#define re register
#define int long long
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
int t,n,m,a[1000002],ans,A,B,vis[1000002],sum[100002],Sum[400002],sz[400002],oo;
char s[1000002];
inline void add(re int p,re int l,re int r,re int x){
	Sum[p]+=x,++sz[p];
	if(l==r)return;
	re int mid=l+r>>1;
	if(x<=mid)add(p<<1,l,mid,x);
	else add(p<<1|1,mid+1,r,x);
}
inline int ask(re int p,re int l,re int r,re int x){
	if(l==r)return x/l;
	re int mid=l+r>>1;
	if(Sum[p<<1]>=x)return ask(p<<1,l,mid,x);
	return ask(p<<1|1,mid+1,r,x-Sum[p<<1])+sz[p<<1];
}
inline void build(re int p,re int l,re int r){
	Sum[p]=sz[p]=0;
	if(l==r)return;
	re int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
}
signed main(){
	t=read();
	while(t--){
		n=read(),m=read(),ans=1e9,build(1,1,n);
		for(re int i=1;i<=n;++i)vis[i]=0;oo=0;
		for(re int i=1;i<=n;++i)a[i]=read()+1;
		map<int,int>V;
		for(re int i=1;i<=n;++i){
			++V[a[i]];
			if(a[i]<=n)vis[a[i]]=1;
		}
		for(re int i=1;i<=n;++i)sum[i]=sum[i-1]+(!vis[i]);
		ans=V.size();
		for(auto o:V)if(o.first>n)add(1,1,n,o.second),++oo;
		for(re int i=n;i;--i){
			if(sum[i]<=m){
				re int xx=m>=Sum[1]?sz[1]:ask(1,1,n,m);
				ans=min(ans,oo-xx);
			}
			if(V.count(i))add(1,1,n,V[i]),++oo;
		}
		printf("%lld\n",ans);
	}
}