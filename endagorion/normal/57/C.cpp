#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

const long long P = 1000000007;

long long deg(long long x, int d) {
    if (d == 0) {
        return 1;
    }
    long long y = deg(x, d / 2);
    y = (y * y) % P;
    if (d % 2) {
        y = (y * x) % P;
    }
    return y;
}

long long inv(long long x) {
    return deg(x, P - 2);
}

int main() {
    long long n;
    cin >> n;
    vector< long long > fact(2 * n);
    fact[0] = 1;
    for (long long x = 1; x <= 2 * n - 1; ++x) {
        fact[x] = (fact[x - 1] * x) % P;
    }

    long long result = fact[2 * n - 1];
    result = (result * inv(fact[n])) % P;
    result = (result * inv(fact[n - 1]) * 2) % P;
    result = (result + P - n) % P;
    cout << result << '\n';

    return 0;
}