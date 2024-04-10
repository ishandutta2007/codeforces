#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int r = abs(a - b);
    if (r % 2 == 0) {
        int t = r / 2;
        cout << t * (t + 1) << '\n';
    }
    else {
        int t1 = r / 2;
        int t2 = r / 2 + 1;
        cout << t1 * (t1 + 1) / 2 + t2 * (t2 + 1) / 2 << '\n';
    }

    return 0;
}