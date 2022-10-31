#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m, ans, o1, e1, o2, e2, x;

int main() {
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &x);
        if(x % 2) o1++;
        else e1++;
    }

    for(int i = 0; i < m; i++) {
        scanf("%lld", &x);
        if(x % 2) o2++;
        else e2++;
    }

    printf("%lld\n", min(o1, e2) + min(o2, e1));
    return 0;
}