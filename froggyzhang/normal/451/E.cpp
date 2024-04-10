#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 123
typedef long long ll;
const ll mod=1e9+7;
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,tot;
ll s,a[N],inv[N],ans;
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
ll C(ll n,ll m){
	if(n<0||m<0||m>n)return 0;
	if(n==0||m==0)return 1;
	n%=mod,m%=mod;
	ll ans=1;
	for(int i=0;i<m;i++){
		ans=ans*(n-i)%mod;
	}
	for(int i=1;i<=m;i++){
		ans=ans*inv[i]%mod;
	}
	return ans;
}
int main(){
	n=read(),s=read();tot=(1<<n)-1;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=20;i++){
		inv[i]=qpow(i,mod-2);
	}
	ans=C(n+s-1,n-1);
	for(int i=1;i<=tot;++i){
		int cnt=0;
		ll tmp=n+s;
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				++cnt,tmp-=a[j];
			}
		}
		tmp-=cnt+1;
		if(cnt&1){
			ans=(ans-C(tmp,n-1)+mod)%mod;
		}
		else{
			ans=(ans+C(tmp,n-1))%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}