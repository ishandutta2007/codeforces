#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, p, q, r, mxj[maxn], mxk[maxn];
map<int, int> mp;
long long ans, cur;

int main() {
    scanf("%d %d %d %d", &n, &p, &q, &r);
    mp[1] = 0, mp[q + 1] = r;
    auto upd = [&](int i, int v) {
        i = q - i + 1;
        auto it = --mp.upper_bound(i);
        if (it->second >= v) return;
        cur += 1LL * (v - it->second) * (next(it)->first - i), mp[i] = v;
        while (1) {
            it = mp.upper_bound(i);
            if (it->second >= v) break;
            cur += 1LL * (v - it->second) * (next(it)->first - it->first);
            mp.erase(it);
        }
    };
    while (n--) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        mxj[a] = max(mxj[a], b), mxk[a] = max(mxk[a], c);
        upd(b, c);
    }
    for (int i = p; i; i--) {
        if (mxj[i]) upd(mxj[i], r);
        if (mxk[i]) upd(q, mxk[i]);
        ans += cur;
    }
    printf("%lld\n", 1LL * p * q * r - ans);
    return 0;
}