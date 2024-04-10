#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m, l, r;

int main() {
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < m; i++) {
        scanf("%lld %lld", &l, &r);
    }

    for(int i = 0; i < n; i++) {
        printf("%d", i % 2);
    } printf("\n");

    return 0;
}