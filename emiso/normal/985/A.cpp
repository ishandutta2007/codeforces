#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], od, ev;

int main() {
    scanf("%lld", &n);

    for(int i = 1; i <= n/2; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n/2 + 1);

    for(int i = 1; i <= n; i += 2) {
        od += abs(a[(i+1)/2] - i);
    }

    for(int i = 2; i <= n; i += 2) {
        ev += abs(a[i/2] - i);
    }
    
    printf("%lld\n", min(od, ev));
    return 0;
}