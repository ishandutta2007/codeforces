#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n;
ll k,a[200005];
void Solve(){
	cin>>n>>k;
	ll ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i],a[i]+=a[i-1];
		ans=max(ans,a[i]-a[max(i-k,0ll)]);
	}
	ll w=1ll*k*(k-1)/2;
	if(k>n){
		w=1ll*((k-1)+(k-n))*n/2;
	}
	cout<<ans+w<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}