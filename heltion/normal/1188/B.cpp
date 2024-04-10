//Author: Heltion
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 0;
map<LL, LL> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	LL n, p, k, a, x, ans = 0;
	cin >> n >> p >> k;
	for(int i = 0; i < n; i += 1){
		cin >> a;
		x = ((a * a % p * a % p * a % p  - k * a % p) % p + p ) % p;
		ans += mp[x];
		mp[x] += 1;
	}
	cout << ans;
	return 0;
}