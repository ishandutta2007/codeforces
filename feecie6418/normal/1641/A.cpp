#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int a[200005],X,n;
void Solve(){
	scanf("%d%d",&n,&X);
	map<ll,int> mp;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=n;i>=1;i--){
		if(mp[1ll*X*a[i]]){
			mp[1ll*X*a[i]]--;
			continue;
		}
		mp[a[i]]++;
	}
	for(auto i:mp)ans+=i.second;
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}