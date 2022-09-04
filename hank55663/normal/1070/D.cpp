#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
ll a[200005];
int main(){
	scanf("%lld%lld",&n,&k);
	ll ans = 0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		ll now;
		if(i==n){
			now = a[i] + a[i-1];
		}
		else{
			now = max(a[i-1],(a[i] + a[i-1])/k*k);
		}
	
		now = (now+k-1)/k*k;
		//cout<<"now = "<<now<<endl;
		ans+=now/k;
		now -= a[i-1];
		a[i] = max(0ll,a[i]-now);
	}
	printf("%lld\n",ans);
	
	return 0;
}