#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <char> c(n);
	vector <bool> tf(26);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < n; i++) {
		if (c[i] >= 'A' && c[i] <= 'Z')
			tf[c[i] - 'A'] = true;
		else
			tf[c[i] - 'a'] = true;
	}
	bool ans = true;
	for (int i = 0; i < 26; i++)
		if (!tf[i])
			ans = false;
	if (ans)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}