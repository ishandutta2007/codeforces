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
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

ld pow(ld a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        ld t = pow(a, n / 2);
        return t * t;
    }
    return a * pow(a, n - 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int m, n;
    cin >> m >> n;
    ld ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans += i * (pow((ld)i / m, n) - pow((ld)(i - 1) / m, n));
    }
    cout << ans << '\n';
}