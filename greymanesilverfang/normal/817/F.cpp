#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX_N = 2e5;

int n, type[MAX_N], idx[MAX_N], rnk[MAX_N], d[MAX_N];
long long a[MAX_N + 1] = {1}, left[2 * MAX_N], mex[2 * MAX_N], inv_mex[2 * MAX_N];

bool comp_a(int x, int y) {return (a[x] < a[y]);}

void calc(int i) {
    if (d[i] == 0) {
        mex[i] = min(mex[i << 1], mex[i << 1 | 1]);
        inv_mex[i] = min(inv_mex[i << 1], inv_mex[i << 1 | 1]);
    }
}

void apply(const int& query_type, int i) {
    switch (query_type) {
        case 1: if (i < n) d[i] = 1; mex[i] = a[idx[n]]; inv_mex[i] = left[i]; break;
        case 2: if (i < n) d[i] = 2; mex[i] = left[i]; inv_mex[i] = a[idx[n]]; break;
        case 3: if (i < n) d[i] = 3 - d[i]; swap(mex[i], inv_mex[i]); break;
    }
    ///printf("i %d left %lld mex %lld inv_mex %lld\n", i, left[i], mex[i], inv_mex[i]);
}

void build_tree() {
    for (int i = n - 1; i >= 0; --i) left[i + n] = mex[i + n] = a[idx[i]], inv_mex[i + n] = a[idx[n]];
    for (int i = n - 1; i >= 0; --i) left[i] = left[i << 1], calc(i);
}

void up(int i) {
    while (i > 1) {
        i >>= 1; if (d[i] == 0) calc(i);
        ///printf("up i %d left %lld mex %lld inv_mex %lld\n", i, left[i], mex[i], inv_mex[i]);
    }
}

void down(int i) {
    for (int lvl = 17; lvl > 0; --lvl) {
        int tmp = i >> lvl;
        if (tmp && d[tmp]) {
            apply(d[tmp], tmp << 1);
            apply(d[tmp], tmp << 1 | 1);
            d[tmp] = 0;
        }
    }
}

void query(const int& query_type, int l, int r) {
    int l0 = l += n, r0 = r += n;
    down(l0); down(r0 - 1);
    for (; l < r; l >>= 1, r >>= 1) {
        ///printf("l %d r %d\n", l, r);
        if (l & 1) apply(query_type, l++);
        if (r & 1) apply(query_type, --r);
    }
    up(l0); up(r0 - 1);
}

int main() {
    scanf("%d", &n); n <<= 1;
    for (int i = 1; i <= n; ++i)
        scanf("%d%I64d%I64d", &type[idx[i] = i], &a[i], &a[i + 1]), ++a[idx[i] = ++i];
    sort(idx, idx + n + 1, comp_a);
    build_tree();
    for (int i = 0; i <= n; ++i)
        rnk[idx[i]] = i && a[idx[i]] == a[idx[i - 1]] ? rnk[idx[i - 1]] : i;
    for (int i = 1; i <= n; i += 2) {
        query(type[i], rnk[i], rnk[i + 1]);
        printf("%I64d\n", mex[1]);
    }
    return 0;
}