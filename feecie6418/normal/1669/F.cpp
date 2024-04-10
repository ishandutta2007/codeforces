#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
void Solve(){
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];
	map<int,int> mp;
	for(int i=n;i>=1;i--){
		if(mp.count(a[i])){
			ans=max(ans,i+n-mp[a[i]]+1);
		}
		mp[a[n]-a[i-1]]=i;
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}