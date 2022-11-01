#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

unsigned hash_f(unsigned x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}
struct chash {
    int operator()(int x) const { return hash_f(x); }
};

int n, k, x;
gp_hash_table<int, int, chash> freq[11], forig[11];
long long ans;

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        int sz = 0, z = x;
        while(z) {
            sz++;
            z /= 10;
        }
        x %= k;
        if(x && freq[sz].find(k-x) != freq[sz].end()) ans += freq[sz][k-x];
        else if(!x) ans += freq[sz][0];

        int y = x;
        for(int j = 1; j < 11; j++) {
            y = (10LL * y) % k;
            freq[j][y]++;
            if(y && forig[j].find(k-y) != forig[j].end()) ans += forig[j][k-y];
            else if(!y) ans += forig[j][0];
        }

        forig[sz][x]++;
    }

    printf("%lld\n", ans);
    return 0;
}