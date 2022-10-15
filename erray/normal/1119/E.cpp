#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int ct = 0;
	long long ans = 0;
	while (n--) {
		int x;
		cin >> x;
		int mx = min(ct, x / 2);
		ct -= mx;
		x -= mx * 2;
		ans += mx + x / 3;
		ct += x % 3;		 
	}
	cout << ans;
}