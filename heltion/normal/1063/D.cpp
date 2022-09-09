#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	LL n, l, r, k, ans = -1;
	cin >> n >> l >> r >> k;
	LL x = r >= l ? r - l + 1 : r + n - l + 1, y = n - x;
	if(n <= k / n / n){
		for(LL a = 0; a <= x; a += 1)
			for(LL b = 0; b <= y; b += 1){
				LL c_1 = n + a + b, c_2 = k - a - x;
				if(c_2 >= 0 and c_2 % c_1 == 0) ans = max(ans, a + b);
			}
		for(LL a = 1; a <= x; a += 1)
			for(LL b = 0; b <= y; b += 1){
				LL c_1 = n + a + b, c_2 = k + 1 - a - x;
				if(c_2 >= 0 and c_2 % c_1 == 0) ans = max(ans, a + b);
			}
	}
	else{
		if(x <= k and 2 * x >= k) ans = max(ans, k - x + y); 
		for(LL t = 1; t <= k / n; t += 1){
			LL a = k - (t + 1) * x - t * y, b = -a;
			LL L = max((a - x + t - 1) / t, - b / (t + 1)), R = min(a / t, (y - b) / (t + 1));
			if(L <= R) ans = max(ans, a + b + R);
		} 
		if(x <= k + 1 and 2 * x >= k + 1) ans = max(ans, k - x + 1 + y); 
		for(LL t = 1; t <= (k + 1) / n; t += 1){
			LL a = k + 1 - (t + 1) * x - t * y, b = -a;
			LL L = max((a - x + t - 1) / t, - b / (t + 1)), R = min((a - 1) / t, (y - b) / (t + 1));
			if(L <= R) ans = max(ans, a + b + R);
		} 
	}
	cout << ans;
	
	return 0;
}