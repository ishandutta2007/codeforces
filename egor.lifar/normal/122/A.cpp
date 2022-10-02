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


bool happy(int x) {
    bool b = true;
    while(x > 0) {
        if (x % 10 != 4 && x % 10 != 7) {
            b = false;
        }
        x = x / 10;
    }
    return b;
}


int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            if (happy(i)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}