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
    int minp = 100000;
    for (int i = 0; i < 4; ++i) {
        int p;
        cin >> p;
        minp = min(minp, p);
    }
    int a, b;
    cin >> a >> b;
    if (a >= minp) {
        cout << 0;
    } else {
        cout << min(minp - a, b - a + 1) << '\n';
    }
    return 0;
}