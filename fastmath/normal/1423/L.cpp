#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define debug(x) std::cout << #x << ": " << x << '\n';
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 10, K = 100 + 10, LG = 16;
const ll INF = 2e9 + 10;
std::mt19937_64 rnd(228);
ull kek[N];
int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, m, s;
    std::cin >> n >> s >> m;
    FOR(i, n) {
        kek[i] = rnd();
    }
    std::vector<ull> hashes;
    FOR(i, s) {
        int len;
        std::cin >> len;
        ull curH = 0;
        FOR(i, len) {
            int t;
            std::cin >> t;
            curH ^= kek[t - 1];
        }
        hashes.pb(curH);
    }
    int left = s / 2;
    int right = s - left;
    gp_hash_table<ull, int> h1, h2;
    FOR(mask, (1 << left)) {
        ull allH = 0;
        int bitCnt = 0;
        FOR(j, left) {
            if ((mask >> j) & 1) {
                allH ^= hashes[j];
                bitCnt++;
            }
        }
        if (h1.find(allH) == h1.end()) {
            h1[allH] = bitCnt;
        }
        else {
            h1[allH] = std::min(h1[allH], bitCnt);
        }
    }
    FOR(mask, (1 << right)) {
        ull allH = 0;
        int bitCnt = 0;
        FOR(j, right) {
            if ((mask >> j) & 1) {
                allH ^= hashes[j + left];
                bitCnt++;
            }
        }
        if (h2.find(allH) == h2.end()) {
            h2[allH] = bitCnt;
        }
        else {
            h2[allH] = std::min(h2[allH], bitCnt);
        }
    }
    FOR(i, m) {
        int len;
        std::cin >> len;
        ull needH = 0;
        FOR(i, len) {
            int t;
            std::cin >> t;
            needH ^= kek[t - 1];
        }
        int answ = INF;
        for (auto e: h1) {
            if (h2.find(e.first ^ needH) != h2.end()) {
                answ = std::min(answ, e.second + h2[e.first ^ needH]);
            }
        }
        if (answ == INF) answ = -1;
        std::cout << answ << '\n';
    }
}