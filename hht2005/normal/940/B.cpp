#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,k,a,b;
	long long ans=0;
	cin>>n>>k>>a>>b;
	if(k==1) {
		cout<<(n-1ll)*a<<endl;
		return 0;
	}
	while(n>=k) {
		ans+=1ll*(n-n/k*k)*a;
		n=n/k*k;
		if(b<1ll*(n-n/k)*a)ans+=b;
		else ans+=1ll*(n-n/k)*a;
		n/=k;
	}
	cout<<ans+(n-1ll)*a<<endl;
	return 0;
}