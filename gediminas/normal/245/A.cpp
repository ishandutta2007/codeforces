#include <bits/stdc++.h>

using namespace std;
/*input
2
1 5 5
2 6 4

*/
/*input
3
1 0 10
2 0 10
1 10 0

*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int l[3]={}, d[3]={};

	for (int i = 0; i < n; ++i) {
		int t, a, b;
		cin >> t >> a >> b;
		l[t] += a;
		d[t] += b;
	}

	for (int i = 1; i < 3; ++i) {
		cout << (l[i] >= d[i] ? "LIVE" : "DEAD") << "\n";
	}
}