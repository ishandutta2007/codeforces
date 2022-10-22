#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <time.h>
#include <algorithm>
#include <random>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int x = 0;
    int y = 0;
    for (int i = 0; i < n; ++i) {
        if (0 <= a[i]) x += a[i];
        else y += a[i];
    }

    cout << x - y << '\n';
    return 0;
}