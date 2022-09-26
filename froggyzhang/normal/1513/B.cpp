#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define N 200020
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
int n,fac[N],a[N],T;
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=1LL*fac[i-1]*i%mod;
}
int Solve(){
	n=read();
	int all=(1<<30)-1;
	for(int i=1;i<=n;++i){
		a[i]=read();
		all&=a[i];
	}
	int zero=0;
	for(int i=1;i<=n;++i){
		a[i]^=all;
		zero+=(a[i]==0);
	}
	return 1LL*zero*(zero-1)%mod*fac[n-2]%mod;
}
int main(){
	init(200000);
	T=read();
	while(T--){
		printf("%d\n",Solve());
	}
	return 0;
}