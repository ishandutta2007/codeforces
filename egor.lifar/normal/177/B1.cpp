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


int d[50];


int main() {
    int n;
    cin >> n;
    d[0] = 0;
    d[1] = 1;
    d[2] = 3;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                d[i] = max(d[i], i + d[j]);
            }
        }
    }  
    cout << d[n] << endl;
    return 0;
}