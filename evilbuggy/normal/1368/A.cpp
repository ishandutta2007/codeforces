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
		ll a, b, n;
		cin>>a>>b>>n;
		if(a > b)swap(a, b);
		int ans = 0;
		while(b <= n){
			ll tmp = a + b;
			a = b;
			b = tmp;
			ans++;
		}
		cout<<ans<<'\n';
	}

	return 0;
}