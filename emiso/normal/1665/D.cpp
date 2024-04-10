#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll t = 1, ans;

int main() {
    scanf("%lld", &t);
    st: ans = 0;

    for (ll i = 0, a = 1, b = 2; i < 30; i++, a *= 2, b *= 2) {
        printf("? %lld %lld\n", (a - ans), (a - ans) + b);
        fflush(stdout);

        ll g; scanf("%lld", &g);
        if (g % b == 0) ans |= a;
    }

    printf("! %lld\n", ans);
    fflush(stdout);

    if(--t) goto st;
    return 0;
}

/*
    ?1010101110110

????10000000000000
?10000000000000000 
*/