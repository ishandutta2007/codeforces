#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN];

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(i) {
            if(a[i] == 1 && a[i-1] == 2) ans += 3;
            else if(a[i] == 2 && a[i-1] == 1) {
                ans += 3;
                if(i > 1 && a[i-2] == 3) ans--;
            }
            else if(a[i] == 1 && a[i-1] == 3) ans += 4;
            else if(a[i] == 3 && a[i-1] == 1) ans += 4;
            else {
                puts("Infinite");
                return 0;
            }
        }
    }

    printf("Finite\n%lld\n", ans);
    return 0;
}