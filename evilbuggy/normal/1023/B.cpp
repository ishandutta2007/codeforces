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

	ll n, k;
	cin>>n>>k;
	ll l = max(1LL, k - n);
	ll r = min(k - 1, n);
	ll ans = max(0LL, r - l + 1);
	if(k%2 == 0 && l <= k/2 && k/2 <= r){
		ans--;
	}
	ans /= 2;
	cout<<ans<<endl;

	return 0;
}