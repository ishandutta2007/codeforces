#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	set <string> a, b, all;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		a.insert(s);
		all.insert(s);
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		b.insert(s);
		all.insert(s);
	}
	if ((a.size() + b.size() - all.size()) % 2 == 1)
		n++;
	if (n > m)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}