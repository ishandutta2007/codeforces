#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>


using namespace std;



int n;


int main() {
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		cout << 1 << endl;
		return 0;
	}
	if (n == 2) {
		cout << 1 << endl;
		cout << 1 << endl;
		return 0;
	}
	if (n == 3) {
		cout << 2 << endl;
		cout << 1 << ' ' << 3 << endl;
		return 0;
	}
	if (n == 4) {
		cout << 4 << endl;
		cout << 3 << ' ' << 1 << ' ' << 4 << ' ' << 2 << endl;
		return 0;
	}
	cout << n << endl;
	for (int i = 1; i <= n / 2; i++) {
		cout << i << ' ' << (n / 2 + n % 2) + i << ' ';
	}
	if (n % 2 == 1) {
		cout << n / 2 + n % 2;
	}
	cout << endl;
    return 0;
}