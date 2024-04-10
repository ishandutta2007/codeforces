#include <bits/stdc++.h>
using namespace std;
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T; T --) {
		int n, m;
		cin >> n >> m;
		if(n & 1) {
			if(m < n) cout << "No\n"; 
			else {
				cout << "Yes\n";
				for(int i = 0; i < n - 1; i ++) cout << 1 << ' ', m --;
				cout << m << '\n';
			}
		}
		else {
			if(m < n || m % 2 == 1) cout << "No\n"; 
			else {
				cout << "Yes\n";
				for(int i = 0; i < n - 2; i ++) cout << 1 << ' ', m --;
				cout << m / 2 << ' ' << m / 2 << '\n';
			}
		}
	}
	return 0;
}