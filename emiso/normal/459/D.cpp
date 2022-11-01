#include <bits/stdc++.h>
#define MN 1000100

using namespace std;

int bit[MN];
map<int, int> l, r;

void update(int idx, int delta) {
    for(; idx < MN; idx += (idx & -idx)) bit[idx] += delta;
}

int query(int idx) {
    int res = 0;
    for(; idx; idx -= (idx & -idx)) res += bit[idx];
    return res;
}

int n, a[MN];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    l[a[0]]++;
    for(int i = n-1; i > 0; i--) {
        r[a[i]]++;
    }

    long long ans = 0;
    for(int i = 1; i < n; i++) {
        ans += (i - 1 - query(r[a[i]]));

        l[a[i]]++;
        update(l[a[i]], 1);
        r[a[i]]--;
    }

    printf("%lld\n", ans);
    return 0;
}