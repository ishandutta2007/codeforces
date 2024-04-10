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

ll upgrade(int a, int n) {
    ll res = a;
    res *= 1ll << n;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, a, b;
    cin >> n >> a >> b;
    vector <pair <int, int>> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i].first >> x[i].second;
    }
    sort(x.begin(), x.end(), 
        [&](pair <int, int> &f, pair <int, int> &s) {
            return f.first - f.second > s.first - s.second;
    });
    ll sum = 0;
    for (auto e : x) {
        sum += e.second;
    }
    if (b == 0) {
        cout << sum << '\n';
        return 0;
    }
    ll can = 0;
    b = min(n, b);
    for (int i = 0; i < b; ++i) {
        can += max(0, x[i].first - x[i].second);
    }
    ll ans = sum + can;
    for (int i = 0; i < n; ++i) {
        ll cur = upgrade(x[i].first, a);
        if (i + 1 <= b) {
            ans = max(ans, sum - x[i].second + cur + can - max(0, x[i].first - x[i].second));
        }
        else {
            ans = max(ans, sum - x[i].second + cur + can - max(0, x[b - 1].first - x[b - 1].second));
        }
    }
    cout << ans << '\n';
}