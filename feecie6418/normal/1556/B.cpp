#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005];
void Solve(){
	cin>>n;
	int cnt[2]={0};
	for(int i=1;i<=n;i++)cin>>a[i],a[i]%=2,cnt[a[i]]++;
	ll ans=1e18;
	if(cnt[1]==n/2){
		ll sum=0,cnt=0;
		for(int i=1;i<=n;i++)if(a[i]==1)cnt++,sum+=abs(i-2*cnt);
		ans=min(ans,sum);
	}
	if(cnt[1]==(n+1)/2){
		ll sum=0,cnt=0;
		for(int i=1;i<=n;i++)if(a[i]==1)cnt++,sum+=abs(i-(2*cnt-1));
		ans=min(ans,sum);
	}
	if(ans<1e14)cout<<ans<<'\n';
	else cout<<"-1\n";
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}