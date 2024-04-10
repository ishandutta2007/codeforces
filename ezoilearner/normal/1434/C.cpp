#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d,T;
#define cout cerr
#define Maxn 100010

ll calc(ll x){
	ll ans=(a+b)*x;
	ans-=d*b*x*(x+1)/2;
	ans+=a-x*b;
	return ans;
}

int main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>c>>d;
		if(a>c*b){
			puts("-1");
			continue;
		}
		if(d>c){
			printf("%lld\n",a);
			continue;
		}
		ll res=a;
		ll l=1,r=c/d;
		while(r-l>3){
			ll mid1=l+(r-l)/3,mid2=l+(r-l)/3*2;
			if(calc(mid1)>calc(mid2))r=mid2;
			else l=mid1;
		}
		for(int i=l;i<=r;++i)res=max(res,calc(i));
		printf("%lld\n",res);
	}
	return 0;
}