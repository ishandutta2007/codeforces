#include <bits/stdc++.h>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define MOD 1000000000000000177LL

using namespace std;
typedef long long ll;

int n, q, l, r, x;
ll can[10101], resp[10101];
vector<ll> ac[10101], vec;

ll mod(ll a, ll b) {
    ll ret = a + b;
    if(ret >= MOD) return ret - MOD;
    if(ret < 0)    return ret + MOD;
    return ret;
}

int main() {
    scanf("%d %d", &n, &q);
    for(int i = 0; i < q; i++) {
        scanf("%d %d %d", &l, &r, &x);
        ac[l].push_back(x);
        ac[r+1].push_back(-x);
    }

    can[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(ll x : ac[i]) {
            if(x > 0)
                for(int j = n; j >= x; j--)
                    can[j] = mod(can[j], can[j-x]);
            else
                for(int j = -x; j <= n; j++)
                    can[j] = mod(can[j], MOD-can[j+x]);

        }
        for(int j = 1; j <= n; j++) {
            if(can[j]) resp[j] = 1;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(resp[i] == 1) vec.push_back(i);
    }

    printf("%d\n", vec.size());
    for(ll x : vec) {
        printf("%lld ", x);
    }

    return 0;
}