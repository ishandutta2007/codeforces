#include <bits/stdc++.h>
#define MN 1001001

using namespace std;
typedef long long ll;

ll n, a, last[MN];
ll tot;

int main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a);
        tot += (i - last[a]) * (n - i + 1);
        last[a] = i;
    }
    tot = tot * 2 - n;
    printf("%.9f\n", tot / (1.0 * n * n));
    return 0;
}