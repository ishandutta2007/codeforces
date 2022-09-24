#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[5005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	ll ans=1e18;
	for(int i=1;i<=n;i++){
		ll cur=0,s=0;
		for(int j=i-1;j>=1;j--){
			cur--;
			s+=(-cur+a[j]-1)/a[j];
			cur=-(-cur+a[j]-1)/a[j]*a[j];
		}
		cur=0;
		for(int j=i+1;j<=n;j++){
			cur++;
			s+=(cur+a[j]-1)/a[j];
			cur=(cur+a[j]-1)/a[j]*a[j];
		}
		ans=min(ans,s);
	}
	cout<<ans;
}