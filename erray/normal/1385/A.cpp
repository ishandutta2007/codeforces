#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		vector<int> a(3);
		cin >> a[0] >> a[1] >> a[2];
		sort(a.begin(), a.end());
		if (a[1] != a[2]) cout << "NO\n";
		else cout << "YES\n" << a[0] << ' ' << a[0] << ' ' << a[2]  << '\n';
	}
}