#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,mod=998244353;
int sum[N<<2];
void build(int p,int l,int r) {
	sum[p]=r-l+1;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
}
int qry(int p,int l,int r,int k) {
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(k<=sum[p<<1])return qry(p<<1,l,mid,k);
	else return qry(p<<1|1,mid+1,r,k-sum[p<<1]);
}
void add(int p,int l,int r,int x,int v) {
	sum[p]+=v;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,v);
	else add(p<<1|1,mid+1,r,x,v);
}
int x[N],y[N],t[N],fac[N*2],inv[N*2];
set<int>S;
int C(int n,int m) {
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main() {
	int T,n,m,N=::N-10;
	scanf("%d",&T);
	build(1,1,N);
	fac[0]=1;
	for(int i=1;i<=2*N;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[2*N]=qpow(fac[2*N],mod-2);
	for(int i=2*N;i>=1;i--)inv[i-1]=1ll*inv[i]*i%mod;
	while(T--) {
		scanf("%d%d",&n,&m);
		S.clear();
		for(int i=1;i<=m;i++)
			scanf("%d%d",x+i,y+i);
		for(int i=m;i>=1;i--) {
			int p=qry(1,1,N,y[i]),q=qry(1,1,N,y[i]+1);
			S.insert(q);
			add(1,1,N,p,-1);
			t[i]=p;
		}
		for(int i=1;i<=m;i++)
			add(1,1,N,t[i],1);
		printf("%d\n",C(2*n-S.size()-1,n));
	}
	return 0;
}