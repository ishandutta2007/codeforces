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

long long div(long long a, long long b) {
    if (a >= 0) {
        return a / b;
    }
    return -((-a - 1) / b) - 1;
}

int main() {
    long long a, b, x1, y1, x2, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    if (a == 1) {
        b = 1;
    }
    if (b == 1) {
        a = 1;
    }
    a *= 2;
    b *= 2;
    int X1 = div(x1 + y1, a);
    int Y1 = div(x1 - y1, b);
    int X2 = div(x2 + y2, a);
    int Y2 = div(x2 - y2, b);

    cout << max(abs(X1 - X2), abs(Y1 - Y2)) << '\n';

    return 0;
}