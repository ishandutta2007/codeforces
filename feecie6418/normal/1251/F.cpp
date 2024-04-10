#include<bits/stdc++.h>
const int mod=998244353,g=3,invg=998244354/3,inv2=998244354/2;
using namespace std;
int a[1100005],b[1100005],c[10],cnt[1100005],n,k,q,ny[1100005]={1},jc[1100005]={1},tr[1100005],wk[1100005],ans[1100005];
int Power(int x,int y,int mod) {
	int ret=1;
	while(y) {
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
void GetTr(int l) {
	for(int i=0; i<l; i++)tr[i]=(tr[i>>1]>>1)|((i&1)?(l>>1):0);
}
void NTT(int a[],int n,int flag) {
	for(int i=0; i<n; i++)if(tr[i]<i)swap(a[i],a[tr[i]]);
	for(int i=1; i<n; i<<=1) {
		int w=Power(flag==1?g:invg,(mod-1)/(i<<1),mod);
		wk[0]=1;
		for(int j=1; j<i; j++)wk[j]=1ll*wk[j-1]*w%mod;
		for(int j=0; j<n; j+=(i<<1)) {
			for(int k=0; k<i; k++) {
				int t=1ll*wk[k]*a[i+j+k]%mod;
				a[i+j+k]=(a[j+k]-t+mod)%mod;
				a[j+k]=(a[j+k]+t)%mod;
			}
		}
	}
	if(flag==-1)for(int i=0,t=Power(n,mod-2,mod); i<n; i++)a[i]=1ll*a[i]*t%mod;
}
int C(int x,int y){
	return 1ll*jc[x]*ny[y]%mod*ny[x-y]%mod;
}
int main() {
	scanf("%d%d",&n,&k);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),cnt[x]++;
	for(int i=1;i<=k;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)jc[i]=1ll*jc[i-1]*i%mod;
	ny[n]=Power(jc[n],mod-2,mod);
	for(int i=n-1;i>=1;i--)ny[i]=1ll*(i+1)*ny[i+1]%mod;
	for(int j=1;j<=k;j++){
		int u=0,v=0,l=1;
		for(int i=1;i<c[j];i++)if(cnt[i]==1)u++;else if(cnt[i])v++;
		for(int i=0,t=1;i<=u;i++)a[i]=1ll*t*C(u,i)%mod,t=t*2%mod;
		for(int i=0;i<=2*v;i++)b[i]=C(2*v,i);
		while(l<=2*v+u)l<<=1;
		GetTr(l),NTT(a,l,1),NTT(b,l,1);
		for(int i=0;i<l;i++)a[i]=1ll*a[i]*b[i]%mod;
		NTT(a,l,-1);
		for(int i=0;i<l&&i+1+c[j]<=6e5;i++)ans[i+1+c[j]]=(ans[i+1+c[j]]+a[i])%mod;
		for(int i=0;i<l;i++)a[i]=b[i]=0;
	}
	scanf("%d",&q);
	for(int i=1,x;i<=q;i++)scanf("%d",&x),printf("%d\n",ans[x>>1]);
	return 0;
}