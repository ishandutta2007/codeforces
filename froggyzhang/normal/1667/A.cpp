#include<bits/stdc++.h>
using namespace std;
#define N 5005
typedef long long ll;
int n,a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	ll ans=1e18;
	for(int i=1;i<=n;++i){
		ll tmp=0;
		ll las=0;
		for(int j=i+1;j<=n;++j){
			ll zz=las/a[j]+1;
			tmp+=zz;
			las=zz*a[j];
		}
		las=0;
		for(int j=i-1;j>=1;--j){
			ll zz=las/a[j]+1;
			tmp+=zz;
			las=zz*a[j];
		}
		ans=min(ans,tmp);
	}
	cout<<ans<<'\n';
	return 0;
}