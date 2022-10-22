#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <random>
#include <time.h>

using namespace std;

int get(int l, int r) {
    if (l == r) return 1;
    int m = (l + r) / 2 - (r - l + 1) % 2;
    return get(l, m) + get(m + 1, r) + 1;
}

int ost = 0;

void solve(int l, int r, int tl, int tr) {
    if (l == r) {
        cout << tl + 1 << ' ';
        return;
    }

    if (ost == 0) {
        for (int i = tl; i <= tr; ++i) cout << i + 1 << ' ';
        return;
    }

    int m = (l + r) / 2 - (r - l + 1) % 2;
    ost -= 2;
    int len = m - l + 1;
    solve(l, m, tr - len + 1, tr);
    solve(m + 1, r, tl, tr - len);     
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if (get(0, n - 1) < k) {
        cout << "-1\n";
        return 0;
    }
    
    if (k % 2 == 0) {
        cout << "-1\n";
        return 0;
    }
    
    ost = k - 1;
    solve(0, n - 1, 0, n - 1);
    cout << '\n';

    return 0;
}