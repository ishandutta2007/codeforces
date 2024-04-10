#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n; 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		if(n%2050)puts("-1");
		else {
			n/=2050;
			int ans=0;
			while(n)ans+=n%10,n/=10;
			cout<<ans<<'\n';
		}
	}
}