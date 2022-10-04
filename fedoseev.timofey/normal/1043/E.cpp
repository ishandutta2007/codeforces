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

// x1 + y2 < x2 + y1
// x1 - y1 < x2 - y2

vector <int> x, y;

bool cmp(int i, int j) {
    return x[i] - y[i] < x[j] - y[j];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    x.resize(n), y.resize(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    vector <int> u(m), v(m);
    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i];
        --u[i], --v[i];
    }
    vector <int> idx;
    for (int i = 0; i < n; ++i) idx.push_back(i);
    sort(idx.begin(), idx.end(), cmp);
    vector <ll> pref(n + 1), suf(n + 1);
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + x[idx[i - 1]];
    }
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] + y[idx[i]];
    }
    vector <ll> ans(n);
    for (int i = 0; i < n; ++i) {
        auto id = lower_bound(idx.begin(), idx.end(), i, cmp) - idx.begin();
        ans[i] = (ll)id * y[i] + (ll)(n - id) * x[i];
        ans[i] += pref[id] + suf[id];
        ans[i] -= x[i] + y[i];
    }
    for (int i = 0; i < m; ++i) {
        int cur = min(x[u[i]] + y[v[i]], y[u[i]] + x[v[i]]);
        ans[u[i]] -= cur;
        ans[v[i]] -= cur;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}