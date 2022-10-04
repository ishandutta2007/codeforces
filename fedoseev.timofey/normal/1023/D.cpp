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

const int N = 2e5 + 7;
int t[4 * N];

void build(int l, int r, int v, vector <int> &a) {
    if (l == r) t[v] = a[l];
    else {
        int m = (l + r) >> 1;
        build(l, m, 2 * v + 1, a);
        build(m + 1, r, 2 * v + 2, a);
        t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    }
}

const int Inf = 1e9;

int get(int ql, int qr, int l, int r, int v) {
    if (qr < l || r < ql) return Inf;
    if (ql <= l && r <= qr) return t[v];
    int m = (l + r) >> 1;
    return min(get(ql, qr, l, m, 2 * v + 1), get(ql, qr, m + 1, r, 2 * v + 2));
}

int main() {
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cin.tie(0);
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <int> res = a;
    int id = -1, lg = -1;
    for (int i = 0; i < n; ++i) {
        if (res[i]) id = i;
        else {
            if (lg == -1) lg = i;
        }
    }
    if (id == -1) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << q << ' ';
        }
        return 0;
    }
    for (int i = id - 1; i >= 0; --i) {
        if (res[i] == 0) {
            res[i] = res[i + 1];
        }
    }
    for (int i = id + 1; i < n; ++i) {
        if (res[i] == 0) {
            res[i] = res[i - 1];
        }
    }
    bool fl = false;
    for (int i = 0; i < n; ++i) {
        if (res[i] == q) fl = true;
    }
    if (!fl) {
        if (lg == -1) {
            cout << "NO\n";
            return 0;
        }
        else {
            res[lg] = q;
        }
    }
    vector <int> l(q + 1, Inf), r(q + 1, -Inf);
    for (int i = 0; i < n; ++i) {
        l[res[i]] = min(l[res[i]], i);
        r[res[i]] = max(r[res[i]], i);
    }
    build(0, n - 1, 0, res);
    for (int i = 1; i <= q; ++i) {
        if (l[i] == Inf) continue;
        int mn = get(l[i], r[i], 0, n - 1, 0);
        if (mn < i) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
}