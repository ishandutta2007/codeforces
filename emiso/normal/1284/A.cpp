#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m, q, x, ans;
char a[MN]; string s[MN], t[MN], res[MN];

int main() {
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%s", a); s[i] = a;
    }
    for(int i = 0; i < m; i++) {
        scanf("%s", a); t[i] = a;
    }

    ll quant = n * m / __gcd(n, m);
    for(int i = 0; i < quant; i++) {
        res[i] = s[i % n] + t[i % m];
    }

    scanf("%lld", &q);
    while(q--) {
        scanf("%lld", &x);
        x--;
        printf("%s\n", res[x % quant].c_str());
    }

    return 0;
}