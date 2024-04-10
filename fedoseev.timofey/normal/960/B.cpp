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

ll e(int a, int b) {
    return (ll)(a - b) * (a - b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    multiset <pair <ll, int>> q;
    for (int i = 0; i < n; ++i) {
        q.insert(make_pair(e(a[i], b[i]), i));
    }
    while (k1 || k2) {
        auto cur = *q.rbegin();
        q.erase(--q.end());
        int i = cur.second;
        if (k1) {
            if (a[i] > b[i]) --a[i];
            else ++a[i];
            --k1;
        }
        else {
            if (b[i] > a[i]) --b[i];
            else ++b[i];
            --k2;
        }
        q.insert(make_pair(e(a[i], b[i]), i));
    }
    ll ans = 0;
    for (auto p : q) {
        ans += p.first;
    }
    cout << ans << "\n";
}