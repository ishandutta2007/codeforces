#include <iostream>
#include <vector>

using namespace std;

bool proverka(int x) {
	int n1, n2, n3, n4;
	n1 = x / 1000;
	n2 = x / 100 % 10;
	n3 = x / 10 % 10;
	n4 = x % 10;
	return (n1 != n2 && n1 != n3 && n1 != n4 && n2 != n3 && n2 != n4 && n3 != n4);
}

int main() {
	int n;
	cin >> n;
	n++;
	while (!proverka(n))
		n++;
	cout << n;
	return 0;
}