#include<bits/stdc++.h>
const int mod=998244353,g=3,invg=998244354/3,inv2=998244354/2;
using namespace std;
int a[400005],b[400005],c[400005],d[400005],n,k,tr[400005],wk[400005];
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
void Calcinv(int a[],int b[],int l){
	if(l==1){
		b[0]=Power(a[0],mod-2,mod);
		return ;
	}
	Calcinv(a,b,(l+1)/2);
	int len=1;
	while(len<l*2)len<<=1;
	GetTr(len);
	static int tmp[400005]={0};
	memcpy(tmp,a,sizeof(int)*l);
	for(int i=l;i<len;i++)tmp[i]=0;
	NTT(tmp,len,1),NTT(b,len,1);
	for(int i=0;i<len;i++)b[i]=(2-1ll*tmp[i]*b[i]%mod+mod)%mod*b[i]%mod;
	NTT(b,len,-1);
	for(int i=l;i<len;i++)b[i]=0;
}
void Calcln(int a[],int b[],int l){
	static int tmp[400005]={0};
	memcpy(tmp,a,sizeof(int)*l);
	for(int i=1;i<l;i++)tmp[i-1]=1ll*tmp[i]*i%mod;
	tmp[l-1]=0;
	Calcinv(a,b,l);
	int len=1;
	while(len<l*2)len<<=1;
	GetTr(len);
	for(int i=l;i<len;i++)tmp[i]=0;
	NTT(b,len,1),NTT(tmp,len,1);
	for(int i=0;i<len;i++)b[i]=1ll*tmp[i]*b[i]%mod;
	NTT(b,len,-1);
	for(int i=l;i<len;i++)b[i]=0;
	for(int i=l-1;i>0;i--)b[i]=1ll*b[i-1]*Power(i,mod-2,mod)%mod;
	b[0]=0;
}
void Calcexp(int a[],int b[],int l){
	if(l==1){
		b[0]=1;
		return ;
	}
	static int tmp[400005]={0},ln[400005]={0};
	Calcexp(a,b,(l+1)/2);
	Calcln(b,ln,l);
	memcpy(tmp,a,sizeof(int)*l);
	int len=1;
	while(len<=l*1.5)len<<=1;
	GetTr(len);
	NTT(tmp,len,1),NTT(ln,len,1),NTT(b,len,1);
	for(int i=0;i<len;i++)b[i]=1ll*b[i]*(1ll-ln[i]+tmp[i]+mod)%mod;
	NTT(b,len,-1);
	fill(b+l,b+len,0);
	fill(tmp,tmp+len,0);
	fill(ln,ln+len,0);
}
int main() {
	scanf("%d%d",&n,&k);
	int l=min(n,k);
	a[0]=1,a[1]=6,a[2]=1,Calcln(a,b,l+1);
	for(int i=0;i<=l;i++)b[i]=1ll*b[i]*inv2%mod;
	memset(a,0,sizeof(a)),Calcexp(b,a,l+1),Calcinv(a,c,l+1);
	a[0]++,a[1]++;
	for(int i=0;i<=l;i++)a[i]=1ll*a[i]*inv2%mod;
	Calcln(a,d,l+1);
	for(int i=0;i<=l;i++)d[i]=1ll*d[i]*(n+1)%mod;
	memset(a,0,sizeof(a)),Calcexp(d,a,l+1);
	int len=1;
	while(len<=2*l)len<<=1;
	GetTr(len),NTT(a,len,1),NTT(c,len,1);
	for(int i=0;i<len;i++)a[i]=1ll*a[i]*c[i]%mod;
	NTT(a,len,-1);
	for(int i=1;i<=l;i++)printf("%d ",a[i]);
	for(int i=l+1;i<=k;i++)printf("0 ");
	return 0;
}