/*input
4
3 1 2 3
2 2 3
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	bool mas[n] = {};
	int cc = n;

	int p;
	cin >> p;

	for (int i = 0; i < p; i++) {
		int x;
		cin >> x;
		x--;
		cc -= (mas[x] ^ 1);
		mas[x] = true;
	}

	cin >> p;

	for (int i = 0; i < p; i++) {
		int x;
		cin >> x;
		x--;
		cc -= (mas[x] ^ 1);
		mas[x] = true;
	}

	if (cc == 0)
		cout << "I become the guy.";
	else
		cout << "Oh, my keyboard!";


	return 0;
}