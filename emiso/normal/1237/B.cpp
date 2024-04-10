#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], b[MN], bit[MN], id[MN];

void upd(int idx, int delta) {
    for(; idx < MN; idx += (idx & -idx)) bit[idx] += delta;
}

int qry(int idx) {
    int ret = 0;
    for(; idx; idx -= (idx & -idx)) ret += bit[idx];
    return ret;
}

int main() {
    scanf("%lld", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        id[a[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
    }
    for(int i = n; i >= 1; i--) {
        if(qry(id[b[i]])) ans++;
        upd(id[b[i]], 1);
    }

    printf("%lld\n", ans);
    return 0;
}