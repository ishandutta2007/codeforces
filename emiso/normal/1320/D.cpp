#include <bits/stdc++.h>

using namespace std;

#define MN 300020

int n, q;
char s[MN]; string str;

struct info {
    pair<int, int> val;
    int len, l, r;

    info() {}

    info(pair<int, int> val, int len, int l, int r)
        : val(val), len(len), l(l), r(r) {}

    bool operator == (const info& o) const {
        return val == o.val && len == o.len && l == o.l && r == o.r;
    }
};

vector<info> L[MN], R[MN], a;

typedef long long ll;
ll mult[MN][2];
ll b1 = 311, M1 = 1000000021, b2 = 317, M2 = 1000000009, im1, im2;

ll expo(ll a, ll b, ll MOD) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1, MOD) % MOD;
    return expo(a * a, b >> 1, MOD);
}

ll inv_mod(ll a, ll MOD) {
    return expo(a, MOD - 2, MOD);
}

info identity({0, 0}, 0, -1, -1);

info reduce(info a, int l) {
    if(l == 1) {
       return info(a.val, a.len-1, 0, a.r);
    } else {
        pair<int, int> val = a.val;
        val.first  = 1LL * val.first  * im1 % M1;
        val.second = 1LL * val.second * im2 % M2;
        return info(val, a.len-1, a.l, 0);
    }
}

info merge(info a, info b) {
    if (a.len == 0) return b;
    if (b.len == 0) return a;

    if (a.len == 1 && b.len == 1 && a.r == 1 && b.l == 1) {
        return identity;
    }
    if (a.len == 1 && a.r == 1 && b.l == 1) {
        return info(b.val, b.len-1, 0, b.r);
    }
    if (b.len == 1 && a.r == 1 && b.l == 1) {
        return reduce(a, 0);
    }

    if(a.r == 1 && b.l == 1) {
        a = reduce(a, 0);
        b = reduce(b, 1);
    }

    pair<int, int> val = b.val;
    val.first  = (val.first  + 1LL * a.val.first  * mult[b.len][0] % M1) % M1;
    val.second = (val.second + 1LL * a.val.second * mult[b.len][1] % M2) % M2;
    return info(val, a.len + b.len, a.l, b.r);
}

void build(int l = 0, int r = 1<<20) {
    if(l + 1 >= r) return;
    int m = (l + r) / 2;

    build(l, m);
    if(m >= a.size()) return;
    build(m, r);

    info last = identity;
    for(ll i = m - 1; i >= l; i--) {
        last = merge(a[i], last);
        L[m].push_back(last);
    }

    last = identity;
    for(ll i = m; i < min(r, (int)a.size()); i++) {
        last = merge(last, a[i]);
        R[m].push_back(last);
    }
}

info query(int l, int r) {
    if(l == r) return a[l];
    int pow2 = 1 << (__builtin_clz(1) - __builtin_clz(l ^ r));
    int m = r & ~(pow2 - 1);
    return merge(L[m][m-l-1], R[m][r-m]);
}

int main() {
    scanf("%d %s %d", &n, &s, &q);
    str = s;

    im1 = inv_mod(b1, M1);
    im2 = inv_mod(b2, M2);

    a.resize(1 << 18, identity);
    for(int i = 0; i < n; i++) {
        a[i] = info({str[i] == '0', str[i] == '0'}, 1, str[i] - '0', str[i] - '0');
    }

    mult[0][0] = mult[0][1] = 1;
    for(ll i=1; i < MN; i++) {
        mult[i][0] = (mult[i-1][0] * b1)%M1;
        mult[i][1] = (mult[i-1][1] * b2)%M2;
    }

    build(0, 1 << 18);
    while(q--) {
        int l1, l2, len;
        scanf("%d %d %d", &l1, &l2, &len);
        l1--; l2--;

        auto h1 = query(l1, l1+len-1);
        auto h2 = query(l2, l2+len-1);
        puts((h1 == h2) ? "Yes" : "No");
    }
    return 0;
}