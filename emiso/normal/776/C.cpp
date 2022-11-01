#include <bits/stdc++.h>

#define MN 100100
#define w1 while(1)

using namespace std;
typedef long long ll;

int n;
vector<ll> pot;
ll a[MN], acum[MN], ans, k;
map <ll, ll> occ;

int main() {
    scanf("%d %lld", &n, &k);

    ll mult = 1;
    if(k == 1) pot.push_back(mult);
    else if(k == -1) {
        pot.push_back(1);
        pot.push_back(-1);
    }
    else {
        while(mult <= 100000000000000000LL) {
            pot.push_back(mult);
            mult *= k;
        }
    }

    occ[0] = 1;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        acum[i] = a[i];
        if(i) acum[i] += acum[i-1];

        for(int p = 0; p < pot.size(); p++) {
            ans += occ[acum[i] - pot[p]];
        }

        occ[acum[i]]++;
    }

    printf("%lld\n", ans);

    return 0;
}