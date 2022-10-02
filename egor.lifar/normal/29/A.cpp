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


int x[100], d[100];


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> d[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1 = d[i] + x[i];
            int x2 = d[j] + x[j];
            if (x1 == x[j] && x2 == x[i]) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
	return 0;
}