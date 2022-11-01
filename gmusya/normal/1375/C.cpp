#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		stack <int> s;
		for (int i = 1; i < n; i++) {
			while (!s.empty() && s.top() < a[i])
				s.pop();
			if (a[i] < a[0])
				s.push(a[i]);
		}
		if (s.empty()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}