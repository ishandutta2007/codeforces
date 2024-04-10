#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long ll;

int n;
ll vet[2020][2020], x[2020], y[2020], S, nS;
pair<ll, ll> p[2020];

int main() {
    scanf("%d %lld", &n, &S);
    S *= 2;
    nS = -S;

    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &p[i].first, &p[i].second);
    } random_shuffle(p, p + n);

    for(int i = 0; i < n; i++) {
        x[i] = p[i].first;
        y[i] = p[i].second;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            vet[i][j] = x[i]*y[j] - y[i]*x[j];

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            for(int k = 0; k < j; ++k) {
                ll A = vet[i][j] - vet[i][k] + vet[j][k];
                if(S == A || nS == A) {
                    puts("Yes");
                    printf("%lld %lld\n", x[i], y[i]);
                    printf("%lld %lld\n", x[j], y[j]);
                    printf("%lld %lld\n", x[k], y[k]);
                    return 0;
                }
            }
        }
    }

    printf("No\n");
    return 0;
}