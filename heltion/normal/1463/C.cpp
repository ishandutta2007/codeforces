#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(20);
	int T;
	for(cin >> T; T; T -= 1){
		int n, f = 0, g = 0, h = 0, k = 1E9, ans = 0;
		cin >> n;
		for(int i = 0, t, x; i < n; i += 1){
			cin >> t >> x;
			if(abs(f - g) <= t - h){
				if(abs(f - k) + abs(k - g) == abs(f - g)) ans += 1;
				f = g;
				g = x;
			}
			else{
				if(g > f){
					if(k >= f and k <= f + t - h) ans += 1;
					f += t - h;
				}
				else{
					if(k <= f and k >= f - t + h) ans += 1;
					f -= t - h;
				}
			}
			h = t;
			k = x;
		}
		if(abs(f - k) + abs(k - g) == abs(f - g)) ans += 1;
		cout << ans << "\n";
	}
	return 0;
}