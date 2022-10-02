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


int n;


bool get(int x) {
    for (int i = 2; i < x; i++) {
        if (x % i == 0) {
            return true;
        }
    }
    return false;
}


int main() {
    cin >> n;
    for (int i = 4; i <= n; i++) {
        if (get(i) && get(n - i)) {
            cout << i << ' ' << n - i << endl;
            return 0;
        }
    }
    return 0;
}