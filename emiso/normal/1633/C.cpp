#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, ans, hc, dc, hm, dm, k, w, a;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    
    scanf("%lld %lld %lld %lld %lld %lld %lld", &hc, &dc, &hm, &dm, &k, &w, &a);
    for (ll ia = 0; ia <= k; ia++) {
        ll atk = dc + ia * w;
        ll health = hc + (k-ia) * a;

        ans |= ((hm + atk - 1) / atk <= (health + dm - 1) / dm);
    }
    puts(ans ? "YES" : "NO");

    if(--t) goto st;
    return 0;
}