#include <bits/stdc++.h>

#define MN 201000

using namespace std;
typedef long long ll;

ll t, a[MN], bit[MN], c, ans, cn;
int n;

void upd(int idx, ll delta) {
    for(; idx < MN; idx += (idx & -idx)) bit[idx] += delta;
}

ll query(int idx) {
    ll ret = 0;
    for(; idx; idx -= (idx & -idx)) ret += bit[idx];
    return ret;
}

/* Last index pos where query(pos) <= k
 * prefix(4) => 1 2 3 4 4 {4} 5 6
 * prefix(4) => 0 1 1 2 2 {2} 5 6
 * usage: prefix(k, bit, MAXN)
 * 0 <= pos < N
 * */
int prefix(ll k) {
    int pos = 0, pot = 0;
    while((1 << (pot+1)) <= MN) pot++;
    while(pot >= 0) {
        int size = (1 << pot);
        if(pos + size < MN && bit[pos + size] <= k) {
            k -= bit[pos + size];
            pos += size;
        }
        pot--;
    }
    return pos;
}

int main() {
    scanf("%d %lld", &n, &t);

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        upd(i, a[i]);
    }

    cn = n;
    while(cn > 0) {
        c = query(n);
        ans += (t / c) * cn;
        t %= c;

        int lst = prefix(t);
        while(lst < n) {
            upd(lst + 1, -a[lst + 1]);
            cn--;

            lst = prefix(t);
        }
    }

    printf("%lld\n", ans);
    return 0;
}