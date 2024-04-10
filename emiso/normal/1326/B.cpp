#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], maxi;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        ans = a[i] + maxi;

        if(i == 0) maxi = a[i];
        else maxi = max(maxi, ans);

        printf("%lld ", ans);
    }
    return 0;
}