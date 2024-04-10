#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1100000

int is_prime[MN], divs[MN], pot[MN];
vector<int> primos;

void crivo() {
    divs[1] = 1;
    for(int i = 2; i < MN; i++) is_prime[i] = 1;

    for(int i = 2; i < MN; i++) {
        if(is_prime[i]) {
            primos.push_back(i);
            divs[i] = 2;
            pot[i] = 1;
        }
        for(int j = 0; j < primos.size() && i * primos[j] < MN; j++) {
            is_prime[i * primos[j]] = 0;

            if(i % primos[j] == 0) {
                divs[i * primos[j]] = divs[i] + divs[i]/(pot[i]+1);
                pot[i * primos[j]] = pot[i] + 1;
                break;
            } else {
                divs[i * primos[j]] = divs[i] * 2;
                pot[i*  primos[j]] = 1;
            }
        }
    }
}

int n, m, t, l, r, arr[MN];
ll bit[MN];
set<int> valid;

void update(int idx, ll delta) {
    for(; idx < MN; idx += (idx & -idx)) bit[idx] += delta;
}

ll query(int idx) {
    ll ret = 0;
    for(; idx; idx -= (idx & -idx)) ret += bit[idx];
    return ret;
}

int main() {
    crivo();
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        update(i, arr[i]);
        if(arr[i] > 2) valid.insert(i);
    }

    while(m--) {
        scanf("%d %d %d", &t, &l, &r);

        if(t == 1) {
            auto L = valid.lower_bound(l);
            vector<int> rem;
            while(L != valid.end() && *L <= r) {
                update(*L, -arr[*L]);
                arr[*L] = divs[arr[*L]];
                update(*L, arr[*L]);

                if(arr[*L] == 2) rem.push_back(*L);
                ++L;
            }
            for(int x : rem) valid.erase(x);

        } else if(t == 2) {
            printf("%lld\n", query(r) - query(l-1));
        } else assert(false);
    }
    return 0;
}