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


long long n, a, b;


int main() {
    cin >> n >> a >> b;
    n = 6 * n;
    if (a * b >= n) {
        cout << a * b << endl;
        cout << a << ' ' << b << endl;
        return 0;
    }
    if (a <= b) {
        long long a1, b1;
        long long ans = 1000000000000;
        for (long long i = a; i <= (long long)(sqrt(n)) + 1; i++) {
            long long b2 = (n + i - 1) / i;
            if (b <= b2) {
                if (ans > i * b2) {
                    ans = i * b2;
                    a1 = i;
                    b1 = b2;
                }
            }
        }
        cout << ans << endl;
        cout << a1 << ' ' << b1 << endl;
    } else {
        long long a1, b1;
        long long ans = 1000000000000;
        for (long long i = b; i <= (long long)(sqrt(n)) + 1; i++) {
            long long a2 = (n + i - 1) / i;
            if (a <= a2) {
                if (ans > i * a2) {
                    ans = i * a2;
                    b1 = i;
                    a1 = a2;
                }
            }
        }
        cout << ans << endl;
        cout << a1 << ' ' << b1 << endl;
    }
    return 0;
}