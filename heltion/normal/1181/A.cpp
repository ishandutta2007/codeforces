#include<bits/stdc++.h> 
using namespace std;
using LL = long long;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	LL x, y, z, ans;
	cin >> x >> y >> z;
	ans = x / z + y / z;
	x %= z; y %= z;
	if(x + y < z) cout << ans << " " << 0;
	else cout << ans + 1 << " " << z - max(x, y);
	return 0;
}