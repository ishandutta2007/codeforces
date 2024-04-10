#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>
const int MAX = 3e5, N = MAX+1;
int a[N], b[N], ia[N], ib[N], rib[N];

void read(int a[], int idx[], int n) {
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    std::iota(idx, idx + n, 0);
    std::sort(idx, idx + n, [&](int x, int y){
        if (a[x] != a[y])
            return a[x] < a[y];
        return x < y;
    });
}

void maxi(int &a, int b) {
    if (a < b) a = b;
}

struct FenwickTree {
    std::vector<int> fen;
    FenwickTree(int n) {
        fen.assign(n, 0);
    }
    void set(int idx, int val) {
        while (idx >= 0) {
            maxi(fen[idx], val);
            idx &= idx + 1;
            --idx;
        }
    }
    int get(int idx, int val = 0) {
        while (idx < fen.size()) {
            maxi(val, fen[idx]);
            idx |= idx + 1;
        }
        return val;
    }
};

bool solve() {
    int n; scanf("%d", &n);
    read(a, ia, n);
    read(b, ib, n);
    for (int i = 0; i < n; ++i)
        rib[ib[i]] = i;
    FenwickTree f(n + 1);
    for (int i = 0; i < n; ++i) {
        int x = ia[rib[i]];
        if (b[i] != a[x])
            return false;
        if (f.get(b[i]) > x)
            return false;
        f.set(b[i], x);
    }
    return true;
}

int main() {
    int t; scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        printf("%s\n", solve() ? "YES" : "NO");
}