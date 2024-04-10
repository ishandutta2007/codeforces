#include <bits/stdc++.h>
#define ll long long
const int mod=998244353;
int n,m,r0,r1,coef=1,mask[60],ans[60],f[36][1<<17];
ll a[100005],b[60],E0[60],E1[60];
void inc(int &a,int b){a=(a+b)%mod;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		for(int j=m;j>=0;j--){
			if(a[i]&(1ll<<j)){
				if(b[j])a[i]^=b[j];
				else {b[j]=a[i];break;}
			}
		}if(!a[i])coef=coef*2%mod;
	}for(int i=m-1;i>=0;i--){
		if(!b[i]){E0[++r0]=i;continue;}
		E1[++r1]=i;
		for(int j=m;j>i;--j)
			if(b[j]&(1ll<<i))b[j]^=b[i];
	}for(int i=1;i<=r1;++i)
	for(int j=1;j<=r0;++j)
		if(b[E1[i]]&(1ll<<E0[j]))mask[i]|=(1<<(j-1));
	if(r1<=17){
		for(int S=0;S<(1<<r1);++S){
			ll w=0;
			for(int i=0;i<r1;++i)if((S>>i)&1)w^=b[E1[i+1]];
			ans[__builtin_popcountll(w)]++;
		}
	}else{
		f[0][0]=1;
		for(int i=1;i<=r1;++i)
		for(int j=r1;j>=0;--j)
		for(int S=0;S<(1<<r0);++S){
			inc(f[j+1][S^mask[i]],f[j][S]);
		}
		for(int j=0;j<=r1;++j)for(int S=0;S<(1<<r0);++S)
			inc(ans[j+__builtin_popcount(S)],f[j][S]);
	}for(int i=0;i<=m;++i)printf("%d ",(ll)ans[i]*coef%mod);
	return 0;
}