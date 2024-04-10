#include <iostream>

using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if ((c >= b - 1 && b >=(c + 1) / 2 - 1) || (d >= a - 1 && a >= (d + 1) / 2 - 1))
		cout <<"YES";
	else
		cout << "NO";
}