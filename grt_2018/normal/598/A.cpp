#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		int p = log2(n);
		long long sum = (long long)n*(n+1)/2;
		sum-=2*((1<<(p+1))-1);
		cout<<sum<<"\n";
	}
	return 0;
}