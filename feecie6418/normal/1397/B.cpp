#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005];
ll ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n>=45){
		for(int i=1;i<=n;i++)ans+=a[i]-1;
		return cout<<ans,0;
	}
	ans=1e18;
	for(int p=1;;p++){
		if(log(p)*(n-1)>log(1e10))break;
		ll t=0;
		for(ll i=1,o=1;i<=n;i++,o*=p)t+=abs(o-a[i]);
		ans=min(ans,t);
	}
	cout<<ans;
}