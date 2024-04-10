#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,a[50005],n,sum=0;
set<ll> s;
struct Thing {
	char opt;
	ll x,y;
} t[500005];
ll Exgcd(ll a,ll b,ll &x,ll &y) {
	if(!b) {
		x=1,y=0;
		return a;
	}
	ll ret=Exgcd(b,a%b,x,y),t=x;
	x=y,y=t-(a/b)*y;
	return ret;
}
void Add(ll a,ll b) {
	t[++sum]= {'+',a,b};
}
void Xor(ll a,ll b) {
	t[++sum]= {'^',a,b};
}
void Make(ll a,ll b) {
	ll t=0;
	for(int i=0; i<=60; i++)if((b-1)&(1ll<<i))t=i;
	for(int i=1; i<=t; i++)if(a*(1ll<<i-1)<2e18)Add(a*(1ll<<i-1),a*(1ll<<i-1));
	ll ans=a;
	for(int i=0; i<=t; i++)if((b-1)&(1ll<<i))Add(ans,a*(1ll<<i)),ans+=a*(1ll<<i);
}
void Print() {
	cout<<sum<<endl;
	for(int i=1; i<=sum; i++)printf("%lld %c %lld\n",t[i].x,t[i].opt,t[i].y);
}
bool Judge(ll x,ll y) {
	if(__gcd(x,y)>1)return 0;
	ll a,b,t=x*y;
	Exgcd(x,y,a,b);
	a=(a%y+y)%y,b=(a*x-1)/y;
	if((a*x)%2==1) {
		Make(x,a),Make(y,b);
		Xor(a*x,b*y);
		Print();
		return 1;
	}
	return 0;
}
void Do(){
	ll m1,m2,mn=1e18,mnp;//0+ 1^
	if(rand()&1){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((a[i]^a[j])<mn&&a[i]!=a[j]&&!s.count(a[i]^a[j]))mn=(a[i]^a[j]),m1=a[i],m2=a[j],mnp=1;
				if((a[i]+a[j])<mn&&!s.count(a[i]+a[j]))mn=(a[i]+a[j]),m1=a[i],m2=a[j],mnp=0;
			}
		}
		if(mnp==0)Add(m1,m2);
		else Xor(m1,m2);
		a[++n]=mn,s.insert(mn);
		for(int i=1;i<n;i++)if(Judge(mn,a[i])||Judge(a[i],mn))exit(0);
	}
	else {
		random_shuffle(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(!s.count(a[i]+a[j])){
					mn=(a[i]+a[j]),m1=a[i],m2=a[j],mnp=0;
					break;
				}
				if(a[i]!=a[j]&&!s.count(a[i]^a[j])){
					mn=(a[i]^a[j]),m1=a[i],m2=a[j],mnp=1;
					break;
				}
			}
		}
		if(mnp==0)Add(m1,m2);
		else Xor(m1,m2);
		a[++n]=mn,s.insert(mn);
		for(int i=1;i<n;i++)if(Judge(mn,a[i])||Judge(a[i],mn))exit(0);
	}
}
int main() {
	cin>>x,a[n=1]=x,s.insert(x);
	for(int i=1;i<=20;i++){
		Add(a[i],a[i]);
		n++;
		a[n]=a[n-1]*2;
		s.insert(a[n]);
	}
	while(1)Do();
 
}