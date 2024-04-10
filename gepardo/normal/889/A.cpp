#include <iostream>
#include <set>

using namespace std;

int main() {
	int n; cin >> n;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int q; cin >> q;
		s.insert(q);
	}
	cout << n + 1 - s.size() << endl;
	return 0;
}