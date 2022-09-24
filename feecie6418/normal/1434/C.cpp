#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,a,b,c,d;//d c healtime a b 
ll ff(ll s){
	ll ret=-s*a;
	ll p;
	ll times=min(s-1,(c-1)/d);
	p=s-1-times;
	//cout<<ret<<' '<<p<<endl;
	return ret+p*c*b+times*(d*b+d*b*times)/2;
}
ll f(ll a,ll b,ll c,ll d){
	ll l=1,r=1e7,m1,m2;
	while(r-l>50){
		m1=(l+l+r)/3,m2=(l+r+r)/3;
		ll f1=ff(m1),f2=ff(m2);
		if(f1<f2)r=m2;
		else l=m1;
	}
	ll ans=1e18;
	for(ll i=l;i<=r;i++)ans=min(ans,ff(i));
	return ans;
}
int main() {
	//a=10,b=10,c=10,d=8;
	//cout<<ff(10)<<endl;
	//return 0;
	cin>>t;
	while(t--){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(b*c<a)puts("-1");
		else printf("%lld\n",-f(a,b,c,d));
	}
}
/*
1
4 3 2 1
*/