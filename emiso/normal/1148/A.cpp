#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll a, b, c;

int main() {
    scanf("%lld %lld %lld", &a, &b, &c);

    if(a == b) printf("%lld\n", a * 2 + 2 * c);
    else printf("%lld\n", min(a, b) * 2 + 1 + 2 * c);
    return 0;
}