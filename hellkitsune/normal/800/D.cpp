#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

int n;
int a[1000000];
int have[1000000];
int dig[6];
int delta[64], odd[64];
int cnt[1000005], sum[1000005], sum2[1000005];
int p2[2000005], ip2[2000005];

const int T = 1000004;

void add(int a, int b, int res) {
    sum2[res] = ((ULL)sum2[a] * p2[cnt[b]] + (ULL)sum2[b] * p2[cnt[a]] + ULL(2) * sum[a] * sum[b]) % MOD;
    sum[res] = ((ULL)sum[a] * p2[cnt[b]] + (ULL)sum[b] * p2[cnt[a]]) % MOD;
    cnt[res] = cnt[a] + cnt[b];
}

void sub(int a, int b, int res) {
    cnt[res] = cnt[a] - cnt[b];
    sum[res] = (sum[a] - (LL)sum[b] * p2[cnt[res]]) % MOD * ip2[cnt[b]] % MOD;
    if (sum[res] < 0) sum[res] += MOD;
    sum2[res] = (sum2[a] - 2ll * sum[res] * sum[b] - (LL)sum2[b] * p2[cnt[res]]) % MOD * ip2[cnt[b]] % MOD;
    if (sum2[res] < 0) sum2[res] += MOD;
}

const int INV2 = (MOD + 1) / 2;
int sz1, sz2;
int ad[66], su[66];

int main() {
    ios_base::sync_with_stdio(false);
    p2[0] = ip2[0] = 1;
    forn(i, 2000004) {
        p2[i + 1] = p2[i] << 1;
        if (p2[i + 1] >= MOD) {
            p2[i + 1] -= MOD;
        }
        ip2[i + 1] = (LL)ip2[i] * INV2 % MOD;

    }
    if (0) {
        mt19937 mt(123);
        n = 1000000;
        forn(i, n) a[i] = mt() % 1000000;
    } else {
        cin >> n;
        forn(i, n) cin >> a[i];
    }
    dig[0] = 1;
    for (int i = 1; i < 6; ++i) {
        dig[i] = dig[i - 1] * 10;
    }
    forn(i, 1000000) {
        have[i] = 0;
        int rem = i;
        forn(j, 6) {
            int cur = rem % 10;
            rem /= 10;
            if (cur < 9) {
                have[i] |= 1 << j;
            }
        }
    }
    forn(mask, 64) {
        delta[mask] = 0;
        forn(i, 6) if (mask & (1 << i)) {
            delta[mask] += dig[i];
        }
    }
    forn(i, n) if (cnt[a[i]] != 0) {
        cnt[T] = 1;
        sum[T] = a[i];
        sum2[T] = (LL)a[i] * a[i] % MOD;
        add(a[i], T, a[i]);
    } else {
        cnt[a[i]] = 1;
        sum[a[i]] = a[i];
        sum2[a[i]] = (LL)a[i] * a[i] % MOD;
    }
    forn(i, 64) {
        odd[i] = __builtin_popcount(i) & 1;
    }
    for (int i = 999999; i > 0; --i) {
        sz1 = 0;
        sz2 = 0;
        for (int mask = have[i]; mask > 0; mask = ((mask - 1) & have[i])) {
            if (odd[mask]) {
                ad[sz1++] = i + delta[mask];
            } else {
                su[sz2++] = i + delta[mask];
            }
        }
        int i1 = 0, i2 = 0;
        while (i1 < sz1 || i2 < sz2) {
            if (i2 < sz2 && cnt[i] >= cnt[su[i2]]) {
                sub(i, su[i2], i);
                ++i2;
            } else {
                add(i, ad[i1], i);
                ++i1;
            }
        }
    }
    for (int i = 1; i < 1000000; ++i) {
        for (int mask = have[i]; mask > 0; mask = ((mask - 1) & have[i])) {
            if (odd[mask]) {
                sum2[i] -= sum2[i + delta[mask]];
                if (sum2[i] < 0) {
                    sum2[i] += MOD;
                }
            } else {
                sum2[i] += sum2[i + delta[mask]];
                if (sum2[i] >= MOD) {
                    sum2[i] -= MOD;
                }
            }
        }
    }
    LL ans = 0;
    for (int i = 1; i <= 999999; ++i) {
        ans ^= (LL)sum2[i] * i;
    }
    cout << ans << endl;
    return 0;
}