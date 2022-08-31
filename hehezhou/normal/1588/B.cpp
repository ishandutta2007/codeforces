#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll query(int l, int r) {
    ll ans;
    printf("? %d %d\n", l, r);
    fflush(stdout);
    scanf("%lld", &ans);
    return ans;
}
int n, t;
inline void rmain() {
    scanf("%d", &n);
    ll all = query(1, n);
    int pos = n, l = 1, r = n;
    while (l <= r) {
        int mid = l + r >> 1;
        if (query(1, mid) == all) r = mid - 1, pos = mid;
        else l = mid + 1;
    }
    ll qwq = query(1, pos - 1);
    int delta = all - qwq;
    int pos2 = pos - delta;
    delta = query(1, pos2 - 1) - query(1, pos2 - 2);
    int pos3 = pos2 - 1 - delta;
    printf("! %d %d %d\n", pos3, pos2, pos);
    fflush(stdout);
}
int main() {
    scanf("%d", &t);
    while (t--) rmain();
}