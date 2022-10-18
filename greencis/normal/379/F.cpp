#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;

constexpr int DEPTH = 19;
int up[1001001][DEPTH];
int h[1001001];
int n = 1;
int diam = 0, diam_a = 0, diam_b = 0;

inline int lca(int a, int b) {
    if (h[a] > h[b]) {
        for (int i = DEPTH; i--; )
            if (h[up[a][i]] >= h[b])
                a = up[a][i];
    } else if (h[a] < h[b]) {
        for (int i = DEPTH; i--; )
            if (h[up[b][i]] >= h[a])
                b = up[b][i];
    }
    if (a != b) {
        for (int i = DEPTH; i--; ) {
            if (up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }
        a = up[a][0];
    }
    return a;
}

inline int get_len(int a, int b) {
    int c = lca(a, b);
    return h[a] + h[b] - 2 * h[c];
}

void add(int parent) {
    int idx = n++;
    h[idx] = h[parent] + 1;
    up[idx][0] = parent;
    for (int i = 1; i < DEPTH; ++i)
        up[idx][i] = up[up[idx][i - 1]][i - 1];
    if (diam_a == parent) {
        ++diam;
        diam_a = idx;
    } else if (diam_b == parent) {
        ++diam;
        diam_b = idx;
    } else {
        int da = diam_a;
        int db = diam_b;
        int lena = get_len(da, idx);
        if (lena > diam) {
            diam = lena;
            diam_a = da;
            diam_b = idx;
        }
        int lenb = get_len(idx, db);
        if (lenb > diam) {
            diam = lenb;
            diam_a = idx;
            diam_b = db;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    add(0); add(0); add(0);
    int q;
    cin >> q;
    while (q--) {
        int v;
        cin >> v;
        add(v - 1); add(v - 1);
        cout << diam << '\n';
    }
}