#include<bits/stdc++.h>
using namespace std;
#define N 50005
const int mod=998244353;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,a[N][22],ans;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	n=read(),m=read();
	int fac=1;
	for(int j=1;j<=n;++j){
		for(int i=1;i<=m;++i){
			a[i][j]=read();
		}
		fac=1LL*fac*j%mod;
	}
	for(int i=1;i<=m;++i){
		sort(a[i]+1,a[i]+n+1,greater<int>());
		int p=0;
		int t=1;
		for(int j=n;j>=1;--j){
			while(p<n&&a[i][p+1]>j)++p;
			t=1LL*t*(p-(n-j))%mod;
		}
		ans=(ans+fac-t)%mod;
	}
	ans=(ans+mod)%mod;
	for(int i=1;i<=n;++i){
		ans=1LL*ans*qpow(i,mod-2)%mod;
	}
	printf("%d\n",ans);
	return 0;
}