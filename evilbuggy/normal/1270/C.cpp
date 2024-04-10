#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll x, sum = 0, xr = 0;
		for(int i = 0; i < n; i++){
			cin>>x;
			sum += x;
			xr ^= x;
		}
		cout<<2<<endl;
		cout<<xr<<" "<<(sum + xr)<<endl;
	}

	return 0;
}