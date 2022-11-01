#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	map <string, vector <int>> kek;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (kek[s].empty()) {
			kek[s].push_back(0);
			cout << "OK" << endl;
		}
		else {
			cout << s << kek[s].size() << endl;
			kek[s].push_back(kek[s].size());
		}
	}
	return 0;
}