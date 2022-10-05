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

vector <ll> tmp;

ll my_pow(int a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        ll t = my_pow(a, n / 2);
        return t * t;
    }
    else {
        return my_pow(a, n - 1) * a;
    }
}

bool ok(ll x) {
    ll l = 0;
    ll r = 1e9 + 7;
    while (r - l > 1) {
        ll m = (r + l) / 2;
        if (m * m <= x) l = m;
        else r = m;
    }
    return l * l != x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int q;
    cin >> q;
    tmp.push_back(1);
    for (int d = 2; d <= (int)1e6; ++d) {
        ll last = 0;
        for (int p = 3; (ll)1e18 / d >= last; ++p) {
            last = my_pow(d, p);
            tmp.push_back(last);
        }
    }
    sort(tmp.begin(), tmp.end());
    tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
    vector <ll> good;
    for (auto x : tmp) {
        if (ok(x)) good.push_back(x);
    }
    for (int i = 0; i < q; ++i) {
        ll l, r;
        cin >> l >> r;
        ll ans = upper_bound(good.begin(), good.end(), r) - lower_bound(good.begin(), good.end(), l);
        ll left = 0;
        ll right = 1e9 + 7;
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            if (mid * mid < l) left = mid;
            else right = mid;
        }
        ll kek = right;
        left = 0;
        right = 1e9 + 7;
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            if (mid * mid <= r) left = mid;
            else right = mid;
        }
        ans += right - kek;
        cout << ans << endl;
    }
}