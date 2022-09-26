#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
	    x=(x<<3)+(x<<1)+c-'0';c=getchar();
	}
	return x*f;
}
ll x,y,n,m,a[10010],b[10010],k,lcm=1;
ll exgcd(ll a,ll b){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll gcd=exgcd(b,a%b);
	ll t=x;
	x=y;
	y=t-a/b*y;
	return gcd;
}
ll _gcd(ll a,ll b){
	if(b==0)return a;
	return _gcd(b,a%b);
}
ll mul(ll a,ll b,ll p){
	ll ans=0;
	while(b){
		if(b&1)ans=(ans+a)%p;
		a=(a+a)%p;
		b>>=1;
	}
	return ans;
}
ll china(){
	ll ans=b[1],lcm=a[1];
	for(int i=2;i<=k;i++){
		ll B=((b[i]-ans)%a[i]+a[i])%a[i];
		x=y=0;
		ll gcd=exgcd(lcm,a[i]);
		if(B%gcd!=0){
			return -1;
		}
		x=mul(x,B/gcd,a[i]);
		ans+=x*lcm;
		lcm=lcm/gcd*a[i];
		ans=(ans%lcm+lcm)%lcm;
	}
	ans=(ans+lcm-1)%lcm+1;
	if(ans<1||ans+k-1>m)return -1;
	return ans;
}
int main(){
	n=read();m=read();k=read();
	for(int i=1;i<=k;i++){
		a[i]=read();
		lcm=lcm*a[i]/_gcd(lcm,a[i]);
		if(lcm>n){
			cout<<"NO"<<endl;return 0;
		}
		b[i]=((a[i]-i+1)%a[i]+a[i])%a[i];
	}
	ll ans=china();
	if(ans==-1){
		cout<<"NO"<<endl;return 0;
	}
	for(int i=1;i<=k;i++){
		if(_gcd(lcm,ans+i-1)!=a[i]){
			cout<<"NO"<<endl;return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}