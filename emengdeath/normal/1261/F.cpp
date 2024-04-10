#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 101;
const int BITS = 60;
struct node{
    int son[2];
    bool all;
    bool have;
}f[N * 200 * 4];
int na, nb;
int tot;
vector<pair<int, int> > d[BITS + 1];
void ins(long long l, int bits, int s, long long ll, long long rr) {
    if (l + (1ll << bits) - 1 < ll || rr < l) return;
    if (f[s].all) return;
    if (l >= ll && l + (1ll << bits) - 1 <= rr) {
        f[s].all = 1;
        f[s].have = 1;
        return;
    }
    f[s].have = 1;
    if (!f[s].son[0])
        f[s].son[0] = ++ tot;
    if (!f[s].son[1])
        f[s].son[1] = ++ tot;
    ins(l, bits - 1, f[s].son[0], ll, rr);
    ins(l + (1ll << (bits - 1)), bits - 1, f[s].son[1], ll, rr);
    f[s].all = (f[f[s].son[0]].all && f[f[s].son[1]].all);
}
const int mod = 998244353;
int add(int x, int y) {
    x+= y;
    return x >= mod ?x - mod : x;
}
int sub(int x, int y) {
    x -= y;
    return x < 0 ? x +mod : x;
}
int mul(int x, int y){
    return 1ll * x * y % mod;
}
int calc(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x), y >>= 1;
    }
    return z;
}
int ni2 = calc(2, mod - 2);
int calc(long long x) {
    return mul(mul((x - 1) % mod, x % mod), ni2);
}
int work(int prefix, int bits) {
    if (!d[bits].size()) return 0;
    for (auto u:d[bits]) {
        if (f[u.first].all || f[u.second].all) {
            return add(mul(prefix, (1ll << bits) % mod), calc(1ll << bits));
        }
    }
    int v = 0;
    for (int x = 0; x < 2; x ++) {
        d[bits - 1].clear();
        for (int i = 0; i < 2; i++)
            for (auto u:d[bits])
                if (f[f[u.first].son[i]].have && f[f[u.second].son[i ^ x]].have)
                    d[bits - 1].push_back({f[u.first].son[i], f[u.second].son[i ^ x]});
        v = add(work(add(prefix, (((long long) x) << (bits - 1)) % mod), bits - 1), v);
    }
    return v;
}
int main() {
    tot = 3;
    scanf("%d", &na);
    while (na --) {
        long long l, r;
        scanf("%lld %lld", &l, &r);
        ins(0, BITS, 1, l, r);
    }
    scanf("%d", &nb);
    while (nb --) {
        long long l, r;
        scanf("%lld %lld", &l, &r);
        ins(0, BITS, 2, l, r);
    }
    d[BITS].push_back({1, 2});
    printf("%d\n", work(0, BITS));
    return 0;
}