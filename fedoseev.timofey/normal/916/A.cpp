#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

bool check(int x) {
    while (x > 0) {
        if (x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}

int main() {
    int x, h, m;
    cin >> x >> h >> m;
    int best = 1e9;
    for (int ho = 0; ho < 24; ++ho) {
        for (int mi = 0; mi < 60; ++mi) {
            if (!check(ho) && !check(mi)) continue;
            int delta = 0;
            delta = (h - ho) * 60 + m - mi;
            if (delta < 0) delta += 24 * 60;
            if (delta % x == 0) {
                best = min(best, delta / x);
            }
        }
    }
    cout << best << endl;
}