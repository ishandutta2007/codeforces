#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	string s;
	cin >> s;
	int res = 0;
	int lastSt = -1;
	for(int i = 4; i <= s.size(); i++) {
		if(s.substr(i - 4, 4) == "bear") {
			lastSt = i - 4;
		}
		res += lastSt + 1;
	}
	cout << res << '\n';
	return 0;
}