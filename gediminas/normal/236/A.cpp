/*input
sevenkplus

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	string a;
	cin >> a;
	bool mas[26] = {};

	for (auto && x : a)
		mas[x - 'a'] = true;

	int ats = 0;

	for (int i = 0; i < 26; i++)
		ats += mas[i];

	cout << (ats % 2 ? "IGNORE HIM!" : "CHAT WITH HER!");


	return 0;
}