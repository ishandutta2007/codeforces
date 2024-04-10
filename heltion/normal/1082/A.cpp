#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --){
		LL n, x, y, d;
		cin >> n >> x >> y >> d;
		if((x - y) % d == 0) cout << abs(x - y) / d << endl;
		else {
			LL p1 = 1LL<< 60, p2 = 1LL << 60;
			if((y - 1) % d == 0) p1 = (x + d - 2) / d + (y - 1) / d;
			if((n - y) % d == 0) p2 = (n - x + d - 1) / d + (n - y) / d;
			if(min(p1, p2) < (1LL << 60)) cout << min(p1, p2) << endl;
			else cout << -1 << endl;
		}
	}
}