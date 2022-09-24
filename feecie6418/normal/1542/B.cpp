#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		int n,a,b,is=0;
		long long x=1;
		cin>>n>>a>>b;
		if(a==1){
			if(n%b==1%b)puts("Yes");
			else puts("No");
			continue;
		}
		while(x<=n){
			if(x%b==n%b)is=1;
			//cout<<x%b<<' '<<n%b<<endl;
			x*=a;
		}
		if(is)puts("Yes");
		else puts("No");
	}
	return 0;
}