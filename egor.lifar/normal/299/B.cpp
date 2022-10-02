#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
 
using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int l = 0;
	int r = 0;
    while (l < n) {
    	int r1 = 0;
    	while(s[l + r1] == '#') {
    		r1++;
    	}
    	r = max(r, r1);
    	l+= r1 + 1;
    }
    if (r < k) {
    	cout << "YES" << endl;
    } else {
    	cout << "NO" << endl;
    }
	return 0;
}