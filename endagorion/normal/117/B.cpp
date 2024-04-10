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

void printt(long long a, int d) {
    if (d == 0) {
        return;
    }
    printt(a / 10, d - 1);
    cout << a % 10;
}

int main() {
    long long a, b, mod;
    cin >> a >> b >> mod;
    for (long long p1 = 0; p1 <= a && p1 < mod; ++p1) {
        long long minp = 1000000000 * p1;
        long long maxp = 1000000000 * p1 + b;
        if (minp / mod == maxp / mod && minp % mod > 0) {
            cout << 1 << " ";
            printt(p1, 9);
            cout << '\n';
            return 0;
        }
    }
    cout << "2\n";
    return 0;
}