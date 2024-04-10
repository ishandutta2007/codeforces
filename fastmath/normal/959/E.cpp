#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
#define int long long

const int LG = 60;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; n != 1; ++i) {
        int ed = n / 2;
        ans += ed * (1ll << i);
        n = (n + 1) / 2;
    }

    cout << ans << '\n';
    return 0;
}