#include<bits/stdc++.h>
using namespace std;
int n,a[305];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1e9;
	for(int i=1;i+2<=n;i++){
		ans=min(ans,a[i+2]-a[i]);
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}