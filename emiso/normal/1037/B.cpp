#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], s;

int main() {
    scanf("%lld %lld", &n, &s);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);

    int m = n / 2, rite = a[m] < s;
    while(m >= 0 && m < n) {
        if(a[m] == s || (a[m] < s) != rite) break;
        ans += abs(s - a[m]);
        if(rite) m++;
        else m--;
    }

    printf("%lld\n", ans);
    return 0;
}