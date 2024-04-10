#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn], f[maxn], c[maxn * 2];

void ins(int p, int v) {
    for (p += 200000; p < maxn * 2; p += p & -p) {
        if (c[p] < v) c[p] = v;
    }
}

void reset(int p) {
    for (p += 200000; p < maxn * 2; p += p & -p) {
        c[p] = -1e9;
    }
}

int query(int p) {
    int s = -1e9;
    for (p += 200000; p; p -= p & -p) s = max(s, c[p]);
    return s;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    memset(f, -0x3f, sizeof(f)), f[0] = 0;
    memset(c, -0x3f, sizeof(c));
    function<void(int, int)> solve = [&](int l, int r) {
        if (l == r) return;
        int mid = (l + r) >> 1;
        solve(l, mid);
        vector<int> id1, id2;
        for (int i = l; i <= r; i++) {
            if (i <= mid) id1.push_back(i);
            else id2.push_back(i);
        }
        sort(id1.begin(), id1.end(), [&](int x, int y) { return a[x] < a[y]; });
        sort(id2.begin(), id2.end(), [&](int x, int y) { return a[x] < a[y]; });
        for (int i = 0, j = 0; i < id2.size(); i++) {
            for (; j < id1.size() && a[id1[j]] < a[id2[i]]; j++) {
                ins(id1[j] - a[id1[j]], f[id1[j]] + 1);
            }
            f[id2[i]] = max(f[id2[i]], query(id2[i] - a[id2[i]]));
        }
        for (int x : id1) reset(x - a[x]);
        solve(mid + 1, r);
    };
    solve(0, n);
    printf("%d\n", *max_element(f, f + n + 1));
    return 0;
}