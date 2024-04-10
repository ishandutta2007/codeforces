#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	long long ans = 0;
	long long mn1 = LLONG_MAX;
	for(int i = 0; i < n; i++){
		long long x; cin >> x;
		if(x&1){
			mn1 = min(mn1, x);
		}
		ans += x;
	}
	if(ans&1){
		ans -= mn1;
	}
	cout << ans << '\n';

	return 0;
}