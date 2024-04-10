#include <iostream>
#include <vector>
#include <string>
#include <set>

#define endl '\n'
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <string> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	set <string> used;
	vector <string> ans;
	for (int i = n - 1; i >= 0; i--) {
		if (used.find(s[i]) != used.end())
			continue;
		ans.push_back(s[i]);
		used.insert(s[i]);
	}
	for (auto now : ans)
		cout << now << endl;
	return 0;
}