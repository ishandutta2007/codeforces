#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<int> right;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'l')
			right.push_back(i+1);
		else
			printf("%d\n", i+1);
	}
	for (int i = right.size()-1; i >= 0; i--)
		printf("%d\n", right[i]);
	return 0;
}