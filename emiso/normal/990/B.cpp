#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], K;

int main() {
    scanf("%lld %lld", &n, &K);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);

    int j = 0;
    ans = n;
    for(int i = 1; i < n; i++) {
        while(j < n && a[j] < a[i] && a[j] + K >= a[i]) {
            ans--;
            j++;
        }

        while(j < n && a[j] + K < a[i]) {
            j++;
        }
    }

    printf("%lld\n", ans);
    return 0;
}