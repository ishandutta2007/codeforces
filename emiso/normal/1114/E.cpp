#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MN 1001000

ll n;
typedef unsigned long long ull;

ull seed = 0;
ull nxt() {
    seed ^= ull(102938711);
    seed *= ull(109293);
    seed ^= seed >> 13;
    seed += ull(1357900102873);
    return seed;
}

int main() {
    scanf("%lld", &n);

    ll l = 1, r = 1000000000, mid;
    while (l < r) {
        mid = (l + r) / 2;
        
        printf("> %lld\n", mid);
        fflush(stdout);
        int res;
        scanf("%d", &res);

        if (res) l = mid + 1;
        else r = mid;
    }

    set<int> val({l});
    for (int i = 0; i < 25; i++) {
        printf("? %llu\n", nxt() % n + 1);
        fflush(stdout);
        int res;
        scanf("%d", &res);
        val.insert(res);
    }

    int d = 0;
    for (auto tt = val.begin(); next(tt) != val.end(); tt = next(tt)) {
        d = __gcd(d, *next(tt) - *tt);
    }

    printf("! %lld %d\n", l - d*(n-1), d);
    fflush(stdout);
    return 0;
}