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
#include <assert.h>


using namespace std;


int n1, n2, k1, k2;


int main() {
	cin >> n1 >> n2 >> k1 >> k2;
	if (n1 <= n2) {
		cout << "Second" << endl;
	} else {
		cout << "First" << endl;
	}
  	return 0;  
}