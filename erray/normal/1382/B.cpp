#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		string ans = "First";
		bool found = false, cur = false;
		int start = n;
		while (n--) {
			int x;
			cin >> x;
			if (x != 1 && !found) {
				found = true;
				if (cur) ans = "Second";
			}			
			cur ^= 1;
		}
		if (!found && start & 1 ^ 1) ans = "Second";
		cout << ans << '\n';
	}
}