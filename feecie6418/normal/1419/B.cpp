#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll o=1,sum=0,ans=0;
		while(sum+o*(o+1)/2<=n)sum+=o*(o+1)/2,ans++,o=o*2+1;
		cout<<ans<<endl;
	}
}