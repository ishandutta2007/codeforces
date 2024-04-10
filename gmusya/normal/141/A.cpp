#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector <int> a(26);
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	for (int i = 0; i < s1.size(); i++)
		a[s1[i] - 'A']++;
	for (int i = 0; i < s2.size(); i++)
		a[s2[i] - 'A']++;
	for (int i = 0; i < s3.size(); i++)
		a[s3[i] - 'A']--;
	bool tf = true;
	for (int i = 0; i < 26; i++)
		if (a[i] != 0)
			tf = false;
	if (tf)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}