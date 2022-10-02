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


int a[1000][100];


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> a[i][j];
    	}
    }
    cout << (m * (m - 1)) / 2 << endl;
    for (int i = 0; i < m; i++) {
    	for (int j = i + 1; j < m; j++) {
    		if (k == 0) {
    			cout << i + 1 << ' ' << j + 1 << endl;
    		} else {
    			cout << j + 1 << ' ' << i + 1 << endl;
    		}
    	}
    }
	return 0;
}