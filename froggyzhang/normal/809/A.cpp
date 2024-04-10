#include<bits/stdc++.h>
using namespace std;
#define N 300030
const int mod=1e9+7;
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
int n,pw2[N],a[N],ans;
int main(){
	n=read();
	pw2[0]=1;
	for(int i=1;i<=n;++i){
		a[i]=read();
		(pw2[i]=pw2[i-1]<<1)%=mod;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		ans=(ans+1LL*(pw2[i-1]-pw2[n-i]+mod)%mod*a[i])%mod;	
	}
	printf("%d\n",ans);
	return 0;
}