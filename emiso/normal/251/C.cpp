#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

inline int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

ll a, b, ans;
int k;

ll path(ll from, ll to) {
    queue<ll> fila;
    int used[from - to + 1];
    memset(used, -1, sizeof used);

    fila.push(from);
    used[from - to] = 0;

    cerr << from << " " << to << endl;
    while(!fila.empty()) {
        ll u = fila.front();
        fila.pop();

        if(u <= to) continue;

        if(used[u - 1 - to] == -1) {
            used[u - 1 - to] = used[u - to] + 1;
            fila.push(u - 1);
        }

        for(int i = 2; i <= k; i++) {
            int m = u % i;
            if(u - m >= to && used[u - m - to] == -1) {
                used[u - m - to] = used[u - to] + 1;
                fila.push(u - m);
            }
        }
    }

    return used[0];
}

int main() {
    scanf("%lld %lld %d", &a, &b, &k);
    int L = 2;
    for(int i = 3; i <= k; i++) {
        L = lcm(L, i);
    } cerr << L << endl;

    if(a - b < L) printf("%lld\n", path(a, b));
    else {
        ll na = a - (a % L);
        ll nb = --b + L - (b++ % L);
        ll times = (na - nb) / L;
        printf("%lld\n", path(2*L, L)*times + path(a, na) + path(nb, b));
    }
    return 0;
}