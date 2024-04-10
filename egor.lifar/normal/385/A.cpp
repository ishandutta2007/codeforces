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


int a[10000];


int main() {
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int s = 0;
    for (int i = 0; i < n - 1; i++) {
        int s1 = 0;
        s1 += a[i];
        if (s1 >= a[i + 1] + c) {
            s1 -= a[i + 1] + c;
            s = max(s, s1);
        }
    }
    cout << s << endl;
	return 0;
}