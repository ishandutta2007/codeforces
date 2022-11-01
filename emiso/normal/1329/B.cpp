#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, m, d;

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld", &d, &m);

        if(d == 1) {
            printf("%lld\n", 1 % m);
            continue;
        }

        ll jmp = 2, inc = 2, i = 1, val = 1;
        while(i + jmp < d) {
            val = (val + jmp * inc) % m;
            inc = inc * (jmp + 1) % m;
            i += jmp;
            jmp *= 2;
        }

        printf("%lld\n", (val + (d - i) * inc) % m);
    }
    return 0;
}