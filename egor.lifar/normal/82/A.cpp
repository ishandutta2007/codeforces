#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
 

using namespace std;


int n;
string s[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};


int main() {
	cin >> n;
	int p = 0;
	while (5 * (1 << p) < n) {
		n -= 5 * (1 << p);
		p++;
	}
	//cout << n << endl;
	int ss = 0;
	int k = (1 << p);
	while (k < n) {
		k += (1 << p);
		ss++;
	}
	cout << s[ss] << endl;
 	return 0;
}