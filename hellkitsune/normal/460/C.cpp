#include <cmath>
#include <iostream>

using namespace std;

int t[1 << 18];
const int off = 1 << 17;

void treeAdd(int v, int L, int R, int l, int r, int val) {
    if (l == L && r == R) {
        t[v] += val;
        return;
    }
    int mid = (L + R) >> 1;
    if (l <= mid) treeAdd(v << 1, L, mid, l, min(r, mid), val);
    if (r > mid) treeAdd((v << 1) | 1, mid + 1, R, max(l, mid + 1), r, val);
}

int treeQuery(int at) {
    int ret = 0;
    for (int v = off + at; v >= 1; v >>= 1)
        ret += t[v];
    return ret;
}

int n, m, w;
int a[100000];

long long solve(int x) {
    for (int i = 1; i < off * 2; ++i) t[i] = 0;
    for (int i = 0; i < n; ++i) t[off + i] = a[i];
    long long ans = 0;
    for (int i = 0; i < n; ++i) if (treeQuery(i) < x) {
        int days = x - treeQuery(i);
        treeAdd(1, 0, off - 1, i, min(n - 1, i + w - 1), days);
        ans += days;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> w;
    int i = 0;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int l = 0, r = 1e9 + 1e7, mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (solve(mid) <= m)
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}