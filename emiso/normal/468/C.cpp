#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a, l, r, x, d, p10 = 10;
string prefix;

int main() {
    scanf("%lld", &a);

    if (a < 45) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < a; j++)
                printf("1");
            printf(" ");
        }
        return 0;
    }

    l = 0, r = 9, x = 45, d = 1;
    while(1) {
        ll nx = 45LL * p10 * (d + 1);
        if(nx > a) break;

        x = nx;
        p10 *= 10LL;
        d++;
        r = 10LL * r + 9;
    }

    a -= x;
    ll pref = a / p10;

    while(pref) {
        ll tmp = min(pref, 9LL);
        prefix += char('0' + tmp);
        pref -= tmp;
    }
    assert(prefix.size() < 1980);

    l += a % p10;
    r += a % p10;

    ll len1 = 0, len2 = 0;
    if(l == 0) len1 = 1;
    for(ll tmp = l; tmp; tmp /= 10, len1++);
    for(ll tmp = r; tmp; tmp /= 10, len2++);
    string lpref(len2 - len1, '0');

    if(prefix.empty()) lpref = "";
    if(prefix.empty() && l == 0) l = 1;
    printf("%s%s%lld %s%lld\n", prefix.c_str(), lpref.c_str(), l, prefix.c_str(), r);
    return 0;
}