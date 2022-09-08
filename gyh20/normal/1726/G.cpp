#include<bits/stdc++.h>
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
int t,n,m,a[1000002],b[1000002],ans,A[1000002],B[1000002],n1,n2,c[1000002],fac[1000002],inv[1000002],V[1000002],N2;
char s[1000002];
inline int C(re int x,re int y){return 1ll*fac[x]*inv[y]%M*inv[x-y]%M;}
struct Seg{
	int mn[800002],tg[800002],mnp[800002];
	inline void pu(re int p){
		mn[p]=min(mn[p<<1],mn[p<<1|1]);
		if(mn[p]==mn[p<<1|1])mnp[p]=mnp[p<<1|1];
		else mnp[p]=mnp[p<<1];
	}
	inline void Add(re int x,re int y){tg[x]+=y,mn[x]+=y;}
	inline void pd(re int p){
		if(tg[p]){
			Add(p<<1,tg[p]),Add(p<<1|1,tg[p]);
			tg[p]=0;
		}
	}
	inline void add(re int p,re int l,re int r,re int x,re int y,re int z){
		if(l>=x&&r<=y)return Add(p,z);
		pd(p);
		re int mid=l+r>>1;
		if(x<=mid)add(p<<1,l,mid,x,y,z);
		if(y>mid)add(p<<1|1,mid+1,r,x,y,z);
		pu(p);
	}
	inline void build(re int p,re int l,re int r){
		tg[p]=0;
		if(l==r){mn[p]=V[l],mnp[p]=l;return;}
		re int mid=l+r>>1;
		build(p<<1,l,mid),build(p<<1|1,mid+1,r);
		pu(p);
	}
}T1,T2;
inline void Mov1(re int x){
	T1.add(1,1,n1,x,x,1e9),x=A[x];
	re int pos=upper_bound(A+1,A+n1+1,x)-A;
	if(pos<=n1)T1.add(1,1,n1,pos,n1,-1);
	pos=lower_bound(B+1,B+n2+1,x)-B;
	if(pos<=N2)T2.add(1,1,n2,pos,N2,-1);
}
inline void Mov2(re int x){
	T2.add(1,1,n2,x,x,1e9),x=B[x];
	re int pos=upper_bound(A+1,A+n1+1,x)-A;
	if(pos<=n1)T1.add(1,1,n1,pos,n1,-1);
	pos=lower_bound(B+1,B+n2+1,x)-B;
	if(pos<=N2)T2.add(1,1,n2,pos,N2,-1);
}
inline void ck(re int X){
	n1=n2=0;
	for(re int i=1;i<=n;++i)
		if(b[i]==0)A[++n1]=a[i];
		else B[++n2]=a[i];
	sort(A+1,A+n1+1),sort(B+1,B+n2+1);
	for(re int i=1;i<=n1;++i)if(A[i]+c[A[i]-1]<X)return;
	for(re int i=1;i<=n2;++i)if(B[i]+n-1<X)return;
	for(re int i=1;i<=n1;++i)V[i]=A[i]+c[A[i]-1]-X;
	if(n1)T1.build(1,1,n1);else T1.mn[1]=1e9;
	for(re int i=1;i<=n2;++i)V[i]=X-(B[i]+n-c[B[i]]);
	if(n2)T2.build(1,1,n2);else T2.mn[1]=1e9;
	N2=n2;
	while(N2&&B[N2]==X)--N2; 
	re int num=0;
	while(num<n){
		++num;
		if(min(T1.mn[1],T2.mn[1])!=0)return;
		if(T1.mn[1]==0&&T2.mn[1]==0){
			re int p1=T1.mnp[1],p2=T2.mnp[1];
			if(A[p1]>B[p2])Mov1(p1);
			else Mov2(p2);
		}
		else if(T1.mn[1]==0)Mov1(T1.mnp[1]);
		else Mov2(T2.mnp[1]);
	}
	re int s=1;num=0;
	for(re int i=1;i<=n1;++i)
		if(A[i]==A[i-1])++num;
		else s=1ll*s*fac[num]%M,num=1;
	s=1ll*s*fac[num]%M,num=0;
	for(re int i=1;i<=n2;++i)
		if(B[i]==B[i-1])++num;
		else s=1ll*s*fac[num]%M,num=1;
	s=1ll*s*fac[num]%M;
	re int oo=0;
	for(re int i=1;i<=n2;++i)oo+=B[i]==X;
	s=1ll*s*C(n,oo)%M;
	add(ans,s);
}
int main(){
	n=1e6;
	for(re int i=fac[0]=inv[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2);
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read(),++c[a[i]];
	for(re int i=1;i<=n+n;++i)c[i]+=c[i-1];
	for(re int i=1;i<=n;++i)b[i]=read();
	re int mx=-1,mn=1e9;
	for(re int i=1;i<=n;++i)mx=max(mx,a[i]),mn=min(mn,a[i]);
	ck(mx);
	if(mn+n-1!=mx)ck(mn+n-1);
	printf("%d",ans);
}