#include<iostream>
#include<string>
#include<set>
using namespace std;
std::set<string> sset;
int n, m;
int cs;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		sset.insert(t);
	}
	cs = 0;
	for (int i = 0; i < m; i++) {
		string t;
		cin >> t;
		if (sset.find(t) != sset.end()) {
			cs++;
		}
	}
	if (n + cs % 2 <= m) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
	return 0;
}