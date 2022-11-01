#include <iostream>
#include <vector>
#include <string>

#define endl '\n'

using namespace std;

int main() {
	int t;
	cin >> t;
	vector <string> answer;
	while (t--) {
		string a, b, c;
		cin >> a >> b >> c;
		bool tf = true;
		for (int i = 0; i < a.size(); i++) {
			if ((a[i] != c[i]) && (b[i] != c[i]))
				tf = false;
		}
		if (tf)
			answer.push_back("YES");
		else
			answer.push_back("NO");
	}
	for (auto now : answer)
		cout << now << endl;
	return 0;
}