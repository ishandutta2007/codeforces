#include <bits/stdc++.h>
using namespace std;

long long f(long long n, long long x){
	long long ret = 0;
	while(n){
		ret += n/x;
		n /= x;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n;
	long long b;
	cin >> n >> b;
	long long ans = 1e18;
	for(long long x = 2; x*x <= b; x++){
		if(b%x)continue;
		int cnt = 0;
		while(b%x == 0){
			b /= x;
			cnt++;
		}
		ans = min(ans, f(n, x)/cnt);
	}
	if(b > 1)ans = min(ans, f(n, b));
	cout << ans << '\n';

	return 0;
}