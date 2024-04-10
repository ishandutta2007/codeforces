#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll k, t, d;
    cin >> k >> d >> t;
    d = ((k + d - 1) / d) * d;
    ll on = k;
    ll off = d - k;
    long double l = 0, r = 2e18 + 7;
    for (int i = 0; i < 300; ++i) {
        long double m = (l + r) / 2;
        long long x = m / d;
        long double res = m - x * d;
        long double f = min(res, (long double)on);
        long double s = max((long double)0, res - f);
        long double a = f + x * on;
        long double b = s + x * off;
        if (a / t + b / (2 * t) > 1) {
            r = m;
        }
        else {
            l = m;
        }
    }
    cout << fixed << setprecision(16) << (l + r) / 2 << endl;
}