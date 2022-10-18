#include <bits/stdc++.h>
#define ll long long
const int mod=998244353;
const int lim=300000;
int f[15][300005],n,a[300005],fac[300005],ifac[300005],vis[300005]={0};
int qpow(int a,int b){
	if (b==0)return 1;
	int d=qpow(a,b>>1);d=(ll)d*d%mod;
	if (b&1)d=(ll)d*a%mod;
	return d;
}

int C(int n,int m){
	if (n<m)return 0;
	return (ll)fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

int main(){
	scanf("%d",&n);fac[0]=ifac[0]=1;
	for(int i=1;i<=lim;++i)fac[i]=(ll)fac[i-1]*i%mod;
	for(int i=1;i<=lim;++i)ifac[i]=qpow(fac[i],mod-2);
	for(int i=1;i<=n;++i){scanf("%d",&a[i]);vis[a[i]]++;}
	for(int i=1;i<=10;++i){
		for(int j=lim;j>=1;--j){
			int cnt=0;
			for(int k=j;k<=lim;k+=j)cnt+=vis[k];
			f[i][j]=C(cnt,i);//printf("C ( %d %d ) = %d\n",cnt,i,C(cnt,i));
			for(int k=j*2;k<=lim;k+=j)f[i][j]=(f[i][j]-f[i][k]+mod)%mod;
		}if (f[i][1]){printf("%d",i);return 0;}
	}printf("-1");
	return 0;
}