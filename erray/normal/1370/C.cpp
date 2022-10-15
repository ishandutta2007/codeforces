#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int sn = n;
		int ct = 0;
		while (n % 2 == 0) {
			n /= 2;
			++ct;
		}
		bool pr = 1;
		for (int i = 2; i*i <= n; ++i) pr &= (n % i != 0);
		if ((ct == 1 && pr && n != 1) || (n == 1 && sn != 2)) cout << "FastestFinger";
		else cout << "Ashishgup";
		cout << '\n';
	}
}