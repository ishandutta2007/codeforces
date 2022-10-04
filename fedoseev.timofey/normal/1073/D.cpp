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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n; ll T;
    cin >> n >> T;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll ans = 0;
    bool fl = 1;
    while (fl) {
        fl = 0;
        ll cur = 0;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (cur + a[i] <= T) {
                fl = 1;
                cur += a[i];
                ++count;
            }
        }
        if (cur) {
            ans += (ll)(T / cur) * count;
            T %= cur;
        }
    }
    cout << ans << '\n';
}