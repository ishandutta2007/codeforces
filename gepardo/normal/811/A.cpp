#include <iostream>

using namespace std;

int main() {
	int vladik, valerich;
	cin >> vladik >> valerich;
	for (int i = 1; ; i++) {
		int &whoNow = (i & 1) ? vladik : valerich;
		if (whoNow < i) {
			cout << ((i & 1) ? "Vladik" : "Valera") << endl;
			break;
		} else {
			whoNow -= i;
		}
	}
	return 0;
}