#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
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
int n,m,a[4][500002],s[4][500002],v1[500002],v2[500002],L[500002],R[500002],W[500002],f[500002];
vector<int>V[500002];
struct SEG{
	int mn[2000002];
	inline void cg(re int p,re int l,re int r,re int x,re int y){
		if(l==r){
			mn[p]=y;
			return;
		}
		re int mid=l+r>>1;
		if(x<=mid)cg(p<<1,l,mid,x,y);
		else cg(p<<1|1,mid+1,r,x,y);
		mn[p]=max(mn[p<<1],mn[p<<1|1]);
	}
	inline int ask(re int p,re int l,re int r,re int x,re int y){
		if(x<1)x=1;
		if(y>n)y=n;
		if(x>y)return -1e18;
		if(l>=x&&r<=y)return mn[p];
		re int mid=l+r>>1,s=-1e18;
		if(x<=mid)s=max(s,ask(p<<1,l,mid,x,y));
		if(y>mid)s=max(s,ask(p<<1|1,mid+1,r,x,y));
		return s;
	}
}T1,T2;
int mx1[2000002],mx2[2000002],Mx,Mx1,Ans[2000002];
inline void build(re int p,re int l,re int r){
	if(l==r){
		mx1[p]=v1[l],mx2[p]=v2[l],Ans[p]=mx1[p]+mx2[p];
		return;
	}
	re int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
	mx1[p]=max(mx1[p<<1],mx1[p<<1|1]),mx2[p]=max(mx2[p<<1],mx2[p<<1|1]);
	Ans[p]=max(Ans[p<<1],Ans[p<<1|1]);
	Ans[p]=max(Ans[p],mx2[p<<1|1]+mx1[p<<1]);
}
inline void Ask(re int p,re int l,re int r,re int x,re int y){
	if(l>=x&&r<=y){
		Mx=max(Mx,Ans[p]);
		Mx=max(Mx,mx2[p]+Mx1),Mx1=max(Mx1,mx1[p]);
		return;
	}
	re int mid=l+r>>1;
	if(x<=mid)Ask(p<<1,l,mid,x,y);
	if(y>mid)Ask(p<<1|1,mid+1,r,x,y);
}
signed main(){
	n=read(),m=read();
	for(re int i=1;i<=3;++i)
		for(re int j=1;j<=n;++j)a[i][j]=read(),s[i][j]=s[i][j-1]+a[i][j];
	for(re int i=1;i<=m;++i)L[i]=read(),R[i]=read(),W[i]=read(),V[R[i]].push_back(i);
	for(re int i=1;i<=n;++i)v1[i]=s[1][i]-s[2][i-1],v2[i]=s[3][n]-s[3][i-1]+s[2][i];
	build(1,1,n);
	for(re int i=1;i<=n;++i)T2.cg(1,1,n,i,s[1][i]-s[2][i-1]);
	for(re int i=1;i<=n;++i){
		f[i]=-1e18;
		for(re int j=0;j<V[i].size();++j){
			re int l=L[V[i][j]],r=R[V[i][j]],w=W[V[i][j]];
			re long long ss=-1e18;
			ss=max(ss,T1.ask(1,1,n,l-1,r-1)+s[2][i]-w);
			ss=max(ss,T2.ask(1,1,n,l,r)+s[2][i]-w);
			f[i]=max(f[i],ss);
		}
		T1.cg(1,1,n,i,f[i]-s[2][i]);
	}
	for(re int i=1;i<=n;++i)f[i]-=s[2][i];
	int ans=-1e18;
	for(re int i=1;i<=m;++i){
		Mx=-1e18,Mx1=-1e18;
		Ask(1,1,n,L[i],R[i]);
		ans=max(ans,Mx-W[i]);
	}
	for(re int i=1;i<=n;++i)v1[i]=f[i],v2[i]=s[2][i]-s[3][i-1]+s[3][n];
	build(1,1,n);
	for(re int i=1;i<=m;++i){
		Mx=-1e18,Mx1=-1e18;
		Ask(1,1,n,max(1ll,L[i]-1),R[i]);
		ans=max(ans,Mx-W[i]);
	}
	printf("%lld",ans);
}