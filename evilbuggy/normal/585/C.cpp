#include <bits/stdc++.h>
using namespace std;

string toString(long long a){
	string ret = "";
	while(a){
		ret += char('0' + a%10);
		a /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long x, y;
	cin >> x >> y;
	if(__gcd(x, y) != 1){
		cout << "Impossible" << '\n';
		exit(0);
	}
	string ans = "";
	while(x > 0 && y > 0){
		if(x > y){
			if(y == 1){
				ans += toString(x - 1);
			}else{
				ans += toString(x/y);
			}
			ans += 'A';
			x %= y;
		}else{
			if(x == 1){
				ans += toString(y - 1);
			}else{
				ans += toString(y/x);
			}
			ans += 'B';
			y %= x;
		}
	}
	cout << ans << '\n';

	return 0;
}