#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,m;
ll a[N],sum;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	cin>>m;
	while(m--){
		ll x,y;
		cin>>x>>y;
		int u=lower_bound(a+1,a+n+1,x)-a;
		ll ans=2e18;
		if(u<=n)ans=min(ans,max(0LL,y-(sum-a[u])));
		if(u>1)ans=min(ans,x-a[u-1]+max(0LL,y-(sum-a[u-1])));
		cout<<ans<<'\n';
	}
	return 0;
}