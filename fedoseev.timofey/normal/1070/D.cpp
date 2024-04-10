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

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    int have = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (have != 0) {
            int up = ((have + k - 1) / k) * k;
            int ost = up - have;
            x = max(0ll, x - ost);
            ans += up / k;
        }
        ans += x / k;
        x %= k;
        have = x;
    }
    ans += (have + k - 1) / k;
    cout << ans << '\n';
}