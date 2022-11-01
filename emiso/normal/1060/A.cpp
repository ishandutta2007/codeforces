#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], f8;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%1lld", &a[i]);
        if(a[i] == 8) f8++;
    }

    ans = n / 11;
    ans = min(ans, f8);

    printf("%lld\n", ans);
    return 0;
}