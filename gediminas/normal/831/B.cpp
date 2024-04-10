/*input
mnbvcxzlkjhgfdsapoiuytrewq
asdfghjklqwertyuiopzxcvbnm
7abaCABAABAcaba7
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	string a, b;
	cin >> a >> b;
	map<char, char>ch;

	for (int i = 0; i < 26; i++) {
		ch[a[i]] = b[i];
		ch[toupper(a[i])] = toupper(b[i]);
	}

	string c;
	cin >> c;

	for (int i = 0; i < c.size(); i++) {
		if (isalpha(c[i]))
			cout << ch[c[i]];
		else
			cout << c[i];
	}


	return 0;
}