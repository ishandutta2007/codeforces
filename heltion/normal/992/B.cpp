#include<bits/stdc++.h> 
using namespace std;
using LL = long long; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	LL l, r, x, y, ans = 0;
	cin >> l >> r >> x >> y;
	if(y % x == 0){
		for(LL i = 1; i * i <= y / x; i += 1) if(y / x % i == 0){
			LL a = x * i, b = y / i;
			if(__gcd(a, b) == x)
			if(a >= l and a <= r and b >= l and b <= r) ans += 1 + (a != b);
		}
	}
	cout << ans;
	return 0;
}