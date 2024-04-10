// Codeforces Beta Round #70
// Problem D -- Archer's Shot
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

long long sqr (long long x) {
    return x * x;
}

bool isValid (long long x, long long y, long long r) {
    return x * x + 3 * y * y > 4 * r * r;
}

int main () {
    long long r;
    cin >> r;
    long long res = 0, i = -2, j = 2 * r, tmp = 0;
    while (j >= 0) {
        if (isValid(i, j, r) || isValid(i + 1, j - 1, r)) {
            j -= 2;
            continue;
        }
        res += j * tmp;
        i += 3;
        j += 3;
        if (tmp < 2) {
            tmp += 1;
        }
    }
    cout << res << endl;
    return 0;
}