#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main() {
	int foo=0, bar=0, baz=0, quz=1;
	int tux;
	cin >> tux;
	while (tux) {
		int pur;
		tux--;
		cin >> pur;
		foo+=pur;
		bar++;
		if (foo*quz>=bar*baz) {
			baz=foo;
			quz=bar;
		} else break;
	}
	cout << (double)baz/quz;
	return 0;
}