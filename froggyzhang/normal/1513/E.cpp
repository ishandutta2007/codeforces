#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define N 100010
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
map<int,int> mp;
int n,A,B,C,ans;
ll tot;
int fac[N],ifac[N],a[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
	}
}
int main(){
	n=read();
	init(n);
	for(int i=1;i<=n;++i){
		a[i]=read();
		tot+=a[i];
		++mp[a[i]];
	}
	if(tot%n)return !printf("0\n");
	tot/=n;
	for(int i=1;i<=n;++i){
		if(a[i]==tot)++C;
		else if(a[i]<tot)++A;
		else ++B;
	}
	if(C==n)return !printf("1\n");
	if(A==1||B==1){
		ans=fac[n];
		for(auto [x,w]:mp)ans=1LL*ans*ifac[w]%mod;	
	}
	else{
		ans=2LL*fac[A]*fac[B]%mod*fac[n]%mod*ifac[n-C]%mod;
		for(auto [x,w]:mp)ans=1LL*ans*ifac[w]%mod;
	}
	printf("%d\n",ans);
	return 0;
}