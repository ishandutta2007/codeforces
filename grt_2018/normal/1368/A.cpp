#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int a,b,n;
		cin >> a >> b >> n;
		int step = 0;
		while(max(a,b) <= n) {
			if(a < b) {
				a = b + a;
			} else {
				b = a + b;
			}
			step++;
		}
		cout << step << "\n";
	}
}