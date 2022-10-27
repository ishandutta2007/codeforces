#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		int g = __gcd(k, 100 - k);
		cout << 100/g << '\n';
	}

	return 0;
}