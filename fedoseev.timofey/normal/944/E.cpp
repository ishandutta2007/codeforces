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

struct fenwick {
    vector <int> t;
    int n;
    fenwick(int nn) {
        t.resize(nn);
        n = nn;
    }
    int get(int r) {
        int mx = -1;
        for (int i = r; i >= 0; i &= i + 1, --i) {
            mx = max(mx, t[i]);
        }
        return mx;
    }
    void modify(int ind, int val) {
        for (int i = ind; i < n; i |= i + 1) {
            t[i] = max(t[i], val);
        }
    }
    void clear() {
        for (int i = 0; i < n; ++i) {
            t[i] = 0;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <int> pt(m);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        ++pt[l];
        if (r + 1 < m) --pt[r + 1];
    }
    for (int i = 1; i < m; ++i) pt[i] += pt[i - 1];
    vector <int> dpLeft(m), dpRight(m);
    fenwick f(n + 1);
    for (int i = 0; i < m; ++i) {
        dpLeft[i] = f.get(pt[i]) + 1;
        f.modify(pt[i], dpLeft[i]);
    }
    f.clear();
    for (int i = m - 1; i >= 0; --i) {
        dpRight[i] = f.get(pt[i]) + 1;
        f.modify(pt[i], dpRight[i]);
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        ans = max(ans, dpLeft[i] + dpRight[i] - 1);
    }
    cout << ans << '\n';
}