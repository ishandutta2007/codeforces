#include <bits/stdc++.h>
using namespace std;
int main(){
	long long x, y, z; cin >> x >> y >> z;
	long long ans = (x + y) / z;
	cout << ans << " ";
	x = x % z, y = y % z;
	if (x + y < z) cout << 0 << endl;
	else cout << z - max(x, y) << endl; 
	return 0;
}