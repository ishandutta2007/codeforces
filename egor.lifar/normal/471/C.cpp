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


long long n;


bool get(long long x) {
    if (x >= (int)sqrt(n)) {
        return false;
    }
    return n >= x * 2LL + (((x - 1) * x) / 2LL) * 3LL;
}


int main() {
    cin >> n;
    if (n < 2) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 2) {
        cout << 1 << endl;
        return 0;
    }
    long long l = 1;
    long long r = n / 3;
    while (l != r) {
        long long m = (l + r + 1) / 2;
        if (get(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    long long k = n % 3LL;
    if (k == 0LL) {
        cout << l / 3LL << endl;
        return 0;
    }
    if (k == 2LL) {
        cout << (l + 2LL) / 3LL << endl;
    } else {
        cout << (l + 1LL) / 3LL << endl;
    }
    return 0;
}