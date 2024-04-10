#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b,c,h[100005];
ll ans=1e18;
ll f(int x){
	ll s1=0,s2=0;
	for(int i=1;i<=n;i++){
		if(h[i]<=x)s1+=x-h[i];
		else s2+=h[i]-x;
	}
	if(s1>=s2)return s2*c+(s1-s2)*a;
	else return s1*c+(s2-s1)*b;
}
int main(){
	cin>>n>>a>>b>>c,c=min(c,a+b);
	for(int i=1;i<=n;i++)cin>>h[i];
	sort(h+1,h+n+1);
	ll l=0,r=1e9;
	while(r-l>100){
		ll mid=(2*l+r)/3,mid2=(2*r+l)/3;
		if(f(mid)<f(mid2))r=mid2-1;
		else l=mid+1;
	}
	for(int i=l;i<=r;i++)ans=min(ans,f(i));
	cout<<ans;
    return 0;
}