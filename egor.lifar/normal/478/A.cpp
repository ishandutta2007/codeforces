#include <iostream> 
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>


using namespace std;


int c[5];


int main() {
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		cin >> c[i];
		ans += c[i];
	}
	if (ans % 5 == 0 && ans != 0) {
		cout << ans / 5 << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}