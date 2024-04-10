#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=4e5+10;
struct pr{
	ll x,t;
	friend bool operator<(const pr&a,const pr&b){
		return a.x==b.x?a.t>b.t:a.x<b.x;
	}
}a[N];
int main(){int n,m=0;
	scanf("%d",&n);
	rep(i,1,n){
		ll l,r,t;
		scanf("%lld%lld%lld",&l,&r,&t);
		if(l+t<=r){
			a[++m]={l+t,t};
			a[++m]={r,-t};
		}
	}
	sort(a+1,a+m+1);ll nw=0;
	multiset<ll>s;s.insert((ll)2e18);
	ll ans=0;
	rep(i,1,m){
		ll x=a[i].x,t=abs(a[i].t),p=*s.begin();
		if(a[i].t>0){
            ll ls=x-t;
            if(nw<ls){
				ll w=(ls-nw-1)/p+1;
				ans+=w;nw=min(nw+w*p,x);
			}
			s.insert(t);
		}else{
			if(nw<x){
				ll w=(x-nw)/p;
				ans+=w;nw+=w*p;
			}
			s.erase(s.find(t));
		}
	}
	printf("%lld\n",ans);
}