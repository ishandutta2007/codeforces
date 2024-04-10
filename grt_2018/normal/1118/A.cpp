#include <bits/stdc++.h>

using namespace std;

int q,a,b;
long long n;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>q;
	while(q--) {
		cin>>n>>a>>b;
		long long ans=0;
		if(n&1) ans=a;
		if(b<2*a) ans+=(n/2)*b;
		else ans+=(n/2)*a*2;
		cout<<ans<<"\n";
	}
	return 0;
}