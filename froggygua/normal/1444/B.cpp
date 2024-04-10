#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 300030
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
int n,a[N],ans,inv[N];
int main(){
	n=read();
	for(int i=1;i<=n<<1;++i){
		a[i]=read();
	}
	sort(a+1,a+(n<<1)+1);
	for(int i=1;i<=n;++i){
		ans=(ans-a[i]+mod)%mod;
	}
	for(int i=n+1;i<=(n<<1);++i){
		ans=(ans+a[i])%mod;
	}
	for(int i=(n<<1);i>=n+1;--i){
		ans=1LL*ans*i%mod;
	}
	inv[1]=1;
	for(int i=2;i<=n;++i){
		inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
		ans=1LL*ans*inv[i]%mod;
	}
	printf("%d\n",ans);
	return 0;
}