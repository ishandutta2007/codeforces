#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		set <int> s;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			s.insert(x);
		}
		cout << s.size() << endl;
	}
	return 0;
}