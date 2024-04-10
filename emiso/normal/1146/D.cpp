#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll m, a, b, g, t, ans, notyet[MN], ok[MN], quant;

int main() {
    scanf("%lld %lld %lld", &m, &a, &b);
    g = __gcd(a, b);

    queue<ll> fila;
    notyet[0] = 1;
    for(t = 0; t < min(m + 1, a + b); t++) { /// <= ???
        if(notyet[t]) {
            fila.push(t);
        }
        while(!fila.empty()) {
            ll u = fila.front(); fila.pop();
            quant++;
            ok[u] = 1;
            if(u + a > t) notyet[u + a] = 1;
            if(u >= b && !ok[u - b]) fila.push(u - b);
            if(u + a <= t && !ok[u + a]) fila.push(u + a);
        }
        ans += quant;
    }

    ans += quant * (m - t + 1);
    ans += (g + (m-t+g)/g*g) * ((m-t+g)/g) / 2;

    for(ll y = m + 1; y % g != 0; y++) {
        ans -= (m-t+g)/g;
    }

    printf("%lld\n", ans);
    return 0;
}