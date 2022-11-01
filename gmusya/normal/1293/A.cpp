#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, s, k;
		cin >> n >> s >> k;
		set <int> closed;
		for (int i = 0; i < k; i++) {
			int x;
			cin >> x;
			closed.insert(x);
		}
		int var1 = 10000, var2 = 10000;
		for (int i = s; i > 0; i--) 
			if (closed.find(i) == closed.end()) {
				var1 = s - i;
				break;
			}
		for (int i = s; i <= n; i++)
			if (closed.find(i) == closed.end()) {
				var2 = i - s;
				break;
			}
		cout << min(var1, var2) << endl;
	}
	return 0;
}