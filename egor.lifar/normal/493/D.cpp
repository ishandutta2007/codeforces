#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <set>
#include <map>


using namespace std;


int n;


int main() {
	cin >> n;
	if (n % 2 == 0) {
		cout << "white" << endl;
		cout << 1 << ' ' << 2 << endl;
	} else {
		cout << "black" << endl;
	}
    return 0;
}