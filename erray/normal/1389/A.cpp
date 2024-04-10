#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int l, r;
		cin >> l >> r;
		if (r < l * 2) cout << "-1 -1\n";
		else cout << l << ' ' << l * 2 << '\n';
	}
}