#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		long long x;
		long long y;
		cin >> x >> y;
		if(x == y){
			cout << x << '\n';
		}else if(x < y){
			long long q = y/x;
			long long r = y%x;
			cout << q*x + r/2 << '\n';
		}else{
			cout << x + y << '\n';
		}
	}

	return 0;
}