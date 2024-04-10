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

int main() {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    int ans = 0;
    if ((x1 == 0 && x2 == n) || (x1 == n && x2 == 0)) {
        ans += min(y1 + y2, 2*n - y1 - y2);
    } else {
        ans += abs(y1 - y2);
    }

    if ((y1 == 0 && y2 == n) || (y1 == n && y2 == 0)) {
        ans += min(x1 + x2, 2*n - x1 - x2);
    } else {
        ans += abs(x1 - x2);
    }

    cout << ans << '\n';
    return 0;
}