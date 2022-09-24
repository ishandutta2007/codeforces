#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
ll a[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		ll ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(i>1)ans+=-1ll*(i-2)*a[i]+a[i-2];
			a[i]+=a[i-1];
		}
		cout<<ans<<'\n';
	} 
}