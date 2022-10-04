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
    int n;
    vector <int> t;
    fenwick(int nn) {
        t.resize(nn);
        n = nn;
    }
    fenwick() {}

    void modify(int x, int val) {
        for (int i = x; i < n; i |= i + 1) {
            t[i] += val;
        }
    }
    int get(int r) {
        int res = 0;
        for (int i = r; i >= 0; i &= i + 1, --i) {
            res += t[i];
        }
        return res;
    }
    int sum(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k, d;
    cin >> n >> k >> d;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    fenwick f(n + 1);
    f.modify(0, 1);
    for (int i = 0; i < n; ++i) {
        int l = lower_bound(a.begin(), a.end(), a[i] - d) - a.begin() - 1;
        int r = i - k;
        if (f.sum(l + 1, r + 1) > 0) {
            f.modify(i + 1, 1);
        }
    }
    if (f.sum(n, n) == 1) {
        cout << "YES\n";
        return 0;
    }
    else {
        cout << "NO\n";
        return 0;
    }
}