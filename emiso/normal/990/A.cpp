#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m, a, b, cd, cu, r;

int main() {
    scanf("%lld %lld %lld %lld", &n, &m, &a, &b);

    r = n % m;
    cd = r * b;
    cu = (m - r) * a;

    printf("%lld\n", min(cd, cu));
    return 0;
}