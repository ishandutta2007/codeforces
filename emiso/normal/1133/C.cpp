#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, ans, a[MN];

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);

    for(int i = 0; i < n; i++) {
        int j = upper_bound(a, a + n, a[i] + 5) - a;
        ans = max(ans, j - i);
    }

    printf("%d\n", ans);
    return 0;
}