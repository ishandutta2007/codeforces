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

	int n, a, b;
	cin>>n;

	vector<ll> arr;
	ll A = 0, B = 0;
	for(int i = 1; i <= n; i++){
		cin>>a>>b;
		arr.push_back(a - b);
		A += a;
		B += b;
	}
	sort(arr.begin(), arr.end());
	ll ans = B*n - A;
	for(int i = 0; i < n; i++){
		ans += arr[i]*(n-i);
	}
	cout<<ans<<endl;

	return 0;
}