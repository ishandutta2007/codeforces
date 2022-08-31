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

bool isInGrid(long long x, long long y, long long cx, long long cy) {
    if (cx == 0 && cy == 0) {
        return x == 0 && y == 0;
    }
    return (x * cx + y * cy) % (cx * cx + cy * cy) == 0 && (x * cy - y * cx) % (cx * cx + cy * cy) == 0;
}

int main() {
    long long ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    bool ok = isInGrid(bx - ax, by - ay, cx, cy);
    ok |= isInGrid(bx - ay, by + ax, cx, cy);
    ok |= isInGrid(bx + ax, by + ay, cx, cy);
    ok |= isInGrid(bx + ay, by - ax, cx, cy);
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}