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
	int n;
    cin >> n;
    int s = 1;
    for (int i = 1; i <= n - 1; i++) {
        s += i;
        s = s % n;
        if (s == 0) {
           s = n;
        }
        cout << s << ' ';
    }
    cout << endl;
	return 0;
}