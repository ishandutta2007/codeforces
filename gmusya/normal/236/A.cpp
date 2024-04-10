#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector <bool> used(26);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		used[s[i] - 'a'] = true;
	int cnt = 0;
	for (int i = 0; i < 26; i++)
		cnt += used[i];
	if (cnt % 2 == 0)
		cout << "CHAT WITH HER!";
	else
		cout << "IGNORE HIM!";
	return 0;
}