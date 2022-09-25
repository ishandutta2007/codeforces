#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a[11],pw10[10];
void Solve(){
	cin>>n>>k;
	++k;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	ll ans=0;
	for(int i=2;i<=n;++i){
		if(k<=pw10[a[i]-a[i-1]]-1){
			cout<<ans+pw10[a[i-1]]*k<<'\n';
			return;
		}
		k-=pw10[a[i]-a[i-1]]-1;
		ans+=(pw10[a[i]-a[i-1]]-1)*pw10[a[i-1]];
	}
	cout<<ans+1LL*pw10[a[n]]*k<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	pw10[0]=1;
	for(int i=1;i<=9;++i)pw10[i]=pw10[i-1]*10;
	while(T--){
		Solve();
	}
	return 0;
}