#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

/*inline uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}*/

struct Bitset {
    uint64_t bs[16];

    Bitset() {
        memset(bs, 0, sizeof bs);
    }

    void set(int idx) {
        bs[idx / 64] |= (1ull << (idx % 64));
    }

    Bitset& operator^=(const Bitset& rhs) {
        for (int i = 0; i < 16; ++i) {
            bs[i] ^= rhs.bs[i];
        }
        return *this;
    }

    ull hash() const {
        ull ans = 0x712673081AAAAAFFull;
        for (int i = 0; i < 16; ++i) {
            ans ^= bs[i] + 0x9e3779b99e3779b9ull + (ans << 6) + (ans >> 2);
        }
        return ans;
    }
} b[30], calc[2][1 << 15];

int popcnt[1 << 15];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < (1 << 15); ++i)
        popcnt[i] = __builtin_popcount(i);

    int n, s, d;
    cin >> n >> s >> d;
    for (int i = 0; i < s; ++i) {
        Bitset cur;
        int cnt, x;
        cin >> cnt;
        for (int i = 0; i < cnt; ++i) {
            cin >> x;
            --x;
            cur.set(x);
        }
        b[i] = cur;
    }

    for (int z = 0; z < 2; ++z) {
        for (int mask = (1 << 15); mask--; ) {
            Bitset cur;
            int popcnt = 0;
            for (int i = 0; i < 15; ++i) {
                if ((mask >> i) & 1) {
                    ++popcnt;
                    cur ^= b[z * 15 + i];
                }
            }
            calc[z][mask] = cur;
        }
    }

    unordered_map<ull, int> mp;
    for (int mask = (1 << 15); mask--; ) {
        int& rf = mp[calc[1][mask].hash()];
        if (rf == 0) rf = 1e9;
        rf = min(rf, popcnt[mask]);
    }

    while (d--) {
        Bitset cur;
        int cnt, x;
        cin >> cnt;
        for (int i = 0; i < cnt; ++i) {
            cin >> x;
            --x;
            cur.set(x);
        }

        int ans = 1e9;
        for (int i = 0; i < (1 << 15); ++i) {
            if (popcnt[i] >= ans) {
                continue;
            }
            Bitset tst = cur;
            tst ^= calc[0][i];
            ull hsh = tst.hash();
            auto it = mp.find(hsh);
            if (it != mp.end()) {
                ans = min(ans, popcnt[i] + it->second);
            }
        }
        if (ans == (int)1e9) ans = -1;
        cout << ans << '\n';
    }
}