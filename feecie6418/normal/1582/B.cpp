#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[105];
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,s1=0,s2=1;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)if(a[i]==1)s1++;else if(a[i]==0)s2<<=1;
		cout<<s1*s2<<'\n';
	}
}