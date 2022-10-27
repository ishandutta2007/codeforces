#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		long long a, b, p, q;
		cin >> a >> b >> p >> q;
		if(q*a == p*b){
			cout << 0 << '\n';
		}else if(p == q){
			cout << -1 << '\n';
		}else if(p == 0){
			cout << -1 << '\n';
		}else{
			long long r = max((a + p - 1)/p, (b - a + q - p - 1)/(q - p));
			cout << r*q - b << '\n';
		}
	}

	return 0;
}