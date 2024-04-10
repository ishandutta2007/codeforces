#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn], id[maxn], ans[maxn], L[maxn], R[maxn];
bool mark[maxn];

int findL(int x) {
    return x == L[x] ? x : L[x] = findL(L[x]);
}

int findR(int x) {
    return x == R[x] ? x : R[x] = findR(R[x]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        id[i] = i, L[i] = R[i] = i;
    }
    sort(id + 1, id + n + 1, [&](int x, int y) { return a[x] > a[y]; });
    for (int $ = 1; $ <= n; $++) {
        int i = id[$];
        if (i > 1 && mark[i - 1]) L[i] = i - 1, R[i - 1] = i;
        if (i < n && mark[i + 1]) R[i] = i + 1, L[i + 1] = i;
        L[i] = findL(i), R[i] = findR(i);
        ans[R[i] - L[i] + 1] = max(ans[R[i] - L[i] + 1], a[i]);
        mark[i] = 1;
    }
    for (int i = n; i; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}