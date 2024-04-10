#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int sum = 0;
		bool tf = false;
		int cnt = 0;
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if ((s[i] - '0') % 2 == 0) 
				cnt++;
			if (s[i] == '0')
				tf = true;
			sum += s[i] - '0';
		}
		if (sum % 3 == 0 && tf && cnt > 1)
			cout << "red" << endl;
		else
			cout << "cyan" << endl;
	}
	return 0;
}